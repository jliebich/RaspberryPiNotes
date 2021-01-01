# Wireguard

Moderner Ersatz für OpenVPN

## Installation auf Raspberry Pi:

Da WireGuard wohl eng mit dem Kernal verbunden ist, ist m.E. ein

    rpi-update

Vor der eigentlichen Installation empfehlenswert.
Dann dieser Anleitung folgen:


    https://www.sigmdel.ca/michel/ha/wireguard/wireguard_03_en.html
    
Andere Anleitung holen sich das WireGuard Paket von Debian (nicht von Raspbian).
Das ist veraltet, da WireGuard package im "Raspbian Testing repository" von Buster enthalten ist

## Neuen User anlegen

Beispiel mit User "zenfone"

    cd wg_config
    ./user.sh -a zenfone
    ls users
    
## Infos zu einem User anzeigen

Beispiel mit User "zenfone"

    ./user.sh -v zenfone

Es gibt immer 2 Config-Files pro User und zwar client.conf und client.all.conf.

client.conf ist die "Split" Konfiguration. Dort werden nur Zugriffe auf das lokale Netzwerk (192.168.0.XXX) getunnel, andere Adressen werden NICHT getunnelt.

client.all.conf ist die "All" Konfiguration  (AllowedIPs: 0.0.0.0/0). Hier werden alle Zugriffe getunnelt.

## Einrichten Android-Geräte

Am besten über den QR-Code

## Einrichten Windows-Notbook

Am besten über die .conf Dateien. Kann man z.B. über WinSCP vom Raspi runterholen 

## Statistik 

    wg
 
 zeigt eine Zusmmenfassung der Konfiguarion, wann die letzte Verbindung war und wieviel Daten übertragen wurden
 

    
