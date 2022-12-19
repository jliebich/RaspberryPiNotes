# Traccar

## Download

https://www.traccar.org/download/

## Installation

https://www.traccar.org/install-digitalocean/

Abweichend von dieser Anleitung folgendes in /opt/traccar/conf/traccar.xml eintragen

    <entry key='database.driver'>com.mysql.cj.jdbc.Driver</entry>
    <entry key='database.url'>jdbc:mysql://localhost:3306/[DATABASE]?serverTimezone=UTC&amp;allowPublicKeyRetrieval=true&amp;useSSL=false&amp;allowMultiQueries=true&amp;autoReconnect=true&amp;useUnicode=yes&amp;characterEncoding=UTF-8&amp;sessionVariables=sql_mode=''</entry>

(Rest wie in Anleitung)

## Aktuell insalliere Version anzeigen

In der Weboberfläche unter Einstellungen -> Info

## Upgrade

https://www.traccar.org/upgrading-traccar/

### Make a database backup

### Backup your config file

    /opt/traccar/conf/traccar.xml

und 

    /opt/traccar/conf/default.xml
    
### Backup media folder
Habe ich nicht

### Remove old version of Traccar

### Install new version of Traccar

### Restore media folder

### Restore config file (if applicable)

### Start Traccar service

## SSL einrichten

https://www.traccar.org/secure-connection/

https://www.traccar.org/forums/topic/nginx-ssl-websocket-example-configuration/

## Überflüssig Port disabeln

https://www.traccar.org/forums/topic/how-to-reduce-open-tcp-ports-on-the-server/


