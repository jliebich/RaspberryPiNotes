# Update OpenWrt/LEDE Installation

Aktuelles Image passend zur Hardware runterladen z.B unter

    https://openwrt.org/toh/hwdata/tp-link/tp-link_tl-wdr4300
oder

    https://openwrt.org/toh/hwdata/gl.inet/gl.inet_gl-b1300

Datei heißt z.B.

    openwrt-18.06.1-ipq40xx-glinet_gl-b1300-squashfs-sysupgrade.bin

Auf das LuCI web interface des Routers einloggen.

Select System ⇒ Backup / Flash Firmware ⇒ Actions -> Bckup/Restore -> Generate Archive
um Einstellungen zu sichern.

Dann "Flash new firware image" -> Durchsuchen
um eben geladenes Image zu installieren

# Probleme beim GL-B1300

Update über Webinterface klappte nicht - war danach nicht mehr ansprechbar.
Update über UBoot vorgenommen, nach dieser Anleitung

    https://docs.gl-inet.com/en/2/troubleshooting/debrick/

Danach finktionierte es.
Vielleicht lag es daran, dass vorher nicht das Original OpenWRT Image installiert war, sonden ein OpenWrt von Gl-Inet?
