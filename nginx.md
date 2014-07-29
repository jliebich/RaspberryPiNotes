#Nginx

##Nginx statt Apache nutzen

http://www.zdnet.de/41559930/mehr-leistung-im-www-nginx-statt-apache-nutzen/


##Apache stoppen, Nginx starten
Nginx kann parallel zu Apache installiert werden (wer nur testen mag).
Zur Nutzung solltest du einfach den einen Dienst beenden und den anderen starten

    service apache2 stop && service nginx start

