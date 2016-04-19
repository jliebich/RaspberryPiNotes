#Datum und Uhrzeit Themen

##Zeit von Hardwareuhr lesen

     hwclock -r
     
##Zeit der Hardwareuhr anhand der Systemzeit setzen

    hwclock -w
    
##Datum/Uhrzeit über NTP holen (manuell anstoßen)

    ntpd -q -g
    
Die Option -g bedeutet, dass ntpd auch synchronisiert, wenn die Zeit mehr als 1000 Sekunden abweicht. Die Option -q bedeutet, dass ntpd nur einmal ausgeführt wird.

##Hardwareuhr mit NTP Uhrzeit synchronisieren
    https://raspberrypi.stackexchange.com/questions/9791/how-can-i-automatically-update-the-hwclock-with-ntp-when-i-have-internet-connect
