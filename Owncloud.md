# Owncloud
## Maintenance Mode einschalten

    sudo -u www-data php occ maintenance:mode --on

## Update auf Kommandozeile starten, nachdem Files manuell aktualisiert wurden

    sudo -u www-data php occ upgrade

## Maintenance Mode ausschalten

    sudo -u www-data php occ maintenance:mode --off
    


## Mysql Datenbank sichern

    mysqldump -u<Benutzer> -p<Passwort> <Datenbank> > backup$(date +%Y-%m-%d-%H.%M.%S).sql
    
in meinem Fall:

    mysqldump -uroot -pStrengGeheim owncloud > backup$(date +%Y-%m-%d-%H.%M.%S).sql
    
## Mysql Datenbank wiederherstellen

    mysql -h [server] -u [username] -p[password] [db_name] < owncloud-dbbackup.bak
    
in meinem Fall:

    mysql -u root -pStrengGeheim owncloud < backupxxxxxx.sql
    

# Fehlermeldung "PHP scheint zur Abfrage von Systemumgebungsvariablen nicht richtig eingerichtet zu sein"

https://doc.owncloud.org/server/8.1/admin_manual/installation/source_installation.html#php-fpm-tips-label

Kommentarzeichen vor diesen Einträgen entfernen in Datei `/etc/php5/fpm/pool.d/www.conf`

    env[HOSTNAME] = $HOSTNAME
    env[PATH] = /usr/local/bin:/usr/bin:/bin
    env[TMP] = /tmp
    env[TMPDIR] = /tmp
    env[TEMP] = /tmp

# Fehlermeldung "Es wurde kein PHP Memory Cache konfiguriert"

Folgende Zeile in `config.php` editieren

    'memcache.local' => '\OC\Memcache\APCu',
    
# Berechtigungen setzen

Script SetPermissions.sh (liegt bei mir unter /root)


    #!/bin/bash
    ocpath='/var/www/owncloud'
    htuser='www-data'
    htgroup='www-data'
    rootuser='root'

    printf "Creating possible missing Directories\n"
    mkdir -p $ocpath/data
    mkdir -p $ocpath/assets
    mkdir -p $ocpath/updater
    
    printf "chmod Files and Directories\n"
    find ${ocpath}/ -type f -print0 | xargs -0 chmod 0640
    find ${ocpath}/ -type d -print0 | xargs -0 chmod 0750
    
    printf "chown Directories\n"
    chown -R ${rootuser}:${htgroup} ${ocpath}/
    chown -R ${htuser}:${htgroup} ${ocpath}/apps/
    chown -R ${htuser}:${htgroup} ${ocpath}/assets/
    chown -R ${htuser}:${htgroup} ${ocpath}/config/
    chown -R ${htuser}:${htgroup} ${ocpath}/data/
    chown -R ${htuser}:${htgroup} ${ocpath}/themes/
    chown -R ${htuser}:${htgroup} ${ocpath}/updater/

    chmod +x ${ocpath}/occ

    printf "chmod/chown .htaccess\n"
    if [ -f ${ocpath}/.htaccess ]
        then
            chmod 0644 ${ocpath}/.htaccess
        chown ${rootuser}:${htgroup} ${ocpath}/.htaccess
        fi
    if [ -f ${ocpath}/data/.htaccess ]
        then
            chmod 0644 ${ocpath}/data/.htaccess
            chown ${rootuser}:${htgroup} ${ocpath}/data/.htaccess
    fi
    
 
# Owncloud von php5 auf php7 upgraden

Migration von php5 nach php7:

https://berndklaus.at/owncloud-von-php5-auf-php7-upgraden/

Achtung! Installation von php7 nicht wie im obigen Link installieren sondern besser aus stretch wie hier beschrieben:

https://www.randombrick.de/raspberry-pi-nginx-und-php-installieren-und-einrichten/

Nötige php7 Pakete für owncloud

    apt-get -t stretch install php7.0-fpm php7.0-dev php7.0-mysql php7.0-cli php7.0-opcache

