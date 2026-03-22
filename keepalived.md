# Mein keepalived Setup

## Install

Um automatisch auf das Backup-Pihole-Sysetm zu wechseln falls die Hauptinstallation ausgefallen ist habe ich bei mir folgendes installiert:

    apt install keepalived

auf Master (192.168.0.37) und Backup-System (192.168.0.9)

Und

    apt install dnsutils

auf Master-System um dig nutzen zu können

Die gewählte virtuelle Adresse ist 192.168.0.10


## Konfig auf Master


    global_defs {
    # Erlaubt das Ausführen von Scripten durch diesen User
    script_user keepalived_script
    # Deaktiviert die Sicherheitswarnung, da wir den User oben definiert haben
    enable_script_security
    max_auto_priority
    }

    vrrp_script check_pihole {
        script "/usr/local/bin/check_pihole.sh"
        interval 3    # Alle 2 Sek. prüfen
        weight -20    # Wenn Script Fehler (1) liefert, sinkt Prio von 100 auf 80
    }

    vrrp_instance VI_1 {
        state MASTER
        interface eth0           # Prüfe mit 'ip a', ob dein Interface so heißt
        virtual_router_id 51     # Muss auf beiden Geräten identisch sein!
        priority 100             # Höhere Zahl gewinnt
        advert_int 1

    virtual_ipaddress {
        192.168.0.10/24    # Die IP für deine Fritzbox
    }

    track_script {
        check_pihole
    }

Und folgendes Script unter /usr/local/bin/check_pihole.sh anlegen:

    #!/bin/bash

    # - @127.0.0.1: Frag den lokalen Pi-hole
    # - +short: Wir wollen keine langen Texte, nur die IP (spart Zeit)
    # - +tries=1: Nicht mehrfach versuchen
    # - +time=1: Nach 1 Sekunde abbrechen, wenn keine Antwort kommt
    /usr/bin/dig +short +tries=1 +time=1 @127.0.0.1 google.com > /dev/null 2>&1

    if [ $? -eq 0 ]; then
      exit 0 # Pi-hole hat geantwortet
    else
      exit 1 # Pi-hole ist tot oder filtert gerade nicht
    fi

Gebe dem Script die richtigen Besitzer

    sudo chown keepalived_script:keepalived_script /usr/local/bin/check_pihole.sh

Stelle sicher, dass es ausführbar ist

    sudo chmod 755 /usr/local/bin/check_pihole.sh

## Konfig auf Slave

    vrrp_instance VI_1 {
      state BACKUP
      interface eth0
      virtual_router_id 51     # Muss auf beiden Geräten identisch sein!
      priority 90              # Kleiner als 100, aber größer als (100-20=80)
      advert_int 1

      virtual_ipaddress {
          192.168.0.10/24
      }
    }

