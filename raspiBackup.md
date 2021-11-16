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

## NAS (nfs) mounten

In raspiBackup.conf

    # Name der Backuppartition die dynamisch gemounted werden soll (z.B. /dev/sda1 oder /backup), muss sonst leer sein um keinen dynamischen Mount zu benutzen
    DEFAULT_DYNAMIC_MOUNT="192.168.0.11:/volume1/Backup_Raspi"
    
in /etc/fstab    

    192.168.0.11:/volume1/Backup_Raspi /media/nas-backup nfs noauto,rw,nfsvers=3 0 0
    
## PiShrink

Nach erstellen des Backups kann mit PiShrink die .img Datei deutlich verkleinert werden, siehe

https://github.com/Drewsif/PiShrink

PiShrink habe ich unter Ubuntu auf WSL installiert UND auch auf der NAS (Zugriff über ssh auf NAS)

