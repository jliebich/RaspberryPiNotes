#Paketverwaltung
##aptitude
Aptitude ist ein Tool, welches apt-cache und apt-get ersetzt

    sudo aptitude
  
##Zu welchem Packet gehört welche Datei/Ordner?

    dpkg -S Dateiname

##Information zu einem Packet ausgeben

    dpkg -l Packetname
    
Filtern mit gre

##Im installierten Paket enthaltenen Dateien ausgeben

    dpkg -L Packetname

##Deinstallation ausprobieren
Erfahrungsgemäß ist es gefährlich etwas zu deinstallieren, wenn es dazu führt das etwas anderes INSTALLIERT wird.
Deshalb ist es hilfreich vorher eine Simulation (Dry-Run) der Deinstallation zu machen:

     sudo apt-get --dry-run purge Packetname

##Welche Version ist im Packetmanager    
    
     apt-cache show Packetname
