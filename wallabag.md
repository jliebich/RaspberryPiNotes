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

Achtung! Dies scheint in neueren Versionen nicht mehr nötig zu sein!
Das "make install" (siehe unten) scheint schon eine passende Datenbank anzulegen!

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

# fail2ban Setup

Beispieleintrag in prod.log für einen fehlgeschlagenen Login:

    [2017-12-22 17:39:27] app.ERROR: Authentication failure for user "TestUser", from IP "192.168.0.9", with UA: "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.84 Safari/537.36". [] []

Filter: Inhalt von /etc/fail2ban/filter.d/wallabag.conf

    [Definition]
    failregex = ^\[\] app\.ERROR: Authentication failure for user "(\B|\S+)", from IP "<HOST>".*\[\]$
    ignoreregex =

Jail: Inhalt von /etc/fail2ban/jail.d/wallabag.conf

    [wallabag]
    enabled = true
    port = 80,443
    protocol = tcp
    filter = wallabag
    maxretry = 3
    logpath = /var/www/wallabag/var/logs/prod.log



# Setting up wallabag + MySQL + nginx

https://blog.ronsonchan.com/setting-up-wallabag-mysql-nginx/

# Öffentliche Benutzerregistrierung deaktivieren

Datei app/config/parameters.yml öffen und folgenden Eintrag setzen:

    fosuser_registration setzen = false
    
In den Stammordner der Wallabag-Installation wechseln und folgendes ausführen

    php bin/console cache:clear -e prod
    
Achtung: Dies dauert auf einem Raspberry Pi sehr lange!

# Update durchführen

Kleine Versionssprünge kann man mit 

    ./scripts/update.sh prod --ignore-root-warning

aus dem Ordner /home/wallabag durchführen


