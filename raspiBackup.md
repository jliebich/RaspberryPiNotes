# RaspiBackup


Quelle
https://www.linux-tips-and-tricks.de/de/raspibackup/

Ich nutze raspiBackup um dd Backups (=SD-Karten Images) auf meine NAS zu kopieren.
Starte das ganze manuell, also NICHT zeitgesteuert

Meldungen (Fehler, Erfolg Ergebnis) werden an Telegram gesendet

## Pfade

Das eigentliche Backupprogramm:

    /usr/local/bin/raspiBackup
    
Die dazugehörige GUI für die grundlegende Konfiguration

    /usr/local/bin/raspiBackupInstallUI

Die Config-Datei - bei mir für das sichern eines dd Images auf dem NAS

    /usr/local/etc/raspiBackup.conf

## NAS (nfs) automatisch mounten

In raspiBackup.conf

    # Name der Backuppartition die dynamisch gemounted werden soll (z.B. /dev/sda1 oder /backup), muss sonst leer sein um keinen dynamischen Mount zu benutzen
    DEFAULT_DYNAMIC_MOUNT="192.168.0.11:/volume1/Backup_Raspi"
    
in /etc/fstab    

    192.168.0.11:/volume1/Backup_Raspi /media/nas-backup nfs noauto,rw,nfsvers=3 0 0
    
## Starten

- Vor dem Start lohnt es sich mit `ncdu` nach Speicherfressern zu suchen.
- Bei Nextcloud sollten unbenötigte Backups unter `/var/www/owncloud/data/updater-XXXXXX` gelöscht werden
- Bei FHEM sollten unbenötigte Backups unter `/opt/fhem/backup` gelöscht werden 
- `apt clean` gefolgt von `apt autoremove` auführen

Ich habe 2 Arten eingerichtet

- `raspiBackup` sichert ein dd image auf der NAS (benutzt Configdatei ´/usr/local/bin/raspiBackup`)
- `raspiBackup -f /usr/local/etc/raspiBackuptar.conf` sichert ein tar image auf der NAS

Mit der Option `-F` (=Fake) kann man vorher ausprobieren ob alles richtig eingerichtet ist

## PiShrink

Nach erstellen des Backups kann mit PiShrink die .img Datei deutlich verkleinert werden, siehe

https://github.com/Drewsif/PiShrink

PiShrink habe ich unter Ubuntu auf WSL installiert UND auch auf der NAS 

Ausführung auf der Synology NAS:

- Einloggen via SSH
- In den Ordner `/volume1/Backup_Raspi/Backup/raspberrypi/raspberrypi-dd-backup-XXXXXX` wechseln
- `sudo pishrink.sh -vrd raspberrypi-dd-backup-XXXXXX.img` ausführen
- Achtung: Option -p erfernt den SSH Schlüssel - daher nicht verwenden, da man sich sonst nicht mehr einloggen kann







