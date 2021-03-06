# Letsencrypt Zertifikat erneuern

Webserver stoppen

    service nginx stop

In Installationsverzeichnis wechslen - bei mir:

    cd /home/letsencrypt

Sicherstellen das in der Firewall (iptables) der Zugriff von "anywhere" auf HTTPS- UND den HTTP-Port erlaubt ist -siehe auch https://community.letsencrypt.org/t/lets-encrypt-and-firewall-rules/18641

Mein Eintrag in /etc/network/iptables sieht dafür so aus:
```Shell
#HTTP generell erlauben  - nötig für Erneuerung Letsencrypt-Zerifikat
-A INPUT -p tcp -m state --state NEW -m tcp --dport 80 -j ACCEPT
#HTTPS generell erlauben - nötig für Erneuerung Letsencrypt-Zerifikat
-A INPUT -p tcp -m state --state NEW -m tcp --dport 443 -j ACCEPTPT
```
Änderungen übernehmen:

    iptables-restore /etc/network/iptables

Letsencrypt aufrufen (letsencrypt-auto wurde in certbot-auto umbenannt):

    ./certbot-auto --renew-by-default certonly -d domain1.de -d domain2.de

Habe mir dafür ein Script angelegt (Aufruf ./my-renew.sh)

Mit mehreren -d können mehrere Domains angegeben werden! Es wird trotzdem nur ein Zertifikat erstellt, dass dann aber für alle angegebenen Domains gültig ist.
Nach obigem Aufruf wird das Prrogramm zunächst aktualisiert.
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

Allgemeinen Zugriff auf HTTP und HTTPS ggf. wieder verbieten.
Dafür den entsprechenden Eintrag (siehe oben) in /etc/network/iptables auskommentieren:

```Shell
#HTTP generell erlauben  - nötig für Erneuerung Letsencrypt-Zerifikat
#-A INPUT -p tcp -m state --state NEW -m tcp --dport 80 -j ACCEPT
#HTTPS generell erlauben - nötig für Erneuerung Letsencrypt-Zerifikat
#-A INPUT -p tcp -m state --state NEW -m tcp --dport 443 -j ACCEPT
```
 

Änderungen übernehmen:

    iptables-restore /etc/network/iptables

Webserver wieder starten

    service nginx start


## Trobleshooting

Meldet das Script am Ende folgendes, dann wurde vermutlich vergessen, den Webserver zu stoppen:

    Problem binding to port 443: Could not bind to IPv4 or IPv6.
