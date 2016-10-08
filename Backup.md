#Backup mit rsnapshot

Siehe
https://dvpizone.wordpress.com/2014/03/08/using-rsnapshot-with-a-raspberry-pi-to-create-a-backup-device/

##Installieren

    apt-get install rsnapshot


#Backup mit rsnapshot auf Synology NAS

##Arbeiten an Synology NAS:
Systemsteuerung das Menü „Gemeinsame Ordner“ , neues Verzeichnis, z.B. Backup_Raspi

Für die Dateisicherung benötigen Sie mindestens einen Benutzer, welcher schreibend darauf zugreifen darf.

In meinem Beispiel heißt der User NASRaspi – er bekommt lese und schreibzugriff im Tab „Berechtigungen“.

Wir werden mit Samba auf diesen Ordner zugreifern -NFS wäre schneller, aber mir ist es nicht gelungen dies ans Laufen zu bekommen...

##Arbeiten an Raspberry Pi:
Benötigte Packete installieren
    
    apt-get install cifs-utils

Ordner anlegen, in den das NAS-Laufwerk gemountet werden soll z.B. /media/NAS

    mkdir /media/NAS

.smbcredentials, im eigenen Homeverzeichnis anlegen. Inhalt

    username=<benutzer>
    password=<passwort>

Mounten:

    mount -v -t cifs -o credentials=~/.smbcredentials //192.168.0.11/Backup_Raspi /media/NAS

##Mounten in C

    const char* src = "\\\\192.168.0.11\\Backup_Raspi";
    const char* dst = "/media/NAS";
    const char* fstype = "cifs";

    const char* all_string = "unc=\\\\192.168.0.11\\Backup_Raspi,ip=192.168.0.11,username=NASRaspi,password=geheim";
   
    printf("Trying to mount...\n");
    fflush(stdout);
    // int mount (const char *special_file, const char *dir, const char *fstype, unsigned long int options, const void *data)
    int result = mount(src, dst, fstype, MS_MGC_VAL | MS_SILENT, all_string);


##Prüfen ob Laufwerk gemounted

    #!/bin/sh
    if mount | grep '^/dev/hda1 ' >/dev/null 2>&1 ; then
        echo "gemountet"
    else
        echo "nicht gemountet"
    fi
    exit 0
