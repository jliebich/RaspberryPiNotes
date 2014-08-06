#Nginx

##Nginx statt Apache nutzen

http://www.zdnet.de/41559930/mehr-leistung-im-www-nginx-statt-apache-nutzen/


##Apache stoppen, Nginx starten
Nginx kann parallel zu Apache installiert werden (wer nur testen mag).
Zur Nutzung solltest du einfach den einen Dienst beenden und den anderen starten

    service apache2 stop && service nginx start

#Konfiguration von nginx testen

    sudo nginx -t

#Expires header für statische Files setzen

    location ~* \.(jpg|jpeg|gif|png|css|js|ico|xml)$ {
    expires           360d;
    }

#epoll empfohlen für Linux-Systeme

    events {
        use epoll;
    }
