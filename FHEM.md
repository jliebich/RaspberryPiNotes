#FHEM
##FHEM-Befehl in der Bash ausführen

     perl fhem.pl <Port> "<Befehl>" 
     
Beispiel

     perl fhem.pl 7072 "version" 
     
##FHEM Server starten/stoppen

      service fhem start

bzw.

      /etc/init.d/fhem stop

Ein "restart" ist merkwürdigerweise nicht möglich.
