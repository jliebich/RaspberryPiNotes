# Watchdog

Der BCM2708 auf dem Raspi besitzt einen Hardware-Watchdog, der das System nach einem Absturz neu booten kann.
Um diesen zu nutzen, wird ein Kernelmodul und ein Daemon benötigt.

## Funktionsweise:
Der Daemon teilt dem Watchdog in regelmäßigen Intervallen mit, dass das System funktioniert.
Hängt das System, erhält der Watchdog keine Nachrichten mehr und setzt daraufhin das System zurück.

## Watchdog aktivieren und einrichten:
Laden des Kernelmoduls:
Für den Raspi heisst das Modul "bcm2708_wdog", für andere Systeme kann man versuchen mit lm-sensors (http://www.lm-sensors.org/) herauszufinden, die watchdog hardware zu indentifizieren. Nähere Infos dazu hier: http://www.sat.dundee.ac.uk/psc/watchdog/watchdog-configure.html#Watchdog_Device__Time

    sudo modprobe bcm2708_wdog
    echo "bcm2708_wdog" | sudo tee -a /etc/modules
    
 Installation des Deamons:
 
    sudo apt-get install watchdog
    
Konfigurationsdatei des Watchdog-Daemon anpassen

    sudo nano /etc/watchdog.conf
    
Bei folgenden beiden Zeilen Raute-Zeichen am Anfang der Zeile entfernen:

    watchdog-device        = /dev/watchdog
    max-load-1             = 24

"max-load-1" ist der maximal erlaubte "1 minute average load". Ein "load" über diesem Wert führt zum Reboot.
Default-Wert ist 0 = deaktiviert. Ein Wert von 1 kann man bei einem Single-Core-System grob gesehen als 100% Auslastung interpretieren. Im Internet findet man die Empfehlung mindestens einen Wert von 5*Anzahl_Cores zu verwenden.

"watchdog-device" ist der Device-Name des Hardware-Watchdogtimers. 

Watchdog starten:

    sudo /etc/init.d/watchdog restart
    
## Syslog checken

    grep watchdog /var/log/syslog
    
Ausgabe (Beispiel):

    Oct 16 18:29:16 raspberrypi kernel: [167854.591959] bcm2708 watchdog, heartbeat=10 sec (nowayout=0)
    Oct 16 18:34:07 raspberrypi watchdog[5168]: starting daemon (5.12):
    Oct 16 18:34:07 raspberrypi watchdog[5168]: int=1s realtime=yes sync=no soft=no mla=24 mem=0
    Oct 16 18:34:07 raspberrypi watchdog[5168]: ping: no machine to check
    Oct 16 18:34:07 raspberrypi watchdog[5168]: file: no file to check
    Oct 16 18:34:07 raspberrypi watchdog[5168]: pidfile: no server process to check
    Oct 16 18:34:07 raspberrypi watchdog[5168]: interface: no interface to check
    Oct 16 18:34:07 raspberrypi watchdog[5168]: test=none(0) repair=none(0) alive=/dev/watchdog heartbeat=none temp=none to=root no_act=no
    Oct 16 18:34:07 raspberrypi watchdog[5168]: cannot set timeout 60 (errno = 22 = 'Invalid argument')
    Oct 16 18:34:07 raspberrypi watchdog[5168]: hardware wartchdog identity: BCM2708


## Testen ob Daemon läuft

    ps -Af | grep watchdog
    
Ausgabe (Beispiel):

    root      5168     1  0 18:34 ?        00:00:01 /usr/sbin/watchdog
    
## Watchdog testen

Diverse Scripts mit denen man den Watchdog testen kann:
    
http://www.sat.dundee.ac.uk/psc/watchdog/watchdog-examples.tgz
