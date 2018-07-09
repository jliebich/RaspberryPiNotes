# Stromverbrauch reduzieren

## HDMI abschalten

    /opt/vc/bin/tvservice -o

Um HDMI dauerhaft abzuschalten, diese Zeile in /etc/rc.local vor "exit 0" eintragen.


## HDMI Status prüfen

    /opt/vc/bin/tvservice -s
    
Falls HDMI aktiv ist, kommt z.B. diese Meldung

    state 0x40001 [NTSC 4:3], 720x480 @ 60.00Hz, interlaced

falls inaktiv:

    state 0x120001 [TV is off]

## HDMI wieder einschalten

    /opt/vc/bin/tvservice -p

## Beim Booten ausschalten

Unter

    /etc/systemd/system
    
eine Datei namens

    hdmioff.service

anlegen mit folgendem Inhalt:

    [Unit]
    Description=Turns off HDMI on startup

    [Service]
    Type=oneshot
    ExecStart=/opt/vc/bin/tvservice -o
    RemainAfterExit=yes

    [Install]
    WantedBy=multi-user.target
    

Mit

    systemctl start hdmioff.service
    
kann man das Script ausprobieren

Mit

    systemctl enable hdmioff.service

sorgt man dafür, dass das Skript immer beim Booten ausgeführt wird

Mit

    systemctl disable hdmioff.service

kann man das wieder disablen.


