#Updateprozess

    sudo apt-get update

Followed by:

    sudo apt-get upgrade

##Firmwareupdate:

Updateskript installieren:

http://raspberrypiguide.de/howtos/raspberry-pi-firmware-update/

Update durchführen:

    sudo rpi-update

und Neustart via

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

##Automatische Sicherheits-Updates

Verwendung des Pakets Unattended-Upgrades 

http://www.elektronik-kompendium.de/sites/raspberry-pi/2002101.htm

##Release-Upgrade von Wheezy nach Jessie

Wechsel von Wheezy nach Jessie wird durch rpi-update NICHT durchgeführt!

https://www.datenreise.de/raspberry-pi-raspbian-linux-wheezy-jessie-upgrade/

Dieses Update hat bei mir zu einem unbenutzbaren System geführt (z.B. keine Netzwerkverbindung mehr).
Habe es wieder rückgängig gemacht...
