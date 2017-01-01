#Letsencrypt Zertifikat erneuern

Webserver stoppen

    service nginx stop

Letsencrypt aufrufen

    ./letsencrypt-auto --renew-by-default certonly -d domain.de
  
Im Dialog "Automatically use a temporary webserver (standalone)" wählen

Prüfen, ob angegebener Pfad, in den das neue Zertifikat gespeichert ist, mit der Angabe in der nginx-Konfiguration übereinstimmt

Bei mir gibt es in der nginx-Konfig zwei Einträge

    /etc/letsencrypt/live/domain.de/fullchain.pem
    /etc/letsencrypt/live/domain.de/privkey.pem
    
Dies sind Links auf

    /etc/letsencrypt/archive/domain.de/fullchainX.pem
    /etc/letsencrypt/archive/domain.de/privkeyX.pem

die offensichtlich automatisch aktualisiert werden (X ist eine Nummer die hochgezählt wird)

Webserver wieder starten

    service nginx start



