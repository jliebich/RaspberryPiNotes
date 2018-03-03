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
