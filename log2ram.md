# log2ram

siehe hier:

https://github.com/azlux/log2ram

Meine Konfiguration:
* Größe 30 MB statt 40 MB
* Sync täglich statt stündlich
* Keine Mail

## Testen ob log2ram läuft

log2ram läuft nicht, wenn `/var/log` größer wird als die Größe, die in `/etc/log2ram.conf` angegebene Größe `SIZE`
Nach der Installation und dem Neustart kann man mit systemctl überprüfen, ob Log2Ram erfolgreich gestartet wurde:

```
systemctl status log2ram
```

Anzeigen des vollständigen Logs:

```
journalctl -u log2ram -e
```

Das Protokoll wird auch nach `/var/log/log2ram.log` geschrieben.

Man kann auch den Mount-Ordner im RAM mit 

    df -h | grep log2ram

und/oder

    mount | grep log2ram

anzeigen. Wenn log2ram funktioniert, werden Zeilen mit log2ram angezeigt

