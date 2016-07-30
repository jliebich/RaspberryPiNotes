#Letsencrypt Zertifikat erneuern

Webserver stoppen

    service nginx stop

Letsencrypt aufrufen

    ./letsencrypt-auto --renew-by-default certonly -d domain.de
  
Im Dialog "Automatically use a temporary webserver (standalone)" wählen

Prüfen, ob angegebener Pfad, in den das neue Zertifikat gespeichert ist mit der Angabe in der nginx-Konfiguration übereinstimmt

Webserver wieder starten

    service nginx start



