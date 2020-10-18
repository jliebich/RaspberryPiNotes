# Searx auf Raspberry Pi

Quellen
https://raspiblog.noblogs.org/post/2018/01/27/installing-searx-with-apache-and-morty/
https://searx.github.io/searx/admin/installation-searx.html#installation-basic

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
    
    
