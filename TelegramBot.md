# Eigene User-ID herausfinden

Send a message to your bot then retrieve the update with:

https://api.telegram.org/bot"BOTID"/getUpdates

"BOTID" ist dabei der Token des Bots

In the json string returned you will find you chat_id/user_id.
In single chat with the bot chat_id is equal to user_id.
Now you can send your message with:

https://api.telegram.org/bot"BOTID"/sendMessage?chat_id="yourchatid"&text="Hello!"
