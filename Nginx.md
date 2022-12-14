# Nginx

## Nginx statt Apache nutzen

http://www.zdnet.de/41559930/mehr-leistung-im-www-nginx-statt-apache-nutzen/

## Nginx/PHP auf Raspberry pi

Das hat bei mir funktioniert:
http://jankarres.de/2012/08/raspberry-pi-webserver-nginx-installieren/

Das irgendwie nicht:
http://www.ducky-pond.com/posts/2013/Sep/setup-a-web-server-on-rpi/

## Apache stoppen und Nginx starten

Nginx kann parallel zu Apache installiert werden (wer nur testen mag).
Zur Nutzung solltest du einfach den einen Dienst beenden und den anderen starten

    service apache2 stop && service nginx start

## Pfad zur nginx Konfiguration

    /etc/nginx/sites-enabled    

## Konfiguration von nginx testen

    sudo nginx -t

## Expires header für statische Files setzen

    location ~* \.(jpg|jpeg|gif|png|css|js|ico|xml)$ {
    expires           360d;
    }

## epoll empfohlen für Linux-Systeme

    events {
        use epoll;
    }

## htaccess to nginx converter

http://winginx.com/en/htaccess

## owncloud unter nginx

Diese Anleitung hat bei mir funktioniert:

http://jankarres.de/2013/10/raspberry-pi-owncloud-server-installieren/

Das ist die offizielle Anleitung (machte bei mir Probleme):

http://doc.owncloud.org/server/7.0/admin_manual/installation/installation_source.html

## Setting up Perl FastCGI with Nginx

http://nginxlibrary.com/perl-fastcgi/

## IP based country blocking

http://nginxlibrary.com/ip-based-country-blocking/

## Welche Module sind installiert

Ausgabe mit

    sudo nginx -V

vergleichen mit Modulliste unter

http://wiki.nginx.org/NginxModules

## Neuere nginx-Version installieren (aus Stretch)

https://getgrav.org/blog/raspberrypi-nginx-php7-dev

## Ausgabe der Versionsnummer auf Fehlerseiten und im Header unterdrücken 

In der „http„-Sektion der nginx.conf folgendes einfügen

    server_tokens off;

## SSL Konfiguration prüfen

https://www.ssllabs.com/ssltest/

## SSL Konfiguration sicherer machen

Siehe
https://www.sherbers.de/howto/nginx/
oder
https://beaglesecurity.com/blog/article/nginx-server-security.html

Mit ssl_ciphers kann man nginx sagen, welche ciphers es erlauben soll (bzw. mit vorgestelltem ! welche nicht)

nginx erwartet dabei namen, die openssl versteht.

Hier eine Liste der Namen:

https://testssl.sh/openssl-iana.mapping.html

Mit dieser Konfiguration

    ssl_ciphers HIGH:!aNULL:!MD5:!CAMELLIA:!ECDHE-RSA-AES256-SHA384:!ECDHE-RSA-AES128-SHA256:!ECDHE-RSA-AES256-SHA:!ECDHE-RSA-AES128-SHA:!AES256-GCM-SHA384:!AES256-CCM8:!AES256-CCM:!AES128-GCM-SHA256:!AES128-CCM8:!AES128-CCM:!AES256-SHA256:!AES128-SHA256:!AES256-SHA:!AES128-SHA;

liefert SSLLabs noch folgende "weak" ciphers:

    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA (0xc013)   ECDH x25519 (eq. 3072 bits RSA)   FS   WEAK
    TLS_RSA_WITH_ARIA_256_GCM_SHA384 (0xc051)   WEAK
    TLS_RSA_WITH_ARIA_128_GCM_SHA256 (0xc050)   WEAK

Diese haben leider keinen openssl Namen, deshalb weiß ich nicht, wie ich die deaktivieren soll.



