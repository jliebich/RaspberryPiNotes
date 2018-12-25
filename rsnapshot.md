# Backup mit rsnapshot

Siehe
https://dvpizone.wordpress.com/2014/03/08/using-rsnapshot-with-a-raspberry-pi-to-create-a-backup-device/

## Installieren

    apt-get install rsnapshot

## Konfig-Datei

    /etc/rsnapshot.conf
    
## FAQ

https://rsnapshot.org/faq.html

Für mich interessant war folgnder Eintrag:

### My rsnapshot setup seems to eat the processor on the machines I’m backing up from. How can I prevent this?

rsnapshot itself is a low-overhead program, but rsync can drive processor utilization uncomfortably high. To address this, tell your rsync to run with high nice and ionice values, like 10 and -c3 respectively.

Depending on how rsync was packaged for your system, your installation may have an /etc/default/rsync file. If it does, set RSYNC_NICE and RSYNC_IONICE as recommended. Then restart the rsync daemon. You should notice a difference immediately.

Aber Achtung: Im Kopf von /etc/default/rsync steht:
    This file is only used for init.d based systems!
    If this system uses systemd, you can specify options etc. for rsync
    in daemon mode by copying /lib/systemd/system/rsync.service to
    /etc/systemd/system/rsync.service and modifying the copy; add required
    options to the ExecStart line.



