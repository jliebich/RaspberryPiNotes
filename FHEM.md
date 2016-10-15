#FHEM
##Installationsverzechnis von FHEM

     /opt/fhem 

##FHEM-Befehl in der Bash ausführen

     perl fhem.pl <Port> "<Befehl>" 
     
Beispiele

     perl fhem.pl 7072 "version" 
     
     perl fhem.pl 7072 "update check" 

     perl fhem.pl 7072 "update"
     
     perl fhem.pl 7072 "shutdown restart"

##FHEM Server starten/stoppen

      service fhem start

bzw.

      service fhem stop

Ein "restart" ist merkwürdigerweise nicht möglich.
