#MySQL-Passwort vergessen
Die Datei
 
      /etc/mysql/debian.cnf

öffen. Hier steht das MySQL-Passwort für den speziellen Benutzer „debian-sys-maint“.
Mit dem kann man direkt das Passwort aktualisieren:

        mysql -u debian-sys-maint -p

und anschließend:

    update user set password=PASSWORD("xyz123") where user='root'; 

