#Owncloud
##Maintenance Mode ein- ausschalten

    sudo -u www-data php occ maintenance:mode --on

bzw.

    sudo -u www-data php occ maintenance:mode --off
    

##Mysql Datenbank sichern

    mysqldump -u<Benutzer> -p<Passwort> <Datenbank> > backup$(date +%Y-%m-%d-%H.%M.%S).sql
    
in meinem Fall:

    mysqldump -uroot -pStrengGeheim owncloud > backup$(date +%Y-%m-%d-%H.%M.%S).sql
    
##Mysql Datenbank wiederherstellen

    mysql -h [server] -u [username] -p[password] [db_name] < owncloud-dbbackup.bak
    
in meinem Fall:

    mysql -u root -pStrengGeheim owncloud < backupxxxxxx.sql
    
