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

# Geräte (device) umbenennen

     rename <alterName> <neuerName>

also z.B.

     rename HM_55B1C7 Wassermelder

# Raum umbenennen


    attr room=room1 room room2

verschiebt alle Devices aus room1 nach room2. room1 ist dann verschwunden und room2 ist neu verfügbar. Das ist faktisch wie eine Umbenennung.

# Icon für Raum definieren

    attr WEB roomIcons Keller:control_building_modern_s_kg  EG:control_building_modern_s_eg OG:control_building_modern_s_og  DG:control_building_modern_s_dg
    
# Homematic-Geräte anlernen (pairen)

HM-MOD-UART in den "Akzeptiere-Pairing-Requests-Modus" bringen:

    set myHmUART hmPairForSec 600

Homematic-Gerät in den Pairing-Mode versetzen:

* Rauchmenlder: Taste drücken bis LED orange blinkt
* Heizregler und Wandthermostat: Boost-Taste min. 3 Sekunden drücken
* Funk-Gangmodul MP3 (HM-OU-CM-PCB): Taste TA1 min. 4 Sekunden drücken (dauerhaftes Blinken = Anlernmodus)
* 4 Kanal Funk-Schaltaktor für Batteriebetrieb (HM-LC-Sw4-Ba-PCB): Taste am entsprechenden Kanal min 4 Sekunden drücken 
