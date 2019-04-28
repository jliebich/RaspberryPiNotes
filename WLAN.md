# Onboard WLAN des Raspberry Pi 3 einrichten

## WLAN-Verbindung einrichten

Prüfen ob der interne Wlan-Adapter des Raspberry Pi 3 betriebsbereit ist:

    ifconfig -a

In der Ausgabe müßte ein Netzwerk-Device wlan0 auftauchen, das ist das Onboard-Wlan.

## WLAN-Ländercode anpassen

Um WLAN-Kanäle 12 + 13 zu aktivieren:

    raspi-config

aufrufen und und unter "Internationalisation Options > Change Wi-fi Country" DE wählen.

## Verfügbare WLAN scannen

    iwlist wlan0 scan

Übersichtlichere Augabe mit

    iwlist wlan0 scan | egrep "(ESSID|IEEE)"
    
## Verbindung herstellen

Mit

    mcedit /etc/wpa_supplicant/wpa_supplicant.conf

Konfiguration anpassen:

    (SSID = WLAN-Name, PSK = WLAN-Passwort)

    network={
        ssid="MeinWLAN"
        psk="DasWlanPasswort"
    }

Netzwerkdienst neu starten um Änderung zu aktivieren

    service networking restart

Damit ist die Einrichtung der WLAN-verbindung abgeschlossen. Das System sollte nun automatisch eine Verbindung zum konfigurierten WLAN herstellen und sich via DHCP eine IP-Adresse vom Router holen.
