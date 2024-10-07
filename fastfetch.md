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

Die Datei unter

    /root/.config/fastfetch/config.jsonc

anlegen. Und dort auch eine Textdatei mit dem eigenen logo anlegen z.B.

    /root/.config/fastfetch/FHEM_Logo.txt

## Starten bei login

Da gibt es viele Möglivhkeiten - ich habe es an die Datei /etc/profile angehängt








    
