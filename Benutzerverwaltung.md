# Benutzerverwaltung

## Alle Unix User anzeigen

    cat /etc/passwd

n dieser Liste stehen ALLE Unix Users. Das /bin/sh bedeutet, dass dieser User sich auch einloggen kann, also eine Shell öffnen könnte, das /bin/false bedeutet, dass der Benutzer sich keine Shell holen könnte.

## Eingeloggte Shell Benutzer anzeigen

     w

## Passwort ändern
Eigenes Passwort ändern:

     passwd
                                
Passwort eines anderen Benutzers ändern:
                                
     sudo passwd BENUTZERNAME 
