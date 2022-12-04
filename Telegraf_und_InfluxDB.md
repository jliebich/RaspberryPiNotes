# Grundidee

[Grafana: Monitor FHEM data with Telegraf and InfluxDB](https://www.dev-eth0.de/2016/12/07/grafana_fhem_influxdb/)


# Config fürs veraltete logparser telegraf plugin

    [[outputs.influxdb]]
    urls = ["http://localhost:8086"]
    database = "telegraf"
    [[inputs.logparser]]
    files = ["/opt/fhem/log/**TX35DTH-**.log"]
    from_beginning = true
    [inputs.logparser.grok]
    patterns = ["%{TEMP}", "%{HUM}"]
    measurement = "fhem"
    custom_patterns = '''
    TEMP %{DATA:timestamp:ts-"2006-01-02_15:04:05"} %{DATA:room:tag} temperature: %{NUMBER:temperature:float}
    HUM %{DATA:timestamp:ts-"2006-01-02_15:04:05"} %{DATA:room:tag} humidity: %{NUMBER:humidity:float}
    '''
#config für das neue tail plugin


# Telegraf aus Raspi installieren

    [[inputs.tail]]
    files = ["/opt/fhem/log/PowerMeter-2021.log"]
    from_beginning = true

#   ## Data format to consume.
#   ## Each data format has its own unique set of configuration options, read
#   ## more about them here:
#   ## https://github.com/influxdata/telegraf/blob/master/docs/DATA_FORMATS_INPUT.md
#   data_format = "influx"
#
#   ## Set the tag that will contain the path of the tailed file. If you don't want this tag, set it to an empty string.
#   # path_tag = "path"
#
#   ## Filters to apply to files before generating metrics
#   ## "ansi_color" removes ANSI colors
#   # filters = []
#
#   ## multiline parser/codec
#   ## https://www.elastic.co/guide/en/logstash/2.4/plugins-filters-multiline.html
#   #[inputs.tail.multiline]
#     ## The pattern should be a regexp which matches what you believe to be an indicator that the field is part of an event consisting of multiple lines of log data.
#     #pattern = "^\s"
#
#     ## The field's value must be previous or next and indicates the relation to the
#     ## multi-line event.
#     #match_which_line = "previous"
#
#     ## The invert_match can be true or false (defaults to false).
#     ## If true, a message not matching the pattern will constitute a match of the multiline filter and the what will be applied. (vice-versa is also true)
#     #invert_match = false
#
#     #After the specified timeout, this plugin sends the multiline event even if no new pattern is found to start a new event. The default is 5s.
#     #timeout = 5s


Ich möchte die InfluxDB aber nicht (wie oben beschrieben) lokal auf dem gleichen Rechner wie FHEM haben, sondern auf einem Rechner im Internet.







