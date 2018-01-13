# co2mini

https://github.com/henryk/fhem-co2mini

https://forum.fhem.de/index.php?topic=41750.0

https://hackaday.io/project/5301-reverse-engineering-a-low-cost-usb-co-monitor


## co2mini_server.pl

Dieses Skript muss mit zwei Argumenten gestartet werden:
Dem "Device Node" des co2mini-Gerätes und eine Portnummer.
Es wird dann auf diesem Port lauschen und Verbindungen von Clients akzeptieren.
Clients erhalten vom CO2-Monitor einen Strom von entschlüsselten Nachrichten (d.h. 5 Byte bis einschließlich 0x0D).
Um das FHEM-Modul so zu konfigurieren, dass es sich mit einem entfernten co2mini_server.pl verbindet, muss einfach "address:port" anstelle des Geräteknotens angegeben werden.
