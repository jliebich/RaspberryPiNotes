# fail2ban

Fail2ban für nextcloud siehe:

https://www.ksite.de/nextcloud-mit-fail2ban-absichern/

## Logfile
     
     /var/log/fail2ban.log
     
## Konfiguration

### Filter

Filter enthalten reguläre Ausdrücke fü die Log-Datei der entsprechenden Anwendung.
Sie liegen unter:

     /etc/fail2ban/filter.d/
     
Für nextcloud z.B. eine Datei nextclod.conf anlegen mit folgendem Inhalt:
     
     [Definition]
     failregex = ^{"reqId":".*","remoteAddr":".*","app":"core","message":"Login failed: '.*' \(Remote IP: '<HOST>'\)","level":2,"time":".*"}$^{"reqId":".*","level":2,"time":".*","remoteAddr":".*","app":"core".*","message":"Login failed: '.*' \(Remote IP: '<HOST>'\)".*}$
     ignoreregex =
     
        
     
### Jails

Filter werden erst aktiv, wenn es einen passenden "Jail" dafür gibt.
Eigene Jails sollte man NICHT in die Datei /etc/fail2ban/jail.conf eintragen, sondern unter

     /etc/fail2ban/jail.d/
     
Für nextcloud z.B. eine Datei nextclod.conf anlegen mit folgendem Inhalt:

     [nextcloud]
     enabled = true
     port = 80,443
     protocol = tcp
     filter = nextcloud
     maxretry = 3
     logpath = /var/www/owncloud/data/nextcloud.log
     
     
## Benachrichtigungen von fail2ban als Telegram Message

https://blog.mypapit.net/2015/08/how-to-send-fail2ban-notification-with-telegram-telegram-cli.html

     
     
