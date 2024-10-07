# fastfetch
## herunterladen
  
herunterladen mit wget (in Ordner home/pi, besser nicht in /root, da kam bei mir eine Fehlermeldung die aber scheinbar keine Auswirkung hatte)

Für 64-bit 

    wget https://github.com/fastfetch-cli/fastfetch/releases/download/X.X.X/fastfetch-linux-aarch64.deb
    
Für 32 Bit
    
    wget https://github.com/fastfetch-cli/fastfetch/releases/download/X.X.X/fastfetch-linux-armv7l.deb

## installieren

    apt install ./fastfetch-linux-XXXXXX.deb

Die Dateien befinden sich dann unter

    /usr/bin/fastfetch
    /usr/share/fastfetch
    /usr/share/fastfetch/presets

## Vorlage anlegen



    
