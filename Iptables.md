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

    
##Links

http://www.forum-raspberrypi.de/Thread-tutorial-linux-firewall-iptables-unter-raspbian-konfigurieren
