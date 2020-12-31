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

Installation dauert lange (bleibt scheibar bei 

        wireguard.ko:
        Running module version sanity check.
        - Original module
        - No original module exists within this kernel
        - Installation
        - Installing to /lib/modules/5.4.79+/kernel/net/
        
        depmod...
        
 stehen.

