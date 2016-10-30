#Synology NAS konfigurieren

Install the OpenVPN server from within Package Center.

Enable OpenVPN under OpenVPN Server > Settings > OpenVPN.

#Fritzbox konfigurieren

Unter Portfreigaben UDP port 1194 an NAS freigeben:

Portfreigabe aktiv für: Andere Anwendung

Bezeichnung: VPN Server (frei wählbar)

Protokoll: UDP

von Port 1194 bis Port 1194

an Computer:Diskstation

an IP-Adresse XX.XX.XX.XX

an Port 1194

#Windows konfigurieren

OpenVPN application installieren

In der NAS Operfläche unter OpenVPN Server > OpenVPN auf Konfigurationdateien exportieren wählen.

Configure the OpenVPN client software

Open windows explorer and navigate to “C:Program Files (x86)OpenVPNconfig”. Copy the openvpn.opvn and ca.crt files from the openvpn.zip file you downloaded earlier to this directory.

Right-click on openvpn.ovpn and open it with notepad (or your favorite text editor) and make the edits explained below:

remote ovpn.example.com 1194

Ändere 

    #float

to

    float

und

    #redirect-gateway
zu

    redirect-gateway

OpenVPN GUI starten und verbinden mit User und Passwort aus NAS
