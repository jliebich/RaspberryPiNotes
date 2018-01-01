# fail2ban

Fail2ban für owncloud7 siehe:

http://debianforum.de/forum/viewtopic.php?f=37&t=150519

## Logfile
     
     /var/log/fail2ban.log
     
## Konfiguration

### Filter

Filter enthalten reguläre Ausdrücke fü die Log-Datei der entsprechenden Anwendung.
Sie liegen unter:

     /etc/fail2ban/filter.d/
     
### Jails

Filter werden erst aktiv, wenn sie in folgender Datei erwähnt sind:

     /etc/fail2ban/jail.conf
     
     
