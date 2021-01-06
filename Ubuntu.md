# VNC
Verschlüsselung für VNC deaktivieren, damit UntraVNC unter Windows Verbindung aufnehmen kann

    gsettings set org.gnome.Vino require-encryption false


# Screensvaer
Sofern der dconf-editor nicht installiert ist kann man das mit

    sudo apt-get install dconf-editor

nachholen.

Die gewünschte Einstellung findet man dann unter org -> Gnome -> Desktop -> screensaver. Hier entfernt man einfach bei ubuntu-lock-on-suspend das Häkchen.

# Animationen abschalten
 
 /org/gnome/desktop/interface/, scroll down a bit, and disable the "enable-animations" setting
