# Grundidee

[Grafana: Monitor FHEM data with Telegraf and InfluxDB](https://www.dev-eth0.de/2016/12/07/grafana_fhem_influxdb/)

Ich möchte die InfluxDB aber nicht (wie oben beschrieben) lokal auf dem gleichen Rechner wie FHEM haben, sondern auf einem Rechner im Internet.

# Config fürs veraltete logparser telegraf plugin

    [[outputs.influxdb]]
    urls = ["http://localhost:8086"]
    database = "telegraf"
    [[inputs.logparser]]
    files = ["/opt/fhem/log/**TX35DTH-**.log"]
    from_beginning = true
    [inputs.logparser.grok]
    patterns = ["%{ENERGY}", "%{POWER}"]
    measurement = "fhem"
    custom_patterns = '''
    ENERGY %{DATA:timestamp:ts-"2006-01-02_15:04:05"} %{DATA:room:tag} energyIEC: %{NUMBER:temperature:float}
    POWER %{DATA:timestamp:ts-"2006-01-02_15:04:05"} %{DATA:room:tag} powerIEC: %{NUMBER:humidity:float}
    '''
# Config für das neue tail plugin

    [[inputs.tail]]
    files = ["/opt/fhem/log/PowerMeter-2021.log"]
    from_beginning = true
    data_format = "grok"
    grok_patterns = ["%{ENERGY}", "%{POWER}"]
    grok_custom_patterns = '''
    ENERGY %{DATA:timestamp:ts-"2006-01-02_15:04:05"} %{DATA:room:tag} energyIEC: %{NUMBER:temperature:float}
    POWER %{DATA:timestamp:ts-"2006-01-02_15:04:05"} %{DATA:room:tag} powerIEC: %{NUMBER:humidity:float}
    '''









