# Stromzähler

## Setup:

- ELV Homematic Zählersensor-Sendeeinheit Strom/Gas HM-ES-TX-WM (Artikel-Nr: 140143 )
- ELV Homematic Energiesensor für Smart Meter ES-IEC (Artikel-Nr: 142148 )
- Stromzähler NORAX3D

## Anleitungen

- Handbuch Nordax 3D: Handbuch_Norax3D.pdf
- [FHEM Wiki zum M-ES-TX-WM](https://wiki.fhem.de/wiki/HM-ES-TX-WM_Z%C3%A4hlersensor_f%C3%BCr_Strom-_und_Gasz%C3%A4hler) ES-IEC Sensor ist hier leider nicht erwähnt
- Liste der unterstützen Stromzähler: 142148_liste_data.pdf NORDAX 3D ist in der Liste erwähnt, müsste also funktionieren
- [HM-ES-TX-WM Anbindung an FHEM (Anderer Zählertyp](https://richter.site/?p=54)

## Protokoll

Laut Anleitung hat die optische Schnittstelle des NORAX3D folgende Eigenschaften

- 9600 Baud 8N1
- Protokoll: SML + COSEM

Es gibt einen "Baisbetrieb" und einen "Erweiterten Betrieb - Herstellerbetrieb"
Im Basisbetrieb wird Obis 1.8.0 = "Entnommene Energie" unterstützt - das ist auch in 142148_liste_data.pdf erwähnt
Im "Erweiterten Betrieb" werden auch

- Momentane Leistung Obis 16.7.0
- Phasenspannung L1 Obis 32.7.0
- Phasenspannung L2 Obis 52.7.0
- Phasenspannung L3 Obis 72.7.0
- Phasenstrom 1 Obis 31.7.0
- Phasenstrom 2 Obis 51.7.0
- Phasenstrom 3 Obis 71.7.0
- 
erwähnt, allerdings ohne direkter Angabe einer Obis-Nummer - diese stehen aber in einem anderen Kontext später in der Anleitung.

Der Wechsel zwischen den beiden Protokollarten geschied durch den "InF"-Paramter.

Zitat aus Bedienungsanleitung:

"Aktivierungsbetrieb der Herstellerdaten im Telegramm am INFO-Port. Es wird das ON-Symbol angezeigt, wenn die Funktion ON ist (erweiterte Daten) oder OFF-Symbol, wenn die Funktion aus ist (Daten in der grundsätzlichen Version). Änderung des ON/OFF-Parameters durch langes Lichtsignal."

Das passt zu der Aussage von ELV:

Zitat:

"Bei SML-Zählern muss häufig zunächst die Info-Funktion im Menü auf On-gestellt werden, um alle Daten und die Zählerstände mit voller Auflösung zu erhalten. Hierfür ist ggf. die PIN von Messstellenbeteiber zu erfragen."

## PIN des Stromzählers

Habe über die Webseite https://www.rng.de/cms/smart-meter-pin-anfordern.html die PIN angefordert, sie kam ein paar Tage später mit mir per Post.

Zur PIN-Eingabe einmal lange (> 5 s) auf die "Nach-Links-Taste" am Zähler drücken.

Dann PIN eingeben. Dies geschied ausschließlich mit der "Nach-Links-Taste" am Zähler (langes oder kurzes Drücken)

Dann im Menü den Parameter "InF" auf "ON" gestellt und den Paremeter PIN auf "Off" (um PIN später nicht mehr eingeben zu müssen)

## Firmware HM-ES-TX-WM

Im Auslieferungszustand ist die Firmware V1.2 auf dem HM-ES-TX-WM installiert.

Für den Betrieb mit dem ES-IEC ist auf dem HM-ES-TX-WM eine Firmwareversion ≥ 2.0 notwendig.

Aktuell (Stand Nov. 2021) ist die V2.5, die also unbedingt installiert werden muss.  

## Firmware-Update über FHEM

- Updatedatei herunterladen von https://www.eq-3.de/service/downloads.html
- Die Datei `HM-ES-TX-WM_update_V2_5_191209.eq3` nach `/opt/fhem/` kopieren
- Korrekte Rechte vergeben mit `chown fhem:dialout /opt/fhem/HM-ES-TX-WM_update_V2_5_191209.eq3`
- Für ein erfolgreiches Firmwareupdate sollte das Gerät mit einem Sensor verbunden sein.
- Das Gerät lässt sich in den Updatemodus versetzen, im dem die Batterien zunächst entfernt, dann beim Einsetzen die Anlerntaste (die rechte mit der Bezeichnung ">") gedrückt bleibt. Die Leuchtdiode blinkt dann rot im sehr schnellen Takt.
- Das FHEM-Kommando zum Senden der Firmware per `set <devicename> fwUpdate <Firmwaredatei.eq3>` muss vor dem Einlegen der Batterie (bei gleichzeitigem Drücken der Anlerntaste) aufgegeben werden. Erfolgt zum Zeitpunkt des Einschaltens im Updatemodus keine Sendung der Firmware wird der Zählersensor normal gebootet. Die Meldung `<devicename> fwUpdate: fail:notInBootLoader` im Filelog erscheint, wenn das FHEM fwUpdate Kommando zu spät gesendet wurde. Das Update dauert etwa eine Minute. Während des Updates blinkt die Diode rot in kurzen Intervallen.
- Nach erfolgreichen Update muss der Sensor auf die Werkseinstellungen zurückgesetzt (">" Taste 4 Sekunden drücken (Display zeigt reS), kurz warten, ">" noch mal 4 Sekunden drücken - Zählersensor rebootet), aus der FHEM Konfiguration entfernt und neu angelernt werden. Wenn der Reset nicht durchgeführt wird, kommt vom Sensor immer die Fehlermeldung: einmal langes und drei mal kurzes rotes Blinken (Sitz des Auslesekopfes prüfen). Diese Meldung ist in diesem Zusammenhang ziemlich irreführend. 

# Konfiguration

Mit `get HM_PowerMeter regList` kann man eine Übersicht der einzustellenden Register auslesen

list:         register | range              | peer     | description
   0: baudrate         |     literal        |          | baudrate options:Bd2400,Bd19200,Bd1200,Bd300,Bd4800,Bd9600,Bd600
   0: pairCentral      |   0 to 16777215    |          | pairing to central
   0: powerMode        |     literal        |          | meter powermode options:mainPower,batPower
   0: protocolMode     |     literal        |          | meter protocol mode options:modeA,modeB,modeC,modeD,modeSML
   0: samplPerCycl     |   1 to 10          |          | samples per cycle
   0: serialFormat     |     literal        |          | serial Format options:s7D1PE2S,s8D0PN1S,s8D1PE1S,s7D1PE1S
   0: transmDevTryMax  |   1 to 10          |          | max message re-transmit

und mit `get HM_PowerMeter reg XXXX` kann man die Einstellung lesen

Korrekte Einstellung für den NORAX3D sind

baudrate = Bd9600 (war schon default)
protocolMode = modeSML  (Default war modeD)
serialFormat = s8D0PN1S (Default war s7D1PE1S)


