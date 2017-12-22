# MySQL
## MySQL-Passwort vergessen
Die Datei
 
    /etc/mysql/debian.cnf

öffnen. Hier steht das MySQL-Passwort für den speziellen Benutzer „debian-sys-maint“.
Mit dem kann man direkt das Passwort aktualisieren:

    mysql -u debian-sys-maint -p

und anschließend:

    show databases;
 
 Eine Datenbank aus der Liste auswählen, z.B. mysql
 
     use mysql;
     
 und Passwort für Nutzer root neu setzen:
 
    update user set password=PASSWORD("xyz123") where user='root'; 
    
 und abschießen:

     flush privileges;
     quit;
 
## Tables eine Datenbank anzeigen

Nach dem auswählen der Datenbank mit use, also z.B.

     use DB_wallabag;
     
folgendes eingeben

     show tables;
     
## Inhalt einer Table anzeigen
     
     SELECT * FROM <table name here>
 
## Datenbank löschen

     DROP DATABASE <Datenbankname>

 
## Zentrale MySQL Konfig-Datei

    /etc/mysql/my.cnf

## Einstellungen optimieren

https://github.com/major/MySQLTuner-perl


## Server System Variablen anzeigen

Aktuellern Wert der Server System Variablen anzeigen

     mysql> SHOW VARIABLES LIKE 'have_query_cache';
     +------------------+-------+
     | Variable_name    | Value |
     +------------------+-------+
     | have_query_cache | YES   |
     +------------------+-------+


## Owncloud
Die Zugangsdaten von Owncloud zur MySQL-Datenbank stehen in der Datei
    
    config/config.php
 
 
