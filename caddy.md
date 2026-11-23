## HTTPS für Heimnetz-Dienste mit ipv64.net und Caddy

- **Voraussetzungen:** Linux-System mit fester LAN-IP, Docker und Docker Compose. Caddy übernimmt den Reverse Proxy; Pi-hole oder ein anderer lokaler DNS-Server löst die Dienstnamen im Heimnetz auf.
- **ipv64.net vorbereiten:** DynDNS-Domain anlegen, zum Beispiel `meinname.ipv64.de`. Eine CDN-Domain brauchst du dafür nicht.
- **API-Key erstellen:** In ipv64.net unter **Account → API** einen Key anlegen und sicher aufbewahren.
- **Caddy-Modul einbauen:** Im Caddy-Dockerfile das Modul `github.com/Sickjuicy/caddy-ipv64` hinzufügen:
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
- **Caddy konfigurieren:** Für die Wildcard-Domain DNS-01 aktivieren:
  ```caddyfile
  *.meinname.ipv64.de {
      tls {
          dns ipv64 {
              api_token {env.IPV64_API_TOKEN}
          }
          resolvers 1.1.1.1 8.8.8.8
          propagation_delay 30s
      }

      @dienst host dienst.meinname.ipv64.de
      handle @dienst {
          reverse_proxy 192.168.1.50:PORT
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
