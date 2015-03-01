#ssh

##ssh Verbindung aufbauen

     ssh Benutzer@IP_Adresse
     
##Sicheres kopieren 
    
     scp Quelldateiname Benutzer@IP_Adresse:Pfad 

##Schlüsselpaar mit WinSCP erzeugen

* Im Login-Fenster Tools->Putty Key Generator wählen
* Generate klicken
* Passphrase eingeben
* "Save public key" und "Save private key" klicken um Schlüsselpaar zu speichern
* Unter /root/.ssh/ die Datei authorized_keys anlegen
* Public Key aus PuttyGen mit Copy/Pate in Datei authorized_keys kopieren
* 

 
