# Defekte SD Karte unter Linux kopieren

ddrescue installieren

    sudo apt-get install gddrescue

SD-Karte ins System einstecken und

    lsblk -o name,label,size,fstype,model
    
aufrufen. Name des SD-Karte merken (im folgenden sdx)

Karte unmounten mit

    umount mountpoint

Jetzt ddrescue starten

    ddrescue -d -r3 /dev/sdx test.img test.log

Ergebnis vom Lesevorgang steht jetzt in test.img

Jetzt das Ziellaufwerk einlegen und test.img zurückschreiben
Man könnte es mit dd mach, aber ddrescue hat eine nettere Fortschrittsanzeige...

    ddsercue -f test.img /dev/sdx restore.log

Jetzt noch fsck ausführen um zu prüfen, ob alles gut funktioniert hat:

    sudo fsck.ext4 -v -f -c /dev/sdax

