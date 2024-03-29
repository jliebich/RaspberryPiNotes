# Updateprozess

    sudo apt-get update

Followed by:

    sudo apt-get upgrade

## Firmwareupdate:

Updateskript installieren:

        sudo wget https://raw.github.com/Hexxeh/rpi-update/master/rpi-update -O /usr/bin/rpi-update
        sudo chmod +x /usr/bin/rpi-update
        
siehe auch http://raspberrypiguide.de/howtos/raspberry-pi-firmware-update/

Update durchführen:

    sudo rpi-update

Falls eine Meldung wie:

    Partition size XXXM may not be sufficient for new Pi4 files
    This could result in a system that will not boot.
    256M FAT partition is recommended. Ensure you have a backup if continuing.

kommt muss die boot partition vergrößert werden, siehe hierzu https://learn.adafruit.com/resizing-raspberry-pi-boot-partition/edit-partitions

Neustart via

    sudo reboot

Anzeige der installierten Version mit

    uname -a

Aufräumen nach erfolgreichem Firmwareupdate:
Firmwareupdate installiert häufig auch eine neue Kernelversion - die alte Version wird dabei als Bachkup behalten.
Um diese alten Kernelversionen zu entfernen, kann man mit

    sudo dpkg -l | grep linux-image
    
ermitteln, welche noch vorhanden sind. Es liefert z.B.

    ii  linux-image-2.6.32-22-generic   2.6.32-22.35   Linux kernel image for  version 2.6.32 on x86
    ii  linux-image-2.6.32-23-generic   2.6.32-23.37   Linux kernel image for  version 2.6.32 on x86
    ii  linux-image-generic             2.6.32.23.24  

In diesem Fall ist die Version 2.6.32-23-generic die aktuelle Version und die Version 2.6.32-22-generic könnte entfernt werden. Das Paket linux-image-generic muss immer installiert bleiben!

Entfernen des alten Kernel erfolgt durch

    sudo apt-get remove --purge linux-image-2.6.32-22-generic
    
Sinnvoll ist es anschliessend noch

    sudo apt-get autoremove
    
um von dem alten Kernel verbleibende Reste auch noch zu entfernen.

## Automatische Sicherheits-Updates

Verwendung des Pakets Unattended-Upgrades 

http://www.elektronik-kompendium.de/sites/raspberry-pi/2002101.htm

Intsallation so anpassen, sonst gehts nicht:

https://raspberrypi.stackexchange.com/questions/72022/configuring-unattended-upgrades-on-raspbian-stretch


## Release-Upgrade von Stretch nach Buster

https://pimylifeup.com/upgrade-raspbian-stretch-to-raspbian-buster/
