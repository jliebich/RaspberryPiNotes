# Telegram-Bot

## Eigene User-ID herausfinden

Im Browser folgende Nachricht an den eigenen Bot senden:

    https://api.telegram.org/bot<TOKEN>/getUpdates

Er hat die folgende Form

    1234567890:AbCdefgHIJklmnOPQRst-uvwxyz

und wird beim anlegen vom BotFather übermittelt.

In dem zurückgegebenen JSON-String findet man seine chat_id und user_id.
Im Einzelchat mit dem Bot ist chat_id gleichbedeutend mit user_id.

## Nachricht senden

### Im Browser:

    https://api.telegram.org/bot<TOKEN>/sendMessage?chat_id="yourchatid"&text="Hello!"

### Linux Command Line:

    curl -s -X POST https://api.telegram.org/bot<TOKEN>/sendMessage -d chat_id=<CHAT_ID> -d text="Hello World"

### Bash Script Beispiel

    #!/bin/bash

    TOKEN=<TOKEN>
    CHAT_ID=<CHAT_ID>
    MESSAGE="Hello World"
    URL="https://api.telegram.org/bot$TOKEN/sendMessage"

    curl -s -X POST $URL -d chat_id=$CHAT_ID -d text="$MESSAGE"
    
### .NET Beispiel    
    
    public void SendNotificationViaTelegram(string notificationMessage)
    {
        var telegramNotification = WebRequest.Create(
            "https://api.telegram.org/botABCDEFG/sendMessage?chat_id=3101948&text="
	        + HttpUtility.UrlEncode(notificationMessage));
        telegramNotification.GetResponse();
  
### Bei start / stop eines systemd service Nachricht senden

Hier zum Beispiel für nginx:
In der Datei /lib/systemd/system/nginx.service im Abschnitt Service folgendes ergänzen

	ExecStartPost=/usr/bin/curl --data chat_id=XXXXXXXXX --data-urlencode "text=Webserver wurde gestartet"  "https://api.telegram.org/botXXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXX/sendMessage"
	ExecStopPost=/usr/bin/curl --data chat_id=XXXXXXXXX --data-urlencode "text=Webserver wurde angehalten"  "https://api.telegram.org/botXXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXX/sendMessage"

Nach dem ändern muss folgendes ausgeführt werden:

 	systemctl daemon-reload	


### Telegram für Benachrichtigungen in der Synology-NAS einrichten 
https://blog.unltd-networx.de/synology-diskstation-telegram/
