#Serielle Schnittstellen
##Dem System bekannte Schnittstellen anzeigen

    dmesg | grep tty

##Momentane Konfiguration abfragen

    stty -F /dev/ttyS0 -a

