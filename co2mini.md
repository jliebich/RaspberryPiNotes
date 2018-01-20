# co2mini

https://github.com/henryk/fhem-co2mini

https://forum.fhem.de/index.php?topic=41750.0

https://hackaday.io/project/5301-reverse-engineering-a-low-cost-usb-co-monitor

# Install

Dateien von hier

        https://github.com/verybadsoldier/fhem-co2mini/tree/vbs
        
oder hier

        https://github.com/henryk/fhem-co2mini/tree/verybadsoldier-vbs
        
herunterladen. Darauf achten, dass man nicht die veraltete Version von FHEM/38_co2mini.pm bekommt.
Die richtige ist vom 24.01.2016 / 10.046 Bytes

        cd /etc/udev/rules.d

Datei 90-co2mini.rules mit folgendem Inhalt anlegen

    ACTION=="remove", GOTO="co2mini_end"
    SUBSYSTEMS=="usb", KERNEL=="hidraw*", ATTRS{idVendor}=="04d9", ATTRS{idProduct}=="a052", GROUP="plugdev", MODE="0660", SYMLINK+="co2mini%n", GOTO="co2mini_end"
    LABEL="co2mini_end"

Neu booten.

## co2mini_server.pl

Dieses Skript muss mit zwei Argumenten gestartet werden:
Dem "Device Node" des co2mini-Gerätes und eine Portnummer. Bei mir

    sudo perl co2mini_server.pl /dev/co2mini0 1971

Es wird dann auf diesem Port (hier 1971) lauschen und Verbindungen von Clients akzeptieren.
Clients erhalten vom CO2-Monitor einen Strom von entschlüsselten Nachrichten (d.h. 5 Byte bis einschließlich 0x0D).
Um das FHEM-Modul so zu konfigurieren, dass es sich mit einem entfernten co2mini_server.pl verbindet, muss einfach "address:port" anstelle des "Decvie Node" angegeben werden.

## startup/shutdown Skript für den server

Dieses Script 

https://github.com/jliebich/RaspberryPiNotes/blob/master/scripts/co2mini

installieren, z.B. mit

        cd /etc/init.d/
        wget https://raw.githubusercontent.com/jliebich/RaspberryPiNotes/master/scripts/co2mini
        chmod +x co2mini
        
Jetzt die Variablen file und port darin entsprechend anpassen.
Dann

        update-rc.d co2mini defaults
        service co2mini start
        
 Kann jetzt mit
 
        service co2mini start|restart|stop|status
        
genutzt werden.






