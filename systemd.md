# systemd

systemd ist ein Hintergrundprogramm (Daemon) für Linux-Systeme, das als init-Prozess als erster Prozess (Prozess-ID 1) zum Starten, Überwachen und Beenden weiterer Prozesse dient.
systemd ist die "neue" Variante um Daemon Prozesse zu starten, Vorgänger ist SysVinit
In Debian ist systemd verfügbar sei Version Jessie.


## Übersicht zum Thema Autostart:

https://www.dexterindustries.com/howto/run-a-program-on-your-raspberry-pi-at-startup/


init.d 


## Deactivate Bluetooth on system startup with systemd:

First, stop the service:

     sudo systemctl stop bluetooth.service

Then disable it:

     sudo systemctl disable bluetooth.service

Check:

     sudo systemctl status bluetooth.service
     
     
     
## Systemd For Upstart Users:

https://wiki.ubuntu.com/SystemdForUpstartUsers

Upstart war zeitweise das Init-System inn Ubuntu, wurde aber inzwischen zugusten von systemd aufgegeben.
