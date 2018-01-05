# locate

locate ist ein Programm, mit dessen Hilfe man auf der Kommandozeile nach Dateien suchen kann.
Hierbei wird aber nicht das gesamte Datenverzeichnis durchsucht (wie bei find), sondern eine Datenbank, die zuvor angelegt wurde.
Diese wird regelmäßig aktualisiert, damit locate immer die korrekten Orte anzeigt, an denen sich die Dateien befinden und somit neue Dateien und Datenbewegungen erfasst werden.
Der Vorteil diese Methode besteht darin, dass das Durchsuchen der Datenbank sehr schnell geht, und die Suchergebnisse praktisch sofort zur Verfügung stehen.

## Installieren

  apt-get install mlocate

Es gibt auch das Pakez locate, das ist aber nicht empfohlen.
Aufpassen, dass man nicht (wie ich) beide parallel installiert. Das ist Resourcenverschwendeung...

## Aktualisierung der Datenbank

manuell:

    
