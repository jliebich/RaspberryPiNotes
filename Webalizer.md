#Webalizer
#Config
 unter etc/webalizer
#Zugriff absichern

[http://byggvir.de/2012/01/25/webalizer-statistiken-absichern/](http://byggvir.de/2012/01/25/webalizer-statistiken-absichern/) 

In Datei

/etc/apache2/sites-enabled/000-default 

    <Directory "/srv/www/htdocs/webalizer">
    AuthType Basic // HTTP Basic Authentication (Digest wäre die andere Option)  
    AuthName "Webalizer Statistics"
    AuthUserFile /etc/apache2/httpusers // hier stehen die Passwörter
      Options None
      AllowOverride None //  .htaccess-Dateien ignorieren   
      Require valid-user // alle Benutzer zulassen
      Allow from 192.168.0.8 // Erlaubt Zugriff von lokalem Rechner
    </Directory>  
    
    #Mein Eintrag für webalizer
    <Directory "/var/www/webalizer/">
    AuthType Basic
    AuthName "Webalizer Statistics"
    AuthUserFile /etc/apache2/httpusers
    Require valid-user
    Options +FollowSymlinks
    AllowOverride None
    Order allow,deny
    Allow from all
    </Directory>
