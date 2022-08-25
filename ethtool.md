# ethtool

Da tool hilft um die Ethernetschnittstelle zu debuggen und einzustellen.

    ethtool eth0

liefert umfangreiche Infos über die Ethernet-Schnittstelle


Um Gigabut Ethernet-Verbindungen zu verhindern kann man

    ethtool -s eth0 advertise 0x00f

verwenden 0x00f ist die Kombination aus allen anderen (langsameren) Modi laut dieser Tabelle:

    advertise N
    Sets the speed and duplex advertised by autonegotiation.  The 
    argument is a hexadecimal value using one or a combination of
    the following values:
    0x001       10baseT Half
    0x002       10baseT Full
    0x004       100baseT Half
    0x008       100baseT Full
    0x010       1000baseT Half       (not supported by IEEE standards)
    0x020       1000baseT Full
    

      
      

