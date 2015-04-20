#ssh

##ssh Verbindung aufbauen

     ssh Benutzer@IP_Adresse
     
##Sicheres kopieren 
    
     scp Quelldateiname Benutzer@IP_Adresse:Pfad 

##Schlüsselpaar mit und für WinSCP & Putty/Kitty erzeugen

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
 
