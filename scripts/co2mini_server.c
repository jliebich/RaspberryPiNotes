#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

#define MAX_EVENTS 64
#define MAX_CLIENTS 32

#define HIDIOCSFEATURE_9 0xC0094806

static uint8_t key[8] = {0x86,0x41,0xc9,0xa8,0x7f,0x41,0x3c,0xac};

int verbose = 0;

int set_nonblock(int fd)
{
    int flags = fcntl(fd, F_GETFL,0);
    if(flags < 0) return -1;
    return fcntl(fd,F_SETFL,flags | O_NONBLOCK);
}

void co2mini_decrypt(uint8_t *key, uint8_t *data, uint8_t *result)
{
    uint8_t offset[8] = {0x84,0x47,0x56,0xD6,0x07,0x93,0x93,0x56};
    int shuffle[8] = {2,4,0,7,1,6,5,3};

    uint8_t phase1[8];
    uint8_t phase2[8];
    uint8_t phase3[8];

    for(int i=0;i<8;i++)
        phase1[i] = data[shuffle[i]];

    for(int i=0;i<8;i++)
        phase2[i] = phase1[i] ^ key[i];

    for(int i=0;i<8;i++)
        phase3[i] = ((phase2[i] >> 3) | (phase2[(i+7)%8] << 5)) & 0xff;

    for(int i=0;i<8;i++)
        result[i] = (0x100 + phase3[i] - offset[i]) & 0xff;
}

int create_server(int port)
{
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0) {
        perror("socket");
        return -1;
    }

    int opt=1;
    if(setsockopt(s,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt)) < 0) {
        perror("setsockopt");
        close(s);
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(s,(struct sockaddr*)&addr,sizeof(addr))<0) {
        perror("bind");
        close(s);
        return -1;
    }

    if(listen(s,10)<0) {
        perror("listen");
        close(s);
        return -1;
    }

    if(set_nonblock(s)<0) {
        perror("fcntl");
        close(s);
        return -1;
    }

    return s;
}

int open_device(const char *path)
{
    int fd = open(path,O_RDWR | O_NONBLOCK);

    if(fd < 0)
        return -1;

    uint8_t feature[9];
    feature[0] = 0;
    memcpy(feature+1,key,8);

    if(ioctl(fd,HIDIOCSFEATURE_9,feature)<0)
    {
        close(fd);
        return -1;
    }

    return fd;
}

void broadcast(int *clients,int n,char *msg,int len)
{
    for(int i=0;i<n;i++)
    {
        if(clients[i] >=0)
        {
            if(send(clients[i],msg,len,MSG_NOSIGNAL)<=0)
            {
                close(clients[i]);
                clients[i] = -1;
            }
        }
    }
}

