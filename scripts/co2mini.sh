#!/bin/sh
### BEGIN INIT INFO
# Provides:          co2mini server
# Required-Start:    $all
# Required-Stop:     
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: 
# Description:       
### END INIT INFO

file="/home/pi/co2mini/fhem-co2mini/co2mini_server.pl"
port=20000

# Actions
case "$1" in

  start)

    pid=$(ps -aux | grep "$file" | sed '$ d' | awk '{ print $2 }')

    if [ ! -z $pid ]; then
      echo "Instance of co2mini server is already running with pid $pid"
    else
      "$file" /dev/co2mini0 $port &
      pid=$(ps -aux | grep "$file" | sed '$ d' | awk '{ print $2 }')
      echo "Started new instance of co2mini server with pid $pid"
    fi

  ;;

  stop)

    pid=$(ps -aux | grep "$file" | sed '$ d' | awk '{ print $2 }')

    if [ ! -z $pid ]; then
      echo "Killing old instance of co2mini server with pid $pid"
      kill -TERM $pid
      sleep 2
    fi

  ;;

  restart)

    pid=$(ps -aux | grep "$file" | sed '$ d' | awk '{ print $2 }')

    if [ ! -z $pid ]; then
      echo "Killing old instance of co2mini server with pid $pid"
      kill -TERM $pid
      sleep 2
    fi

    "$file" /dev/co2mini0 $port &

    pid=$(ps -aux | grep "$file" | sed '$ d' | awk '{ print $2 }')

    echo "Started new instance of co2mini server with pid $pid"
  ;;

esac
 
exit 0
