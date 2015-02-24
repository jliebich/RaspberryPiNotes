#Aliases in Bashh
Schon zu DOS Zeiten habe ich mir immer ein Alias angelegt, das bei ".." ein "cd .." ausführt

In der Linux-Bash geht das so:

    sudo nano ~/.bash_aliases

Folgende Zeile am Ende einfügen:

    alias '..'='cd ..'

Nach verlassen der bash und neuem einloggem sollte es dann fentsprechend funktionieren.
