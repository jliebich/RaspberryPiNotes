# NetBeans als IDE für C Entwicklung auf dem Raspberry (besser Visual Studio Code nehmen, siehe unten)

## Creating A New NetBeans Project
Menu > File > New Project > Select 'C/C++ Application'

Set the projects name and location

Select C or C++ from the drop down 

Leave the default options for 'Build host' and 'Tool collection'.

Click 'Finish'

Select the 'Services' tab in the left window.

Ensure the Raspberry Pi is powered up and connected to the network.

Right click 'C/C++ Build Hosts' > Add New Host

Enter the IP address of the Raspberry Pi

*Press Next*

Jetzt SSH-Schlüssel wählen und den Pfad zur PPK Datei angeben 

*Press next*

NetBeans will attempt to connect

*Press Finish*

Select the 'Projects' tab in the left window.

Right click the projects name > Properties

Build > Build Host > Select the build host name you just created.

Run > Console Type > Standard Output

Apply and Close

If you are using the bcm2835 library for the IO pins etc, ensure you've installed it by following the guide here, add the bcm2835.h file to your project and do this:

Right click the project > Properties > Build > Linker > In the 'Libraries' section press the '…' button > Add Option… > Other Option > Enter: -lbcm2835

Right click the project > Build

## Delete all breakpoints
Menu > Window > Debugging > Breakpoints

Then right-click in the Breakpoints window and select Disable All or  "Delete All".


# Visual Studio Code auf Windows als Remote-IDE für C Entwicklung auf dem Raspberry nutzen

NICHT diese Anleitung nehemen, die ist veraltet:
    
    https://www.i-programmer.info/programming/hardware/14044-raspberry-pi-iot-in-c-vs-code-remote-c.html
    
Sondern mittels dieser Extension:
    
    https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack

Installation ist u.a. hier beschrieben

    https://electrobotify.wordpress.com/2019/08/16/remote-development-on-raspberry-pi-with-vs-code/

Wenn dann das Remote-VSCode auf dem Raspi läuft, kann man so arbeiten, als wäre VSCode auf dem Raspi direkt installiert.
Um C-Programme zu schreiben muss man auf dem Remote-VSCode die Extension C/C++ von Microsoft installieren (mittels Button "Install in SSH: XXXXX").

Beispiel für ein Hello-World Programm in c++:

    https://tutorials-raspberrypi.de/raspberry-pi-visual-studio-code-installieren-cpp-programmieren/


# Diverses


##  bcm2835 library installieren

Doku siehe http://www.airspayce.com/mikem/bcm2835/

    cd /home/pi/
    wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.58.tar.gz 
    tar zxvf bcm2835-1.58.tar.gz
    cd bcm2835-1.58
    ./configure
    make
    make check
    make install
    
    
## mqtt library installieren

Doku siehe https://www.eclipse.org/paho/clients/c/


    apt-get install libssl-dev

    cd /home/pi/
    git clone https://github.com/eclipse/paho.mqtt.c.git
    cd paho.mqtt.c
    make
  
  Bei mir gab es mehrere Warnungen das TLSv1 veraltet ist - die kann man ignorieren
    
    make install

Auch hier gab es bei mir ein paar Warnungen
    
    
    
    
    
        
