##Mounten von Samba Freigabe

    const char* src = "\\\\192.168.0.11\\Backup_Raspi";
    const char* dst = "/media/NAS";
    const char* fstype = "cifs";

    const char* all_string = "unc=\\\\192.168.0.11\\Backup_Raspi,ip=192.168.0.11,username=NASRaspi,password=geheim";
   
    printf("Trying to mount...\n");
    fflush(stdout);
    // int mount (const char *special_file, const char *dir, const char *fstype, unsigned long int options, const void *data)
    int result = mount(src, dst, fstype, MS_MGC_VAL | MS_SILENT, all_string);
