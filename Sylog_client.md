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
