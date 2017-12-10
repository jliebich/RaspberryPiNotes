## Installationsanleitung

https://splittscheid.de/ha-bridge-installation-auf-dem-raspberry-pi/


## ha-bridge Version gibts hier:

https://github.com/bwssytems/ha-bridge/releases

## Update ha-bridge Version

Siehe https://github.com/bwssytems/ha-bridge/wiki/HA-Bridge-FAQs#update

Ins Installationsverzeichnis wechseln (verwenden Sie Ihren Ordnernamen, wenn nicht "/home/pi/habridge"):

        cd /home/pi/habridge
      
Version herunterladen, auf die aktualisiert werden soll (wobei {VERSION} die Versionsnummer ist):

        wget https://github.com/bwssytems/ha-bridge/releases/download/v{VERSION}/ha-bridge-{VERSION}.jar

Wir müssen den Habridge-Dienst stoppen (falls er läuft):

        sudo systemctl stop habridge

Symlink /home/pi/ha-bridge.jar auf neue Version umlenken z.B. mit mc über File -> Edit symlink


habridge service wieder starten:

        sudo systemctl start habridge


## Kommandos für Robbie:

http://www.robonect.de/viewtopic.php?f=11&t=11
