# Syslog an einen Syslog-Server senden

Synology-NAS als Sylog Server einrichten mit Paket "Protokoll-Center" (muss nachistalliert werden)

Am Pi die Datei /etc/rsyslog.conf editieren und am Schluss folgende Zeilen einfügen

    # Send log to remote syslog server using UDP (for TCP add ad second "@" after the first one)
    *.* @192.168.0.11:514
    
wobei die IP die IP-Adresse der Synlogy NAS ist. Der Port bleibt 514.

Mit

    service rsyslog restart

den Service noch neustarten und schon müsste man die ersten Logs zu sehen bekommen. Praktisch ist, dass hier bereits auch der komplette Bootlog gesendet wird, was oft beim debuggen behilfreich ist. Übrigens keine Angst, das lokale Syslog File wird weiterhin fleißig gefüllt, die Meldungen werden nur zusätzlich an den eingetragenen Server gesendet.

Viel Spaß beim nachmachen!
