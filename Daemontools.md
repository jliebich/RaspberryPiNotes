# Daemintools zur Überwachung von Daemon Prozessen

## installieren

        apt-get install daemontools
        
## Autostart

In Datei /etc/init.d/

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
        
  
