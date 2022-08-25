# CPU Frequenzen

    lscpu 

liefert auf meinem Raspberry Pi 4 Model B Rev 1.1

    ...
    CPU max MHz:         1500.0000
    CPU min MHz:         600.0000
    ....

und

    cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies
    
liefert

    600000 700000 800000 900000 1000000 1100000 1200000 1300000 1400000 1500000
    
## Strom sparen durch runtersetzen der minimalem Frequenz?

Das ist nicht erfolgsversprechend, siehe hier https://www.raspberrypi.com/documentation/computers/config_txt.html

Zitat zu arm_freq_min:

    Minimum value of arm_freq used for dynamic frequency clocking.
    Note that reducing this value below the default does not result
    in any significant power savings and is not currently supported.
    
    
