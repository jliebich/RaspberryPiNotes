# Daemontools zur Überwachung von Daemon Prozessen

## installieren

        apt-get install daemontools
        
## Autostart

In Ordner /etc/init.d/ eine neue Datei supervise-app anlegen

        #!/bin/sh
        ### BEGIN INIT INFO
        # Provides: supervise-app
        # Required-Start: $all
        # Required-Stop:     
        # Should-Stop:       
        # Default-Start:     2 3 4 5
        # Default-Stop:      0 1 6
        # Short-Description: .
        # Description: Startet und uebwacht e_paper_info Programm
        ### END INIT INFO

        case "$1" in
        stop)
                echo "Stopping monitoring e_paper_info"
                svc -d /root
        ;;

        start)
                echo "Starting monitoring e_paper_info"
                supervise /root &
        ;;

        restart)
                echo "Continuing monitoring e_paper_info"
                svc -u /root
        ;;

        *)
                exit 1
                ;;
        esac

Init-Script aktivieren mit

        update-rc.d supervise-app defaults

Falls man es wieder deaktivieren möchte

        update-rc.d -f supervise-app  remove

## Run script
  
        #!/bin/sh
        echo Monitoring e_paper_info
        exec ./e_paper_info >> /var/log/e_paper_info.log
        
        
## Ergebnis

Program e_paper_info.log wird automatisch neu gestartet wenn es sich beendet
