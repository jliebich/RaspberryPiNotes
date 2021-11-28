# Stromzähler

## Setup:

- ELV Homematic Zählersensor-Sendeeinheit Strom/Gas HM-ES-TX-WM (Artikel-Nr: 140143 )
- ELV Homematic Energiesensor für Smart Meter ES-IEC (Artikel-Nr: 142148 )
- Stromzähler NORAX3D

## Anleitungen

- Handbuch Nordax 3D: Handbuch_Norax3D.pdf
- FHEM Wiki zum M-ES-TX-WM (ES-IEC Sensor ist hier nicht erwähnt) https://wiki.fhem.de/wiki/HM-ES-TX-WM_Z%C3%A4hlersensor_f%C3%BCr_Strom-_und_Gasz%C3%A4hler
- Liste der unterstützen Stromzähler: 142148_liste_data.pdf NORDAX 3D ist in der Liste erwähnt, müsste also funktionieren

## Protokoll

Laut Anleitung hat die optische Schnittstelle des NORAX3D folgende Eigenschaften

- 9600 Baud 8N1
- Protokoll: SML + COSEM

Es gibt einen "Baisbetrieb" und einen "Erweiterten Betrieb - Herstellerbetrieb"
Im Basisbetrieb wird Obis 1.8.0 = "Entnommene Energie" unterstützt - das ist auch in 142148_liste_data.pdf erwähnt
Im "Erweiterten Betrieb" werden auch

- Momentane Leistung Obis 16.7.0
- Phasenspannung L1 Obis 32.7.0
- Phasenspannung L2 52.7.0
- Phasenspannung L3 72.7.0
- Phasenstrom 1 31.7.0
- Phasenstrom 2 51.7.0
- Phasenstrom 3 71.7.0
- 
erwähnt, allerdings ohne direkter Angabe einer Obis-Nummer - diese stehen aber in einem anderen Kontext später in der Anleitung.

Der Wechsel zwischen den beiden Protokollarten geschied durch den "InF"-Paramter.
Zitat auf Bedienungsanleitung:
"Aktivierungsbetrieb der Herstellerdaten im Telegramm am INFO-Port. Es wird das ON-Symbol angezeigt, wenn die Funktion ON ist (erweiterte Daten) oder OFF-Symbol, wenn die Funktion aus ist (Daten in der grundsätzlichen Version). Änderung des ON/OFF-Parameters durch langes Lichtsignal.



