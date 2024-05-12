# Samba Server

Siehe auch
Einrichten der Samba SMB Freigabe des consume Ordners
https://www.youtube.com/watch?v=69zhCTa7Zc4

## Install samba:
    sudo apt-get install samba -y

## Confirm service is running:
    sudo systemctl restart smbd.service

## Add user:
    sudo adduser pi

## Add the user to samba:
    sudo smbpasswd -a pi

## Set permissions:
    sudo apt-get install acl
    sudo setfacl -R -m "u:pi:rwx" /path/to/paperless/consumption/directory

Der Pfad zum Consume-Ordenr von paperless-ngx is bei mir 
    /portainer/Files/AppData/Config/paperless-ngx/consume

## Samba.conf to add share folder to:
    mcedit /etc/samba/smb.conf

und dann folgendes unten anhängen

    [paperless]
        comment = paperless consumption
        path = /portainer/Files/AppData/Config/paperless-ngx/consume
        read only = no
        writable = yes
        browseable = yes
        guest ok = no
        valid users = @pi

## Zugriff in Windows 
Der Pfad in Windows zu dem Ordner lautet

    \\192.168.0.37\paperless

Dieser Ordner wird leider nicht automatisch in der Netzwerk-Ansicht in Windows angezeigt
Hintergrund:
Windows Shares wurden ursprünglich mittels NetBIOS im Netzwerk bekannt gemacht. Auch wenn das eigentlich nichts mit SMB zu tun hat, weil es ein gänzlich anderes Protokoll ist, baut es in Windows auf den SMB-Services auf.
Das heißt, dass man zwingend SMBv1 aktivieren muss, um die mittels NetBIOS publizierten Shares von Samba anzuzeigen. SMBv1 ist aber unsicher, deshalb ist es keine gute Idee das in Windows zu aktivieren.
Ohne SMBv1 bzw. NetBIOS nutzt Windows andere Protokolle dafür, zB WS-Discovery.
Leider unterstützt Samba kein WSD und somit "sieht" Windows die Shares von Samba nicht.
Anbinden kann Windows die Shares aber problemlos.
Als Workaround gibt es wsdd (https://github.com/christgau/wsdd) , einen Daemon, der WSD implementiert und die Samba Shares im Netzwerk bekannt macht - auch für Windows ohne SMBv1.

Einen längeren Artikel mit mehr Details dazu findet man hier:
https://www.truenas.com/community/resources/how-to-kill-off-smb1-netbios-wins-and-still-have-windows-network-neighbourhood-better-than-ever.106/

