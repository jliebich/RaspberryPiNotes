#NOOBS Bootloader entfernen
Mit einem Linux-Rechner (nicht der Raspi!) SD Karte vom Raspi mounten.

Alle Daten kopieren:

     cp -r -p -f /<Deine SD-Karte/root-Verzeichnis> /<Dein kurzfristiger Speicherort>)

Nur die Betriebssystem Partition sichern, nicht Noobs!

SD-Karte aushängen und wie gewohnt Betriebssystem drauf spielen (Download von http://www.raspberrypi.org/downloads/)

Nun mit Linux PC SD-Karte mounten und alle zuvor gesicherten mit dem gleichen Befehl wieder zurück.

      cp -r -p -f /<Dein kurzfristiger Speicherort> /<Deine SD-Karte/root-Verzeichnis>).

