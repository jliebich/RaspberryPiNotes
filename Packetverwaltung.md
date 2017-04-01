# Paketverwaltung
## aptitude
Aptitude ist ein Tool, welches apt-cache und apt-get ersetzt

    sudo aptitude
  
## Zu welchem Paket gehört welche Datei/Ordner?

    dpkg -S Dateiname

## Information zu einem Paket ausgeben

    dpkg -l Paketname
    
Filtern mit grep

## Im installierten Paket enthaltenen Dateien ausgeben

    dpkg -L Paketname

##Deinstallation ausprobieren
Meiner Erfahrung nach ist es gefährlich etwas zu deinstallieren, wenn es dazu führt das etwas anderes INSTALLIERT wird.
Deshalb ist es hilfreich vorher eine Simulation (Dry-Run) der Deinstallation zu machen:

     sudo apt-get --dry-run purge Paketname

## Heruntergeladene Installationsdateien aus dem Paket-Cache /var/cache/apt/archives/ löschen

     sudo apt-get [Option(en)] clean  

Dies gibt teilweise > 100 MB Speicherplatz frei

## Welche Version ist im Paketmanager    
    
     apt-cache show Paketname

## Suchen ob Paket vorhanden

     apt-cache search SUCHBEGRIFF  

## Installierte Pakete auslesen
     
     dpkg --get-selections \* > tmp/PAKETLISTE

oder mit dem Tool

     apt-show-versions
     
Dieses zeigt verfügbare auch Paketversionen mit Distribution an - insbenondere interessant wenn man Distributionen mischt (Wheezy und Jessie)

## Pakete wiederherstellen
     
     dpkg --set-selections \* < tmp/PAKETLISTE
     apt-get deselect-upgrade
     
## Paket aus bestimmter Distribution installieren
Man kann Distributionen auch "mischen" z.B. Wheezy und Jessie
Vogehensweise:
* In /etc/apt/sources.list und den Dateien unter /etc/apt/sources.list.d beide Distributionen eintragen
* Unter /etc/apt/preferences folgenes eintragen:


     Package: *
     Pin: release n=wheezy
     Pin-Priority: 900
     
     Package: *
     Pin: release n=jessie
     Pin-Priority: 300
     
     Package: *
     Pin: release o=Raspbian
     Pin-Priority: -10

Jetzt kann ein bestimmtes Paket aus Jessie installiert werden mit:

    apt-get install -t jessie Paketname
    





