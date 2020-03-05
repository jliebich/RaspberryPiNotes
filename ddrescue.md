# Defekte SD Karte unter Linux kopieren

ddrescue installieren

    sudo apt-get install gddrescue

SD-Karte ins System einstecken und

    lsblk -o name,label,size,fstype,model
    
aufrufen. Name des SD-Karte merken (im folgenden sdx)

Karte unmounten mit

    umount mountpoint

Jetzt ddrescue starten

    ddrescue -d -r3 /dev/sda test.img test.logfile

