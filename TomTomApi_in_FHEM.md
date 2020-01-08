# TomTom-Api in FHEM einbinden

Unter https://developer.tomtom.com API-Key holen (auf "Get your Key" klicken).

Position des Heimatortes und des Arebitsplatzes bestimmen. Format in Grad (nicht Minuten / Sekunden!)
Am einfachsten unter https://mydrive.tomtom.com auf die Stelle zoomen und Wert aus der URL kopieren.

Für Kölner-Dom z.B. 50.94125,6.95801
Für Brandenburger-Tor in Berlin z.B. 52.51615,13.37759

define FahrtZurArbeit HTTPMOD https://api.tomtom.com/routing/1/calculateRoute/50.94125%2C6.95801%3A52.51615%2C13.37759/json?routeRepresentation=summaryOnly&computeTravelTimeFor=none&routeType=fastest&traffic=true&avoid=unpavedRoads&travelMode=car&key=DeinKey
attr FahrtZurArbeit enableControlSet 1
attr FahrtZurArbeit reading01JSON routes_01_summary_lengthInMeters
attr FahrtZurArbeit reading01Name Strecke
attr FahrtZurArbeit reading02JSON routes_01_summary_trafficDelayInSeconds
attr FahrtZurArbeit reading02Name Verzoegerung
attr FahrtZurArbeit reading03JSON routes_01_summary_travelTimeInSeconds
attr FahrtZurArbeit reading03Name Fahrzeit
attr FahrtZurArbeit showBody 1
attr FahrtZurArbeit stateFormat {sprintf("Fahrzeit:%d",ReadingsVal("FahrtZurArbeit","Fahrzeit",0) )}
define FileLog_FahrtZurArbeit FileLog ./log/FahrtZurArbeit-%Y.log FahrtZurArbeit

Das gleiche nochmal für die Gegenrichtung (Device-Name "FahrtNachHause")

## Zu den interessanten Zeiten schneller einlesen

    define di_BrustReadFahrtZurArbeit DOIF ([06:00|Mo Di Mi Do Fr]) (set FahrtZurArbeit interval 60) DOELSEIF ([09:00]) (set FahrtZurArbeit interval 300)
    define di_BrustReadFahrtNachHause DOIF ([15:00|Mo Di Mi Do Fr]) (set FahrtNachHause interval 60) DOELSEIF ([18:00]) (set FahrtNachHause interval 300)
    
    
