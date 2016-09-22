#Wallabag installieren

## Wallabag per Git nach /var/www auschecken...
    cd /var/www
    git clone https://github.com/wallabag/wallabag
    chown www-data.www-data -R /var/www/wallabag

## Auf vielen Webservern wird mod_tidy fehlen...
    apt-get install php5-tidy

## Twig (http://twig.sensiolabs.org) installieren...
    cd /var/www/wallabag
    sudo -s
    curl -s http://getcomposer.org/installer | php
    php composer.phar install

#Wallagbag aktualisieren
    cd /var/www/wallabag
    git pull
    chown www-data.www-data -R /var/www/wallabag
