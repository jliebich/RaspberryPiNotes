# Bluetooth
Status

    systemctl status bluetooth

und auch

    hciconfig -a
    

Enable

    sudo systemctl start bluetooth

Service stoppen

    sudo systemctl stop bluetooth

# /boot/config.txt

Man kann in /boot/config.txt den internen Blootooth-Adapter auch deaktivieren.
Habe meherer Vasrianten gefunden:

    # Disable internal BT
    dtoverlay=pi3-disable-bt

# /etc/modprobe.d/raspi-blacklist.conf
Man kann auch in /etc/modprobe.d/raspi-blacklist.conf blcklisten

    # Disable bluetooth
    blacklist btbcm
    blacklist hci_uart