int main(int argc,char *argv[])
{
    signal(SIGPIPE,SIG_IGN);

    int opt;

    while((opt=getopt(argc,argv,"v"))!=-1)
    {
        if(opt=='v')
            verbose = 1;
    }

    const char *default_device = "/dev/co2mini0";
    int default_port = 20000;

    const char *device;
    int port;

    if(argc - optind == 0)
    {
        device = default_device;
        port = default_port;
    }
    else if(argc - optind == 1)
    {
        device = argv[optind];
        port = default_port;
    }
    else
    {
        device = argv[optind];
        port = atoi(argv[optind+1]);
    }

    int server = create_server(port);
    if(server < 0) 
    {
        fprintf(stderr,"Error: Server could not be created\n");
        exit(1);
    }
    else
    {
        printf("Server started on port %d\n",port);    
    }

    int ep = epoll_create1(0);

    struct epoll_event ev,events[MAX_EVENTS];

    ev.events = EPOLLIN;
    ev.data.fd = server;
    epoll_ctl(ep,EPOLL_CTL_ADD,server,&ev);

    int devicefd = -1;

    int clients[MAX_CLIENTS];
    for(int i=0;i<MAX_CLIENTS;i++)
        clients[i] = -1;


    while(1)
    {
        if(devicefd <0)
        {
            devicefd = open_device(device);

            if(devicefd >=0)
            {
                printf("Device %s connected\n",device);
                fflush(stdout);    
                
                set_nonblock(devicefd);

                ev.events = EPOLLIN;
                ev.data.fd = devicefd;
                epoll_ctl(ep,EPOLL_CTL_ADD,devicefd,&ev);
            }
            else
            {
                printf("Waiting for device %s...\n",device);
                fflush(stdout);
                sleep(1);
                continue;
            }
        }

        int n = epoll_wait(ep,events,MAX_EVENTS,2000);

        if(verbose)
        {
            printf("%d events on device %s...\n",n,device);
            fflush(stdout);
        }

        for(int i=0;i<n;i++)
        {
            int fd = events[i].data.fd;

            if(fd == server)
            {
                struct sockaddr_in client_addr;
                socklen_t addrlen = sizeof(client_addr);

                int c = accept(server, (struct sockaddr*)&client_addr, &addrlen);
                if(c >= 0)
                {
                    int j;
                    set_nonblock(c);                   

                    for(j=0;j<MAX_CLIENTS;j++)
                    {
                        if(clients[j] <0)
                        {
                            clients[j] = c;

                            char ip[INET_ADDRSTRLEN];
                            inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));
                            printf("New client %s:%d connected as client no. %d\n", ip, ntohs(client_addr.sin_port), j);
                            ev.events = EPOLLIN;
                            ev.data.fd = c;
                            epoll_ctl(ep,EPOLL_CTL_ADD,c,&ev);
                            break;
                        }
                    }
                    if(j==MAX_CLIENTS)
                    {
                        printf("Too many clients, rejecting connection\n");
                        close(c);
                    }                    
                }
                else
                {
                    printf("Unknown event from Server: %d",c);
                }
                fflush(stdout);   
            }

            else if(fd == devicefd)
            {
                uint8_t buf[8];
                int r = read(devicefd,buf,8);

                if(r == 8)
                {
                    uint8_t data[8];
                    co2mini_decrypt(key,buf,data);

                    if(data[4]==0x0d &&
                       (((data[0]+data[1]+data[2])&0xff)==data[3]))
                    {
                        // Gültige Nachricht
                        
                        char msg[5];
                        memcpy(msg,data,5);

                        if(data[0]==0x50)
                        {
                            broadcast(clients,MAX_CLIENTS,msg,5);
                            if (verbose)
                            {
                                int value = (data[1]<<8) | data[2];
                                printf("CO2: %d ppm\n",value);
                                fflush(stdout);
                            }
                        }
                        else if(data[0]==0x42)
                        {
                            broadcast(clients,MAX_CLIENTS,msg,5);
                            if (verbose)
                            {
                                int value = (data[1]<<8) | data[2];
                                float temp = value/16.0 - 273.15;
                                printf("Temp: %.2f C\n",temp);
                                fflush(stdout);
                            }
                        }
                        else
                        {
                            if (verbose)
                            {
                                int value = (data[1]<<8) | data[2];
                                printf("Datatype: %d Value: %d\n",data[0],value);
                                fflush(stdout);
                            }
                        }                        
                    }
                    else
                    {
                        if(verbose)
                        {
                            printf("Invalid data: ");
                            for(int j=0;j<8;j++)
                                printf("%02x ",data[j]);
                            printf("\n");
                            fflush(stdout);
                        }
                    }
                }
                else if(r <=0)
                {
                    epoll_ctl(ep,EPOLL_CTL_DEL,devicefd,NULL);
                    close(devicefd);
                    devicefd = -1;
                    printf("Device %s disconnected\n",device);
                    fflush(stdout);
                }
                else
                {
                    if (verbose)
                    {
                        printf("Wrong read from device: %d bytes\n",r);
                        fflush(stdout);
                    }
                }
            }

            else
            {
                char tmp[32];

                int r = recv(fd,tmp,sizeof(tmp),0);

                if(r <=0)
                {
                    epoll_ctl(ep,EPOLL_CTL_DEL,fd,NULL);

                    for(int j=0;j<MAX_CLIENTS;j++)
                    {
                        if(clients[j]==fd)
                        {
                            clients[j]=-1;
                            printf("Client no. %d disconnected\n",j);
                            fflush(stdout);
                        }
                    }
                    close(fd);
                }
                else
                {
                    if (verbose)
                    {
                        printf("Received data from client %d: %.*s\n",fd,r,tmp);
                        fflush(stdout);
                    }
                }
            }
        }
    }

    return 0;
}