# Swap

## Status anzeigen

    service dphys-swapfile status   

## Speicherauslastung anzeigen
Kurzform:

    free
Graphisch schöner:

    htop
    
## Swap an- / ausschalten

    swapoff -a
    
bzw.

    swapon -a

Vorsicht! Das einschalten des swaps mit neuer Dateigröße hat bei mir (scheinbar?) nicht funktioniert. Nach einem Reboot war das System zunächst EXTREM langsam - hat sich dann aber wieder gefangen. Vermutlich dauert das anlegen eines neuen Swapfiles (bei mir 1GB) sehr lange.
