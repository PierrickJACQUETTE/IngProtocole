#include "pcap.h"

int pcap(char* fichier){
    FILE* f = NULL;
    pcap_t *capture;
    char* errbuf = NULL;
    struct bpf_program fp;
    int error;
    numero = 0;

    f = fopen(fichier, "r");
    ERROR_NULL(f, "imposible de lire le fichier : fopen : pcap : pcap.c");
    capture = pcap_fopen_offline(f, errbuf);
    ERROR_NULL(capture, "impossible d'ouvrir l'interface : pcap_fopen_offline : pcap : pcap.c");
    error = pcap_compile(capture, &fp, "tcp port 23", 0, 0);
    ERROR_SYS(error, "Error : pcap_compile : pcap : pcap.c");
    error = pcap_setfilter(capture, &fp);
    ERROR_SYS(error, "Error : pcap_setfilter : pcap : pcap.c");
    printHeader();

    pcap_loop(capture, 0, paquet, NULL);
    ERROR_SYS(error, "Error : pcap_loop : pcap : pcap.c");

    pcap_freecode(&fp);
    pcap_close(capture);
    return EXIT_SUCCESS;
}
