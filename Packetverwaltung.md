#Paketverwaltung
##aptitude
Aptitude ist ein Tool, welches apt-cache und apt-get ersetzt

    sudo aptitude
  
##Zu welchem Paket gehört welche Datei/Ordner?

    dpkg -S Dateiname

##Information zu einem Paket ausgeben

    dpkg -l Paketname
    
Filtern mit grep

##Im installierten Paket enthaltenen Dateien ausgeben

    dpkg -L Paketname

##Deinstallation ausprobieren
Meiner Erfahrung nach ist es gefährlich etwas zu deinstallieren, wenn es dazu führt das etwas anderes INSTALLIERT wird.
Deshalb ist es hilfreich vorher eine Simulation (Dry-Run) der Deinstallation zu machen:

     sudo apt-get --dry-run purge Paketname

##Heruntergeladene Installationsdateien aus dem Paket-Cache /var/cache/apt/archives/ löschen

     sudo apt-get [Option(en)] clean  

Dies gibt teilweise > 100 MB Speicherplatz frei

##Welche Version ist im Paketmanager    
    
     apt-cache show Paketname

##Suchen ob Paket vorhanden

     apt-cache search SUCHBEGRIFF  

##Installierte Pakete auslesen
     
     dpkg --get-selections \* > tmp/PAKETLISTE

##Pakete wiederherstellen
     
     dpkg --set-selections \* < tmp/PAKETLISTE
     apt-get deselect-upgrade
     
