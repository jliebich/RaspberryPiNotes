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
    
