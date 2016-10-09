##Arbeiten an Synology NAS (Server)
Systemsteuerung das Menü „Gemeinsame Ordner“ , neues Verzeichnis, z.B. Backup_Raspi

Für die Dateisicherung benötigen Sie mindestens einen Benutzer, welcher schreibend darauf zugreifen darf.

In meinem Beispiel heißt der User NASRaspi – er bekommt lese und schreibzugriff im Tab „Berechtigungen“.

Unter „NFS-Berechtigungen“ → „Erstellen“ Lese- und Schreibzugriff für die IP des Raspberry Pi erlauben.

Unten im Fenster steht auch der Mount-Pfad der später benötigt wird – bei mir /volume1/Backup_Raspi 

##Arbeiten an Raspberry Pi (Client)
Benötigte Packete installieren
    
    apt-get install nfs-common cifs-utils libnss-myhostname

Testen ob Zugriff möglich ist mit

    showmount -e [ip-Adresse-NAS]
    
hier muss jetzt das oben angelegte Verzeichnis erscheinen

Ordner anlegen, in den das NAS-Laufwerk gemountet werden soll z.B. /media/NAS

    mkdir /media/NAS

Testweise mounten:

    mount -t nfs [ip-Adresse-NAS]:[Mount-Pfad] /media/NAS

[ip-Adresse] durch die IP-Adresse des NAS-Laufwerks ersetzen, [Mount-Pfad] durch MountPfad-Name (siehe oben) – bei mir also

    mount -t nfs 192.168.0.11:/volume1/Backup_Raspi /media/NAS

Bei Fehlermeldung

    mount.nfs: rpc.statd is not running but is required for remote locking.
    mount.nfs: Either use '-o nolock' to keep locks local, or start statd.
    mount.nfs: an incorrect mount option was specified
    
muss noch folgendes gemacht werden:

    service rpcbind start
    
und

    update-rc.d rpcbind enable
