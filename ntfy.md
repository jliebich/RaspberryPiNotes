# ntfy Message beim Booten

Datei /etc/systemd/system/ntfy-boot.service anlegen mit folgendem Inhalt

    [Unit]
    Description=Send ntfy notification on boot
    Wants=network-online.target
    After=network-online.target

    [Service]
    Type=oneshot
    ExecStart=/usr/bin/curl -d "CO2 Raspberry wurde gestartet" https://ntfy.sh/XXXXX

    [Install]
    WantedBy=multi-user.target


Text in der Message den eigenen Bedüfnissen anpassen und XXXXX mit dem eigenen Token ersetzen

## Service aktivieren

    sudo systemctl enable ntfy-boot.service
    sudo systemctl daemon-reload

## Testen

    sudo systemctl start ntfy-boot.service

Wenn alles funktioniert, bekommst man beim nächsten Boot automatisch eine Push-Nachricht.


