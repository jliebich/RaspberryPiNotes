# Traccar

## Download

https://www.traccar.org/download/

## Installation

https://www.traccar.org/install-digitalocean/

Abweichend von dieser Anleitung folgendes in /opt/traccar/conf/traccar.xml eintragen

    <entry key='database.driver'>com.mysql.cj.jdbc.Driver</entry>
    <entry key='database.url'>jdbc:mysql://localhost:3306/[DATABASE]?serverTimezone=UTC&amp;allowPublicKeyRetrieval=true&amp;useSSL=false&amp;allowMultiQueries=true&amp;autoReconnect=true&amp;useUnicode=yes&amp;characterEncoding=UTF-8&amp;sessionVariables=sql_mode=''</entry>

(Rest wie in Anleitung)

## Upgrade

https://www.traccar.org/upgrading-traccar/



## SSL einrichten

https://www.traccar.org/secure-connection/

https://www.traccar.org/forums/topic/nginx-ssl-websocket-example-configuration/

## Überflüssig Port disabeln

https://www.traccar.org/forums/topic/how-to-reduce-open-tcp-ports-on-the-server/


