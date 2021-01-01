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
    wg_config $ ls users
    
## Infos zu einem User anzeigen

Beispiel mit User "zenfone"

    ./user.sh -v zenfone
