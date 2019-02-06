# MQTT


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
 
## MQTT_GENERIC_BRIDGE

Um in FHEM einfach für vorhandene Devices MQTT-Nachrichten zu erzeugen verwende ich das Modul MQTT_GENERIC_BRIDGE

        defmod mqttGeneric MQTT_GENERIC_BRIDGE mqtt
        attr mqttGeneric IODev MyMosquitto
        
Damit ein Device automatisch MQTT-Nachriten versendet, wenn sich ein Reading ändert muss noch folgendes Attribut gesetzt werden Hier am Bespiel des Device "co2" mit topic "/Haus/EG/Wohnzimmer/CO2":

        attr co2 mqttPublish *:topic={"/Haus/EG/Wohnzimmer/CO2/$reading"}
        
# MQTT-Client mit C schreiben

### MQTT C Client
https://www.eclipse.org/paho/clients/c/

Installieren:

        apt-get install libssl-dev
        git clone https://github.com/eclipse/paho.mqtt.c.git
        cd paho.mqtt.c
        make
        


Asynchronous subscription example:
https://www.eclipse.org/paho/files/mqttdoc/MQTTClient/html/subasync.html

