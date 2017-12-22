#Wallabag installieren

## Auf vielen Webservern wird mod_tidy fehlen...
    apt-get install php5-tidy

## Composer aktualisieren

    composer selfupdate    

## Wallabag per Git nach /var/www auschecken...
    cd /var/www
    git clone https://github.com/wallabag/wallabag
    chown www-data.www-data -R /var/www/wallabag

## MySQL Datenbank anlegen

    mysql -uroot -p

Root-Passwort eingeben


    CREATE DATABASE DB_wallabag;
    GRANT ALL PRIVILEGES ON DB_wallabag.* TO 'USER_wallabag'@'localhost' IDENTIFIED BY '_PASSWORD_';
    FLUSH PRIVILEGES;
    \q

# Install-Script aufrufen

    cd /var/www/wallabag
    make install

Dieser Schritt schlug bei mir wegen zu wenig RAM fehl - daher swap-File anlegen

https://jankarres.de/2012/11/raspberry-pi-swap-erweitern/

Nach einiger Lasufzeit kommt abfrage nach Datenbank

    database_driver (pdo_sqlite): pdo_mysql
    database_host (127.0.0.1): 127.0.0.1
    database_port (null): 3306
    database_name (symfony): DB_wallabag
    database_user (root): USER_wallabag
    database_password (null): $PASSWORTDESDATENBANKNUTZERS
    database_path ('%kernel.root_dir%/../data/db/wallabag.sqlite'):
    database_table_prefix (wallabag_): wallabag_
    mailer_transport (smtp): smtp
    mailer_host (127.0.0.1): $MAILSERVERIPBZWNAME
    mailer_user (null): $bENUTZERNAMENMAILSERVER
    mailer_password (null): $PASSWORTMAILSERVER
    locale (en): en
    secret (ovmpmAWXRCabNlMgzlzFXDYmCFfzGv): $SECRTEINGEBEN

Später kommt die Frage

    It appears that your database already exists. Would you like to reset it?

hier mit NEIN antworten, sonst kam bei mir Fehlermeldung und Abbruch. 

Danach wird man aufgefordert einen "Admin" User anzulegen - dies wie vorgeschlagen tun, es ist KEIN SQL-Datenbankuser!

# Wallagbag aktualisieren

Dieses Kommando scheint die neueste Version Wallabag Version zu laden.
Auf jeden Fall migriert es die Datenbank auf die neue Version.

    make update

Wenn die Datenbank leer ist, funktioniert die Migration nicht - dann muss man das sier machen:
https://github.com/wallabag/wallabag/issues/3480

# wallabag Log
Neben den Log-Dateien die der Server anlegt, hat wallabag noch eine eigene Log-Datei.
Die liegt bei mir unter

    /var/www/wallabag/var/logs/prod.log


# Setting up wallabag + MySQL + nginx

https://blog.ronsonchan.com/setting-up-wallabag-mysql-nginx/
