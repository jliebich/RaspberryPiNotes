# RaspiBackup


Quelle
https://www.linux-tips-and-tricks.de/de/raspibackup/

Ich nutze raspiBackup um dd Backups (=SD-Karten Images) auf meine NAS zu kopieren.
Starte das ganze manuell, also NICHT zeitgesteuert

Meldungen (Fehler, Erfolg Ergebnis) werden an Telegram gesendet

## Pfade

    /usr/local/bin/raspiBackup
    
    /usr/local/bin/raspiBackupInstallUI
    
    /usr/local/etc/raspiBackup.conf

## NAS (nfs) automatisch mounten

In raspiBackup.conf

    # Name der Backuppartition die dynamisch gemounted werden soll (z.B. /dev/sda1 oder /backup), muss sonst leer sein um keinen dynamischen Mount zu benutzen
    DEFAULT_DYNAMIC_MOUNT="192.168.0.11:/volume1/Backup_Raspi"
    
in /etc/fstab    

    192.168.0.11:/volume1/Backup_Raspi /media/nas-backup nfs noauto,rw,nfsvers=3 0 0
    
## Starten

- Vor dem Start lohnt es sich mit `ncdu` nach Speicherfressern zu suchen. Bei Nextcloud sollten z.B. unbenötigte Backups unter `/var/owncloud/data/updater-XXXXXX` gelöscht werden
- `apt clean` gefolgt von `apt autoremove` auführen
- `journalctl --vacuum-size=100M` ausführen, um Logs zu löschen

Ich habe 2 Arten eingerichtet

- `raspiBackup` sichert ein dd image auf der NAS (benutzt Configdatei ´/usr/local/bin/raspiBackup`)
- `raspiBackup -f /usr/local/etc/raspiBackuptar.conf` sichert ein tar image auf der NAS

## PiShrink

Nach erstellen des Backups kann mit PiShrink die .img Datei deutlich verkleinert werden, siehe

https://github.com/Drewsif/PiShrink

PiShrink habe ich unter Ubuntu auf WSL installiert UND auch auf der NAS 

Ausführung auf der Synology NAS:

- Einloggen via SSH
- In den Ordner `/volume1/Backup_Raspi/Backup/raspberrypi/raspberrypi-dd-backup-XXXXXX` wechseln
- `sudo pishrink.sh -vrpd raspberrypi-dd-backup-XXXXXX.img` ausführen







