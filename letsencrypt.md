# Letsencrypt Zertifikat erneuern

Webserver stoppen

    service nginx stop

In Installationsverzeichnis wechslen - bei mir:

    cd /home/letsencrypt

Sicherstellen das in der Firewall (iptables) der Zugriff von "anywhere" auf HTTPS-Port erlaubt ist -siehe auch https://community.letsencrypt.org/t/lets-encrypt-and-firewall-rules/18641

Mein Eintrag in /etc/network/iptables sieht dafür so aus:

    #HTTPS generell erlauben - nötig für Erneuerung Letsencrypt-Zerifikat
    -A INPUT -p tcp -m state --state NEW -m tcp --dport 443 -j ACCEPTPT

Letsencrypt aufrufen 

    ./letsencrypt-auto --renew-by-default certonly -d domain.de

Daraufhin wird das Prrogramm zunächst aktualisiert.
Achtung: Es dauert sehr lange, bis der Schritt "Installing Python packages..." abgeschlossen ist!

Im Dialog "Automatically use a temporary webserver (standalone)" wählen

Prüfen, ob angegebener Pfad, in den das neue Zertifikat gespeichert ist, mit der Angabe in der nginx-Konfiguration übereinstimmt

Bei mir gibt es in der nginx-Konfig zwei Einträge

    /etc/letsencrypt/live/domain.de/fullchain.pem
    /etc/letsencrypt/live/domain.de/privkey.pem
    
Dies sind Links auf

    /etc/letsencrypt/archive/domain.de/fullchainX.pem
    /etc/letsencrypt/archive/domain.de/privkeyX.pem

die offensichtlich automatisch aktualisiert werden (X ist eine Nummer die hochgezählt wird)

Allgemeinen Zugriff auf HTTPS ggf. wieder verbieten.
Dafür den entsprechenden Eintrag (siehe oben) in /etc/network/iptables auskommentieren:
    
    #HTTPS generell erlauben - nötig für Erneuerung Letsencrypt-Zerifikat
    #-A INPUT -p tcp -m state --state NEW -m tcp --dport 443 -j ACCEPT

Webserver wieder starten

    service nginx start



