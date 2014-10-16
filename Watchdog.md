#Watchdog

Der auf dem Raspberry Pi verbaute BCM2708 von Broadcom verfügt standardmäßig bereits über einen Hardware-Watchdog, der das System im Problemfall neu starten kann. Um diesen zu nutzen, wird ein Kernelmodul und ein Daemon benötigt.

##Funktionsweise:
Der Daemon teilt dem Watchdog in regelmäßigen Intervallen mit, dass das System funktioniert. Kommt es nun zu einem Problem und das System hängt sich auf, erhält der Watchdog keine Nachrichten mehr und setzt daraufhin das System zurück.

##Watchdog aktivieren und einrichten:
Laden des Kernelmoduls und anschließende Installation des Deamons:
