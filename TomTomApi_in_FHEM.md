# TomTom-Api in FHEM einbinden

Unter https://developer.tomtom.com API-Key holen (auf "Get your Key" klicken).

Position des Heimatortes und des Arebitsplatzes bestimmen. Format in Grad.
Für Kölner-Dom als z.B. 50.94125,6.95801

(...)

## Zu den interessanten Zeiten schneller einlesen

    define di_BrustReadFahrtZurArbeit DOIF ([06:00|Mo Di Mi Do Fr]) (set FahrtZurArbeit interval 60) DOELSEIF ([09:00]) (set FahrtZurArbeit interval 300)
    define di_BrustReadFahrtNachHause DOIF ([15:00|Mo Di Mi Do Fr]) (set FahrtNachHause interval 60) DOELSEIF ([18:00]) (set FahrtNachHause interval 300)
    
    
