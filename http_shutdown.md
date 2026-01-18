# Shutdown Script
Das ist auf meinem Jellyfin Server instlliert um ihn einfach herunterfahren zu können, z.B. über FHEM

```
#!/usr/bin/env python3
from http.server import BaseHTTPRequestHandler, HTTPServer
import subprocess
import urllib.parse
import datetime

PORT = 7762
SECRET_KEY = "MEINSECRET"  # <--- hier eigenes Secret eintragen
LOGFILE = "/var/log/http-control.log"

def log_event(message: str):
    timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(LOGFILE, "a") as f:
        f.write(f"[{timestamp}] {message}\n")

class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        parsed_path = urllib.parse.urlparse(self.path)
        path = parsed_path.path
        query = urllib.parse.parse_qs(parsed_path.query)
        key = query.get("key", [""])[0]

        if key != SECRET_KEY:
            self.send_response(403)
            self.end_headers()
            self.wfile.write(b"Forbidden: Invalid key\n")
            log_event(f"Unauthorized access attempt to {path} from {self.client_address[0]}")
            return

        # Shutdown
        if path == "/shutdown":
            self.send_response(200)
            self.end_headers()
            self.wfile.write(b"System is shutting down\n")
            log_event(f"Shutdown triggered by {self.client_address[0]}")
            subprocess.Popen(["/sbin/shutdown", "-h", "now"])

        # Reboot
        elif path == "/reboot":
            self.send_response(200)
            self.end_headers()
            self.wfile.write(b"System is rebooting\n")
            log_event(f"Reboot triggered by {self.client_address[0]}")
            subprocess.Popen(["/sbin/reboot"])

        # Status
        elif path == "/status":
            try:
                output = subprocess.check_output(["fastfetch"], text=True)
            except Exception as e:
                output = f"Error running fastfetch: {e}"
            self.send_response(200)
            self.end_headers()
            self.wfile.write(output.encode("utf-8"))
            log_event(f"Status requested by {self.client_address[0]}")

        # 404 für alle anderen Pfade
        else:
            self.send_response(404)
            self.end_headers()
            self.wfile.write(b"Not Found\n")
            log_event(f"Unknown path {path} accessed by {self.client_address[0]}")

    # Konsole sauber halten
    def log_message(self, format, *args):
        return

# Server starten
HTTPServer(("", PORT), Handler).serve_forever()
```

Speichern, dann ausführbar machen:

    sudo chmod +x /usr/local/bin/http-shutdown.py

## systemd-Service anlegen
sudo nano /etc/systemd/system/http-shutdown.service
Inhalt:
```
[Unit]
Description=HTTP Shutdown Service
After=network.target

[Service]
ExecStart=/usr/bin/python3 /usr/local/bin/http-shutdown.py
User=root
Restart=always

[Install]
WantedBy=multi-user.target
```

## Service aktivieren & starten

    sudo systemctl daemon-reload
    sudo systemctl enable http-shutdown.service
    sudo systemctl start http-shutdown.service


## Status prüfen

    sudo systemctl status http-shutdown.service

## Test im Browser

    http://192.168.0.8:7762/status?key=MEINGEHEIMNIS

