# PUTTY
## Zwischenablage
Zwischanablage lässt sich mit rechter Maustaste einfügen
## KITTY
KITTY ist eine verbesserte Version von PUTTY
## Automatische Verbindungstrennung verhindern
Unter "Connection" "Seconds between keepalives" auf 120 setzen
## User und Passwort vorgeben
Siehe "Connection->Data"
## Zeichendarstellung
Damit Umlaute und Rahmenlinien richtig dargestellt werden unter Window -> Translation -> UTF-8 einstellen
Bei meinem Raspi 4 hat das nicht gereicht, hier musste ich auch noch unter Windows -> Translation ein Häckchen unter "Enable VT100 Line Drawing even in UTF-8 Mode. 

## Speicherort Sessions
Sessions speichert Kitty bei mit unter
    
    C:\Users\[Benutzername]\AppData\Local\VirtualStore\Program Files (x86)\Kitty\Sessions
    
vermutlich weil der Sessions-Ordner im Kitty-Programmverzeichnis schreibgeschützt ist.
