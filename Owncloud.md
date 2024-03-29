# Owncloud / Nextcloud
## Upgrade über Kommandozeile

Der Web-Updater von Nextcloud macht bei mit Probleme wegen Timeouts im Browser.
Deshalb ist es besser das Upgrade über die Kommandozeile zu machen

In folgenden Ordner wechslen

    cd /var/www/owncloud/updater

(ja, nextcloud ist bei mir unter owncloud installiert).

Dann

    sudo -u www-data php updater.phar

Update dauert eine Weile - daher besser unter Windows mit dem Programm "Don't sleep" (http://www.softwareok.de/?seite=Microsoft/DontSleep) verhindern das die SSH-Session abbricht... Eine andere Alternative ist natürlich screen (https://wiki.ubuntuusers.de/Screen/)

Beim Update wird unter `/var/www/owncloud/data/updater-XXXXXX/backups` ein Backup der gesamten Nextcloud-Installation angelegt.
Diese belegt ziemlich viel Speicherplatz, da auch die gesamte Datenbank mit enthalten ist. Das ist bei mir problematisch, da ich den gesamten Ordner `/var/www/owncloud` auf ein NAS sichere. Muss daher zügig gelöscht werden, wenn nach dem Update alles wie erwartet funktioniert.

## Maintenance Mode ausschalten

    sudo -u www-data php occ maintenance:mode --off
    
## Maintenance Mode einschalten

    sudo -u www-data php occ maintenance:mode --on

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

# Fehlermeldung "OC\HintException: [0]: Memcache \OC\Memcache\APCu not available for local cache (Is the matching PHP module installed and enabled?)"

Sofortiges beheben durch Aufruf von occ mit 
    
    php -d apc.enable_cli=1

also z.B 

    sudo -u www-data php -d apc.enable_cli=1 occ maintenance:mode --off
    
Generell in `/etc/php/7.X/cli/php.ini` die Zeile

    apc.enable_cli=1

am Ende einfügen


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

