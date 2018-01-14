# co2mini

https://github.com/henryk/fhem-co2mini

https://forum.fhem.de/index.php?topic=41750.0

https://hackaday.io/project/5301-reverse-engineering-a-low-cost-usb-co-monitor

# Install

    git clone https://github.com/henryk/fhem-co2mini.git

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


