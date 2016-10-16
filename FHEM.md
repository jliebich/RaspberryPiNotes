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


##Mit FHEM auf andere Hardware umziehen

Siehe auch

http://www.meintechblog.de/2014/05/intel-nuc-als-smart-home-server-fhem-on-steroids/#more-4596

In der FHEM-Konsole der "alten" Installation "backup" (ohne Anführungszeichen) eingegeben.

Im Ordner /opt/fhem/backup/ sollte dann das Backup anzutreffen sein.

Diese Datei auf die neue Hardware ins Verzeichnis /opt/fhem/backup/ (muss erst erstellt werden) kopieren.

Um das Backup abschließend zurückzuspielen, FHEM auf der neuen Hardware mit

    service fhem stop

beenden und mit 

    sudo tar -xvzf /opt/fhem/backup/FHEM-XXXXXXXX_XXXXXXXX.tar.gz -C /opt/fhem/

das Backup auf der neuen Hardware in das passende Verzeichnis entpacken

Mit

    service fhem start

FHEM wieder starten.

CUL-Stick umstecken, Reboot mit
    
    reboot
