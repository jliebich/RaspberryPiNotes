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
