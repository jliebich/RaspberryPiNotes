#iptables
iptables ist ein Programm zur Konfiguration der Firewall-Tabellen.

##Konfiguration editieren

    sudo nano /etc/network/iptables
  
##Konfiguration laden

    sudo iptables-restore /etc/network/iptables
    
##Konfiguration anzeigen

    sudo iptables -L

oder ausführlicher (mit Anzahl der gefilterten Packete/Bytes je Regel):

    sudo iptables -L -v


##Firewall-Regeln bei einem Neustart des Systems automatisch laden

    sudo nano /etc/network/if-pre-up.d/iptables

Fügen Sie in die Datei `/etc/network/if-pre-up.d/iptables` die folgenden Zeilen ein.

    #!/bin/sh
    /sbin/iptables-restore /etc/network/iptables

Damit das Skript ausgeführt werden kann müssen Sie die Zugriffsrechte entsprechend anpassen.

    sudo chmod +x /etc/network/if-pre-up.d/iptables


##ipset um große Blacklists zu verwalten
https://neverendingsecurity.wordpress.com/2015/04/13/iptables-blacklist-script/

##Links

http://www.forum-raspberrypi.de/Thread-tutorial-linux-firewall-iptables-unter-raspbian-konfigurieren
