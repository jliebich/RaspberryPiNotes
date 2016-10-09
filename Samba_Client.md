#Raspi als Samba Client

##Benötigte Packete installieren
      
    apt-get install cifs-utils
  
Ordner anlegen, in den das NAS-Laufwerk gemountet werden soll z.B. /media/NAS
  
      mkdir /media/NAS
  
##Credentials

.smbcredentials, im eigenen Homeverzeichnis anlegen. Inhalt

    username=<benutzer>
    password=<passwort>
  
Dies sind die Angaben des Benutzers den man im NAS angelegt hat.

## Mounten
 
     mount -v -t cifs -o credentials=~/.smbcredentials //192.168.0.11/Backup_Raspi /media/NAS
  
  -v erzeugt zusätzliche Ausgabe, die hilft um das mounten in C durchzuführen
  
##Hinweis
  
Eine samba Freigabe im NAS ist nicht geeignt, damit der Raspi dort per rsync oder rsnapshot Backups ablegt.
Beide Programme wollen per chown nach dem kopieren dort die Nutzerrechte passend setzen - dies funktioniert aber nicht, da Samba aus der Windows-Welt  kommt.
  
