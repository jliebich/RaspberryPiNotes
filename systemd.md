#Deactivate Bluetooth on system startup with systemd:

First, stop the service:

     sudo systemctl stop bluetooth.service

Then disable it:

     sudo systemctl disable bluetooth.service

Check:

     sudo systemctl status bluetooth.service
