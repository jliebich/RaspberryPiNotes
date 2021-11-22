# Diverses zu den Logdatein

Pfad zu den logs ist `/var/log`

Zumindest auf dem Raspberry Pi Stretch von 11/2018 werden sowohl journalctl als auch rsyslog ausgeführt.
Dies bedeutet, dass die Protokollinformationen doppelt geloged werden!

journalctl ist das modernere System, rsyslog das ältere.
Um rsyslog-Datein zu "rotieren" wird das Tool "logrotate" benötigt.

Es ist also u.U. sinnvoll rsyslog zu deaktivieren.

Das journalctl-Protokoll auf einem Pi wird angeblic standardmäßig in einem nicht-permanenten Speicher gehalten, sondern unter `/run/log/journal` (`/run` ist ein tmpfs Filesystem und somit im RAM, das kann man mittels `mount | grep tmpfs` sehen)

Um journalctl abzuspeichern folgendes tun:

    mkdir -p /var/log/journal systemd-tmpfiles --create --prefix /var/log/journal
 
und dann das System neu starten. Dadurch wird das journalctl-Protokoll dauerhaft gespeichert.

Das funktioniert, weil der Standard-Speichermodus von journald auto ist, was bedeutet, dass die Protokolle im Speicher gehalten werden, solange /var/log/journal nicht existiert - und das ist im Basis-Image angeblich nicht der Fall.

Ich habe allerdings da andere Erfahrungen: Bei meinen Raspis gibt es teilwiese ein /var/log/journal...


# journal konfigurieren

Einstellungen (wie z.B. die Größe) zu journalctl sind in

    /etc/systemd/journald.conf

Interessante Einstellungen sind hier `SystemMaxUse`, `SystemKeepFree`, etc.

Diverse Befehle für den Service:

`systemctl status systemd-journald` zeigt an, ob der Dienst läuft und gibt gegebenenfalls zusätzliche Informationen.

`systemctl start systemd-journald` startet den Dienst

`systemctl stop systemd-journald` stoppt den Dienst.

`systemctl restart systemd-journald` startet den Dienst neu.

`systemctl reload systemd-journald` lädt die Konfiguration des Dienstes neu, wenn möglich, beendet ihn aber nicht (daher besteht keine Gefahr einer Dienstunterbrechung oder einer Unterbrechung der laufenden Verarbeitung, aber der Dienst läuft möglicherweise mit einer veralteten Konfiguration weiter).

`systemctl force-reload systemd-journald` lädt die Konfiguration des Dienstes neu, wenn dies möglich ist, und startet den Dienst neu, wenn dies nicht möglich ist (so ist gewährleistet, dass der Dienst die aktuelle Konfiguration verwendet, aber dies kann zu einer Unterbrechung führen).

# journal anzeigen

Dem Journal live folgen

    journalctl -f



# rsyslog deaktivieren

Wenn man rsyslog nicht benötigt, weil man z.B. wie oben beschrieben das journalctl-Protokoll persistent speichert, dann kann man es einfach deinstallieren mit

    apt --autoremove purge rsyslog
    
 Bei mir ist auf allen Raspis rsyslog deaktiviert.

    
# Größenbegrenzung von Text-Log-Dateien mit logrotate (NICHT für system.journal!)

Die Speicherung der Textprotokolle, die von rsyslog erstellt werden, kann mit logrotate kontrolliert werden

Es rollt die Dateien um, komprimiert sie möglicherweise und verwirft sie je nach Volumen und/oder Alter.

Traditionell wird logrotate von cron ausgeführt, aber das aktuelle Raspbian-System verwendet einen systemd-Timer.

Siehe `/etc/systemd/system/timers.target.wants/logrotate.timer`

Mit `systemctl status logrotate.timer` kann man überprüfen ob er aktiviert ist


# Syslog an einen Syslog-Server senden

Synology-NAS als Sylog Server einrichten mit Paket "Protokoll-Center" (muss nachistalliert werden)

Am Pi die Datei /etc/rsyslog.conf editieren und am Schluss folgende Zeilen einfügen

    # Send log to remote syslog server using UDP (for TCP add ad second "@" after the first one)
    *.* @192.168.0.11:514
    
wobei die IP die IP-Adresse der Synlogy NAS ist. Der Port bleibt 514.

Mit

    service rsyslog restart

den Service noch neustarten und schon müsste man die ersten Logs zu sehen bekommen.
Auch der komplette Bootlog wird gesendet, was oft beim debuggen behilfreich ist.
Das lokale Syslog File wird weiterhin gefüllt, die Meldungen werden nur zusätzlich an die NAS gesendet.

# rngd-Ausgabe aufiltern

Die rngd-Protokolle sind ziemlich überflüssig und "müllen" das syslog voll.
Wir können rsyslog dazu bringen, sie in eine dedizierte Protokolldatei zu schreiben (sagen wir /var/log/rnd.log):

Erzeugen einer /etc/rsyslog.d/rng.conf


    # redirect rngd output on Raspberry Pi Buster
    # distribution into /var/log/rng.log to
    # avoid cluttering /var/log/syslog

    # redirect all messages coming from rng
    :programname,startswith,"rng" /var/log/rng.log

    # and discard them for the following rsyslog
    # actions
    :programname,startswith,"rng" stop

gefolgt von einem Neustart des rsyslog-Dienstes:

    sudo systemctl restart rsyslog.service
