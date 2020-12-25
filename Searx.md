# Searx auf Raspberry Pi

## Quellen
https://raspiblog.noblogs.org/post/2018/01/27/installing-searx-with-apache-and-morty/

https://searx.github.io/searx/admin/installation-searx.html#installation-basic

## Installation nach "Step by step instruction"
Ich will eine schlanke Installation für die ausschließliche Nutzung im Inranet, also ohne filtron und morty.

Deshalb verwende ich die "Step by step installation"-Anleitung.

    sudo -H apt-get install -y virtualenv python3-dev python3-babel python3-venv uwsgi uwsgi-plugin-python3 git build-essential libxslt-dev zlib1g-dev libffi-dev libssl-dev shellcheck
    
    sudo -H useradd --shell /bin/bash --system --home-dir /usr/local/searx --comment 'Privacy-respecting metasearch engine' searx
    sudo -H mkdir /usr/local/searx
    sudo -H chown -R searx:searx /usr/local/searx
    
    sudo -H -u searx -i
    
Wir sind jetzt als User searx angemeldet, man sieht es am Prompt. Weiter mit:    
    
    git clone https://github.com/searx/searx.git /usr/local/searx/searx-src
    python3 -m venv /usr/local/searx/searx-pyenv
    echo . /usr/local/searx/searx-pyenv/bin/activate >>  /usr/local/searx/.profile
    
Jetzt mit exit wieder zurück aus den vorherigen user.

Zur Kontrolle wieder zum user searx

    sudo -H -u searx -i

Wir sind jetzt also wieder als User searx angemeldet, man sieht es wieder am Prompt.

    command -v python && python --version
Liefert bei mir
    
    /usr/local/searx/searx-pyenv/bin/python
    Python 3.7.3
    
laut Anleitung soll es Python 3.8.1 sein - mein Rasbian ist offensichtlich noch nicht so weit - hoffe dass es trotzdem funktioniert.
Weiter mit dieser Anmeldung:

    pip install -U pip
    pip install -U setuptools
    pip install -U wheel
    cd /usr/local/searx/searx-src
    pip install -e .
    
Zweites Terminal öffnen (mit normalem User) und das andere mit User serry offen lassen
In dem neuen Terminal:

    mkdir /etc/searx
    sudo -H cp /usr/local/searx/searx-src/searx/settings.yml /etc/searx/settings.yml
    sudo -H sed -i -e s/ultrasecretkey/\51234567890b42919551c0442c4919d8/g /etc/searx/settings.yml

Schlüssel natürlich beliebig anpassen

Dieser Befehl    

    sudo -H sed -i -e s/{instance_name}/searx@\alexandre-vm/g /etc/searx/settings.yml

funktionierte beim mir nicht. Habs gelassen. Nennt nur irgendwie die Instance um, vermutlich nicht nötig.

Debug aktivieren
Dazu in Datei /etc/searx/settings.yml "debug : False" ersetzen mit

    debug : True

Im searx Terminal:

    cd /usr/local/searx/searx-src
    export SEARX_SETTINGS_PATH=/etc/searx/settings.yml
    python searx/webapp.py

Jetzt testen (mit normalem User-Terminal), remote ging bei mir nicht (wegen Firewall) auf dem Rechner selber mit curl aber schon:

    curl 127.0.0.1:8888 --location --verbose --head --insecure

liefert so was ähnliches wie

    *   Trying 127.0.0.1:8888...
    * TCP_NODELAY set
    * Connected to 127.0.0.1 (127.0.0.1) port 8888 (#0)
    > HEAD / HTTP/1.1
    > Host: 127.0.0.1:8888
    > User-Agent: curl/7.68.0
    > Accept: */*
    >
    * Mark bundle as not supporting multiuse
    * HTTP 1.0, assume close after body
    < HTTP/1.0 200 OK
    HTTP/1.0 200 OK
    ...

Debug wieder disable.
Dazu in Datei /etc/searx/settings.yml "debug : True" wieder ersetzen mit

    debug : False
    
## Zu nginx hinzufügen

    
