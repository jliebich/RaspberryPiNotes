## Zu den interessanten Zeiten schneller einlesen

    define di_BrustReadFahrtZurArbeit DOIF ([06:00|Mo Di Mi Do Fr]) (set FahrtZurArbeit interval 60) DOELSEIF ([09:00]) (set FahrtZurArbeit interval 300)
    define di_BrustReadFahrtNachHause DOIF ([15:00|Mo Di Mi Do Fr]) (set FahrtNachHause interval 60) DOELSEIF ([18:00]) (set FahrtNachHause interval 300)
    
    
