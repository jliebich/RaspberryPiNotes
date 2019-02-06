# MQTT

## MQTT C Client
https://www.eclipse.org/paho/clients/c/

Asynchronous subscription example:
https://www.eclipse.org/paho/files/mqttdoc/MQTTClient/html/subasync.html

## FHEM und MQTT
https://wiki.fhem.de/wiki/MQTT
Zitat: "Nutzt man das MQTT-Protokoll dagegen vorwiegend innerhalb von FHEM, ist eher der Einsatz von MQTT2_SERVER in Betracht zu ziehen." 

Ich verwende trotzdem mosquitto, da dies auf dem FHEM-Raspi schon installiert war. 


## mosquitto installieren
Quelle: http://blog.wenzlaff.de/?p=6487

        sudo apt-get install mosquitto mosquitto-clients python-mosquitto libmodule-pluggable-perl

python-mosquitto wird bei mir nicht gefunden, erst mal nichts gemacht. Mal schauen ob das Probleme macht.
        
Andere Anleitung: https://www.youtube.com/watch?v=ro0-W9Nl6sk

Installiert wird unter 

        /usr/sbin/mosquitto
        
Konfig-File ist unter 

        /etc/mosquitto/mosquitto.conf

Weitere setups für Perl (für FHEM)

        sudo cpan install Net::MQTT:Simple
        sudo cpan install Net::MQTT:Constants
        
## Mosquitto in FHEM konfigurieren

        define MyMosquitto MQTT 192.168.0.35:1883
 

        
