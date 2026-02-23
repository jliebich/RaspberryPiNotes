# Nextcloud als Docker Container
## Update über Portainer
In Portainer auf Stacks klicken und dann nextcloud auswählen

Dann auf Editor klicken und auf "Update the stack"

"Repull image and redeploy" anwählen und dann "Update" klicken

## Fehlende Datenbankaktualisierungen nach Update
Auf der Nextcloud-Weboberfläche Administration -> Übersucht wählen

Dort sind ggf- Hinweise welche occ-Kommandos man ausführen sollte um fehlende Datenbankaktualisierungen anzustoßen

Diese kann man auf der Konsole des Docker Containers ausführen

Dazu

    sudo docker exec -it <docker-ID> bash

ausführen.

In der Bash des Docker Container jetzt

    php /app/www/public/occ maintenance:repair --include-expensive

und/oder

    php /app/www/public/occ db:add-missing-indices

ausführen
