## HTTPS für Heimnetz-Dienste mit ipv64.net und Caddy

- **Voraussetzungen:** Linux-System mit fester LAN-IP, Docker und Docker Compose. Caddy übernimmt den Reverse Proxy; Pi-hole oder ein anderer lokaler DNS-Server löst die Dienstnamen im Heimnetz auf.
- **ipv64.net vorbereiten:** DynDNS-Domain anlegen, zum Beispiel `meinname.ipv64.de`. Eine CDN-Domain brauchst du dafür nicht.
- **API-Key erstellen:** In ipv64.net unter **Account → API** einen Key anlegen und sicher aufbewahren.
- **Caddy-Modul einbauen:** Im Caddy-Dockerfile (bei mir unter `/opt/caddy-ipv64/Dockerfile` ) das Modul `github.com/Sickjuicy/caddy-ipv64` hinzufügen:
  ```dockerfile
  FROM caddy:2-builder AS builder
  RUN xcaddy build --with github.com/Sickjuicy/caddy-ipv64@latest

  FROM caddy:2
  COPY --from=builder /usr/bin/caddy /usr/bin/caddy
  ```
- **Key hinterlegen:** In `.env` eintragen und in `docker-compose.yaml` an den Caddy-Container weiterreichen:
  ```env
  IPV64_API_TOKEN=dein_api_key
  ```
  Achtung: mit normalem ls wird die .env Datei nicht angezeigt!
  
- **Caddy konfigurieren:** So sieht mein Caddyfile aus:
  ```Caddyfile
  {
    email admin@XXXXXXX.ipv64.de
}

*.XXXXXXX.ipv64.de {
    tls {
        dns ipv64 {
            api_token {env.IPV64_API_TOKEN}
        }
        resolvers 9.9.9.9 1.1.1.1
        propagation_delay 30s
    }

    @pihole host pihole.XXXXXXX.ipv64.de
    handle @pihole {
        redir / /admin/
        reverse_proxy pihole:80
    }

    @searxng host search.XXXXXXX.ipv64.de
    handle @searxng {
        reverse_proxy searxng:8080
    }

    @portainer host portainer.XXXXXXX.ipv64.de
    handle @portainer {
        reverse_proxy portainer:9000
    }

    @paperless host paperless.XXXXXXX.ipv64.de
    handle @paperless {
        reverse_proxy paperless-ngx-webserver-1:8000
    }

    @nextcloud host cloud.XXXXXXX.ipv64.de
    handle @nextcloud {
        redir /.well-known/carddav /remote.php/dav/ 301
        redir /.well-known/caldav /remote.php/dav/ 301
        reverse_proxy nextcloud:80
    }

    @vault host vault.XXXXXXX.ipv64.de
    handle @vault {
        reverse_proxy vaultwarden:80
    }

    @wud host wud.XXXXXXX.ipv64.de
    handle @wud {
        reverse_proxy wud:3000
    }

    handle {
        abort
    }
}
  ```
  `meinname.ipv64.de`, die Dienstnamen, IP-Adressen und Ports anpassen. Weitere Dienste jeweils mit eigenem `host`-Matcher und `reverse_proxy` ergänzen.
- **Lokalen DNS einrichten:** Im lokalen DNS einen Wildcard-Eintrag für `*.meinname.ipv64.de` auf die LAN-IP von Caddy setzen. Die Clients müssen diesen DNS-Server verwenden.
- **Starten und prüfen:** Mit `docker compose up -d --build` starten. Caddy-Logs auf eine erfolgreiche Zertifikatsausstellung prüfen und im Heimnetz `https://dienst.meinname.ipv64.de` aufrufen.

**Hinweis:** Der API-Key ist vertraulich. Das ipv64.net-Modul ist ein Community-Modul.
