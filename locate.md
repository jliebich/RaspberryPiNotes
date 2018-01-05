# locate

locate ist ein Programm, mit dessen Hilfe man auf der Kommandozeile nach Dateien suchen kann.
Hierbei wird aber nicht das gesamte Datenverzeichnis durchsucht (wie bei find), sondern eine Datenbank, die zuvor angelegt wurde.
Diese wird regelmäßig aktualisiert, damit locate immer die korrekten Orte anzeigt, an denen sich die Dateien befinden und somit neue Dateien und Datenbewegungen erfasst werden.
Der Vorteil diese Methode besteht darin, dass das Durchsuchen der Datenbank sehr schnell geht, und die Suchergebnisse praktisch sofort zur Verfügung stehen.

## Installieren

    apt-get install mlocate

Es gibt auch das Paket locate, das ist aber nicht empfohlen.
Aufpassen, dass man nicht (wie ich) beide parallel installiert. Das ist Resourcenverschwendeung...

## Aktualisierung der Datenbank

### manuell:

    updatedb
    
### automatisch:

Bei der Installation wird ein cron job unter

    /etc/cron.daily/mlocate
    
angelegt.

## Konfiguration

Siehe /etc/updatedb.conf

Ich habe zusätzliche Ordner von der Suche ausgeschlossen.

    PRUNE_BIND_MOUNTS="yes"
    PRUNENAMES=".git .bzr .hg .svn"
    PRUNEPATHS="/tmp /var/spool /media /var/lib/os-prober /var/lib/ceph  /var/lib/dpkg/info /usr/share/man"
    PRUNEFS="NFS nfs nfs4 rpc_pipefs afs binfmt_misc proc smbfs autofs iso9660 ncpfs coda devpts ftpfs devfs devtmpfs fuse.mfs shfs sysfs cifs lustre tmpfs usbfs udf fuse.glusterfs fuse.sshfs curlftpfs ceph fuse.ceph fuse.rozofs"
    
Folgendes Kommando ist hilfreich, um Ordner mit sehr vielen Dateien zu finden, die man vielleich besser ausschließt, um die Datenbanknicht zu groß werden zu lassen:

     find / -xdev -printf '%h\n' | sort | uniq -c | sort -k 1 -n
     
     
