# ssh

## ssh Verbindung aufbauen

     ssh Benutzer@IP_Adresse
     
## Sicheres kopieren 
    
     scp Quelldateiname Benutzer@IP_Adresse:Pfad 

## ssh in Raspbian aktivieren
In Raspian ist SSH defaultmäßig deaktiviert. Um es zu aktivieren, muss man einfach eine Datei ohne Endung mit dem Namen ssh erstellen und in den root ordner der SD Karte schieben (also neben den Ordner overlays)

Default user: pi Default password: raspberry


## Schlüsselpaar mit und für WinSCP & Putty/Kitty erzeugen

* Im Login-Fenster Tools->Putty Key Generator wählen
* Generate klicken
* Passphrase eingeben
* "Save public key" und "Save private key" klicken um Schlüsselpaar zu speichern
* Unter /root/.ssh/ die Datei authorized_keys anlegen
* Rechte für Ordner .ssh sollte 700, für Datei authorized_keys 600 sein, Benutzer und Gruppe jeweils root
* Public Key aus PuttyGen mit Copy/Paste in Datei authorized_keys kopieren
* In Putty/Kitty: Unter Connection->Data "Auto-login username" auf root setzen und unter Connection->SSH->Auth "Private key file for authentication" den Public Key wählen, Session->Save
* In WinSCP: Im Login-Fenster; Benutzer root, kein Passwort, unter Advanced -> SSH -> Authentication -> Private Key File den Public Key wählen, Save

Note:
Für die Verwendung in OpenSSH Clients muss der Private Key im PuTTY Key Generator über "Conversions->Export OpenSSH key" noch konvertiert werden. Achtung: Dabei wird die Passphrase entfernt. 


## Passwort-Login serverseitig abschalten
Achtung: Es muss gewährleistet sein, dass man sich über seinen Key anmelden kann. Ansonsten kommt man über SSH nicht mehr auf den Server!
In der Datei:
     
     mcedit /etc/ssh/sshd_config

Müssen folgende Optionen gesetzt sein:
     
     ChallengeResponseAuthentication no
     PasswordAuthentication no
     UsePAM no

Achtung
Es muss sichergestellt sein, dass die Zeile „PubkeyAuthentication yes“ vorhanden ist. Ansonsten kommt man auch mit seinem Schlüssel nicht mehr auf den Server.

Um zu testen, ob Login über Passwort wirklich deaktiviert ist, folgendes von einem anderen Rechner ausprobieren:

     ssh -p 22 pi@192.168.0.XXX

Es sollte folgende Meldung kommen:

     Permission denied (publickey).
  
 
## Protocol V1 deaktivieren
Um nur die neuese Version 2 von SSH zuzulassen, folgenden Eintrag in

    etc/ssh/sshd_config
    
vornehmen:

    Protocol 2

Vorher prüfen, ob auch die entspechenden Schlüssel für V2 vorhanden sind:

    # HostKeys for protocol version 2
    HostKey /etc/ssh/ssh_host_rsa_key
    HostKey /etc/ssh/ssh_host_dsa_key

Änderungen wirksam werden lassen, durch Neustart des SSH daemon:
    
    /etc/init.d/sshd restart
    
