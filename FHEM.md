# FHEM
## Installationsverzechnis von FHEM

     /opt/fhem 

## Konfigurations-Datei

     /opt/fhem/fhem.cfg

## FHEM-Befehl in der Bash ausführen

     perl fhem.pl <Port> "<Befehl>" 
     
Beispiele

     perl fhem.pl 7072 "version" 
     
     perl fhem.pl 7072 "update check" 

     perl fhem.pl 7072 "update"
     
     perl fhem.pl 7072 "shutdown restart"

## FHEM Server starten/stoppen

      service fhem start

bzw.

      service fhem stop

Ein "restart" ist merkwürdigerweise nicht möglich.


## Mit FHEM auf andere Hardware umziehen

Siehe auch

http://www.meintechblog.de/2014/05/intel-nuc-als-smart-home-server-fhem-on-steroids/#more-4596

In der FHEM-Konsole der "alten" Installation "backup" (ohne Anführungszeichen) eingegeben.

Im Ordner /opt/fhem/backup/ sollte dann das Backup anzutreffen sein.

Diese Datei auf die neue Hardware ins Verzeichnis /opt/fhem/backup/ (muss erst erstellt werden) kopieren.

Um das Backup abschließend zurückzuspielen, FHEM auf der neuen Hardware mit

    service fhem stop

beenden und mit 

    sudo tar -xvzf /opt/fhem/backup/FHEM-XXXXXXXX_XXXXXXXX.tar.gz -C /opt/fhem/

das Backup auf der neuen Hardware in das passende Verzeichnis entpacken

Mit

    service fhem start

FHEM wieder starten.

CUL-Stick umstecken, Reboot mit
    
    reboot

## Geräte (device) umbenennen

     rename <alterName> <neuerName>

also z.B.

     rename HM_55B1C7 Wassermelder

## Raum umbenennen


    attr room=room1 room room2

verschiebt alle Devices aus room1 nach room2. room1 ist dann verschwunden und room2 ist neu verfügbar. Das ist faktisch wie eine Umbenennung.

## Icon für Raum definieren

    attr WEB roomIcons Keller:control_building_modern_s_kg  EG:control_building_modern_s_eg OG:control_building_modern_s_og  DG:control_building_modern_s_dg
    
## Homematic-Geräte anlernen (pairen)

HM-MOD-UART in den "Akzeptiere-Pairing-Requests-Modus" bringen:

    set myHmUART hmPairForSec 600

Homematic-Gerät in den Pairing-Mode versetzen:

* Rauchmelder: Taste drücken bis LED orange blinkt
* Heizregler und Wandthermostat: Boost-Taste min. 3 Sekunden drücken
* Funk-Gongmodul MP3 (HM-OU-CM-PCB): Taste TA1 min. 4 Sekunden drücken (dauerhaftes Blinken = Anlernmodus)
* Tür-/Fensterkontakt, optisch: Kurz auf Taste drücken
* 4 Kanal Funk-Schaltaktor für Batteriebetrieb (HM-LC-Sw4-Ba-PCB): Taste am entsprechenden Kanal min 4 Sekunden drücken. Laut Anleitung muss jeder Kanal einzeln angelert werden, in FHEM erscheinen bei mir aber sofort alle 4 Kanäle, nachdem ich einen Kanal angelert habe.

Nach dem Anlernen erkennt man an in der Weboberfläche von FHEM an dem roten Fragezeichen hinter "Save config", dass das Gerät angelernt wurde.
Man kann auf das Fragezechen klicken, um zu sehen wie das neue Gerät heißt. "Save config" klicken um die Änderung zu übernhemen

## Firmware-Update von HomeMatic-Komponenten

https://haus-automatisierung.com/hardware/fhem/2016/12/23/fhem-tutorial-reihe-part-19-firmware-update-homematic-komponenten.html

## Synology-NAS via SNMP überwachen

https://haus-automatisierung.com/hardware/fhem/2016/06/02/fhem-tutorial-reihe-part-10-synology-status-per-snmp-ueberwachen.html

## Floorplan

Floorplan nutzt ein CSS-Datei.
Welche genau verwendet wird kann im Browser mit dem F12-Tool herausgefunden werden. Bei mir ist es die Datei darkfloorplanstyle.css
Mit dem F12-Tool kann man auch leicht die Element-ID eines umzuformatierenden Textes gefunden werden.
Achtung: Änderungen in der CSS-Datei werden erst übernommen wenn man einen "vollen" Refresh der Seite vornimmt. Ein normales Neuladen reicht nicht! In Firefox muss man dazu Alt gedrückt halten und "Neu laden" klicken, bei Chrome muss man dazu Strg gedrückt halten und "Neu laden" klicken.

Bei einem Update wird die Datei /opt/fhem/www/pgm2/darkfloorplanstyle.css immer überschrieben und damit meine Änderung rückgängig gemacht.
Ich stelle sie dann immer aus dem Backup wieder her.


## Undo
Es gibt leider kein direktes Undo. Wnn man eine Änderung gemacht hat und noch nicht ```Save config``` geklickt hat, kann sie nur mit ```shutdown restart``` rückgängig gemacht werden.

## Backup
Vor größeren Änderungen empfiehlt sich, ein backup durchzuführen. Einfach

     backup
     
ins Eingabefeld eingeben. Unter /opt/fhem/backup wird dann im Hintergrund ein TAR-Archiv der kompletten Installation angelegt.
Im Logfile erscheint der einsprechende tar Aufruf und wenn Backup beendet ist die Zeile "Backup done"
Ältere Backups werden dabei NICHT gelöscht - mann sollte also ab und zu in dem backup-Ordner aufräumen.

## Eigene, globale Variablen in FHEM

Will man aber global Variablen nutzen, die man innerhalb der FHEM Steuerung auch von anderen Geräten oder notifys auslesen oder längerfristig speichern möchte, definiert man zunächst ein dummy-Device in FHEM, dem man später einen Wert geben kann:

define MeineVariable dummy

Diesem Device kann man jetzt einen Wert zuweisen – entweder aus FHEM selbst:

set MeineVariable on

oder aus Perl:

fhem(„set MeineVariable on“);

## Geräte tauschen

* Neues Geraet an fhem anlernen
* FHEM Configs entsprechend altem Geraet anpassen (Raum, DevStateIcon, etc...)
* M-Configs entsprechend altem Geraet anpassen (register, usw...)
* altes Device loeschen
* rename neues-HM-Geraet NamedesaltenHMGeraets
* Achtung, Tür/Fenstersensor-Status ist bei FS20 "Open" und "Close" bei Homematic ist es allerdings "open" und "close". DoIfs müssen also ggf angepasst werden
* shutdown restart
