#Letsencrypt Zertifikat erneuern

Webserver stoppen

    service nginx stop

Letsencrypt aufrufen

    ./letsencrypt-auto --renew-by-default certonly -d domain.de
  
Im Dialog "Automatically use a temporary webserver (standalone)" wählen

Webserver wieder starten

    service nginx start



