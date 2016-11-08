#Wallabag installieren

##Composer aktualisieren

    composer selfupdate    

## Wallabag per Git nach /var/www auschecken...
    cd /var/www
    git clone https://github.com/wallabag/wallabag
    chown www-data.www-data -R /var/www/wallabag

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
