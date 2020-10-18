# Searx auf Raspberry Pi

Quellen
https://raspiblog.noblogs.org/post/2018/01/27/installing-searx-with-apache-and-morty/
https://searx.github.io/searx/admin/installation-searx.html#installation-basic

Ich will eine schlanke Installation für die ausschließliche Nutzung im Inranet, also ohne filtron und morty.

Deshalb verwende ich die "Step by step installation"-Anleitung.

    sudo -H apt-get install -y virtualenv python3-dev python3-babel python3-venv uwsgi uwsgi-plugin-python3 git build-essential libxslt-dev zlib1g-dev libffi-dev libssl-dev shellcheck
    
    
