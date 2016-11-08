#Wallabag installieren

##Composer aktualisieren

    composer selfupdate    

## Wallabag per Git nach /var/www auschecken...
    cd /var/www
    git clone https://github.com/wallabag/wallabag
    chown www-data.www-data -R /var/www/wallabag

#Install-Script aufrufen

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


## Auf vielen Webservern wird mod_tidy fehlen...
    apt-get install php5-tidy

## Twig (http://twig.sensiolabs.org) installieren...

Dieser Schritt schlug bei mir wegen zu wenig RAM fehl - daher swap-File anlegen

https://jankarres.de/2012/11/raspberry-pi-swap-erweitern/

    cd /var/www/wallabag
    sudo -s
    curl -s http://getcomposer.org/installer | php
    php composer.phar install





#Wallagbag aktualisieren
    cd /var/www/wallabag
    git pull
    chown www-data.www-data -R /var/www/wallabag

#Setting up wallabag + MySQL + nginx

https://blog.ronsonchan.com/setting-up-wallabag-mysql-nginx/
