## Installationsanleitung

https://splittscheid.de/ha-bridge-installation-auf-dem-raspberry-pi/


## ha-bridge Version gibts hier:

https://github.com/bwssytems/ha-bridge/releases

## Update ha-bridge Version

Siehe https://github.com/bwssytems/ha-bridge/wiki/HA-Bridge-FAQs#update

Wir müssen den Habridge-Dienst stoppen (falls er läuft):

        sudo systemctl stop habridge

Ins Installationsverzeichnis wechseln (verwenden Sie Ihren Ordnernamen, wenn nicht "habridge"):

        cd habridge

Vorhandene Datei ha-bridge.jar umbenennen:

        mv ha-bridge.jar ha-bridge-ARCHIVE.jar
        
Version herunterladen, auf die aktualisiert werden soll (wobei {VERSION} die Versionsnummer ist):

        wget https://github.com/bwssytems/ha-bridge/releases/download/v{VERSION}/ha-bridge-{VERSION}.jar

Heruntergeledene Datei umbenennen (wobei {VERSION} die Versionsnummer ist):

        mv ha-bridge-{VERSION}.jar ha-bridge.jar

habridge service wieder starten:

        sudo systemctl start habridge


## Kommandos für Robbie:

http://www.robonect.de/viewtopic.php?f=11&t=11
