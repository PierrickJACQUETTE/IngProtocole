#ifndef CORE_H
#define CORE_H

#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define couleur(param) printf("\033[%dm",param)
#define RED 31
#define GREEN 32
#define YELLOW 33
#define CYAN 36
#define DEFAULT 0

/**
 * structure du corps d un message telnet
 */
struct telnet{
    unsigned char * message;        //corps
    int size_telnet;                //taille du corps
};

/**
 * structure du paquet telnet
 */
struct paquet {
    struct ip* ip;          // information ip du paquet
    struct tcphdr* tcp;     // information tcp du paquet
    struct telnet* telnet;  // information telnet du paquet
};

int numero;

#define ERROR_NULL(a,str) if (a == NULL) {fprintf(stderr, "\n%s\n\n", str); return EXIT_FAILURE;}
#define ERROR_NULL_P(a,str) if (a == NULL) {fprintf(stderr, "\n%s\n\n", str);}
#define ERROR_SYS(a,str) if (a < 0) {fprintf(stderr, "\n%s\n\n", str); return EXIT_FAILURE;}
#define ERROR_SYS_P(a,str) if (a < 0) {fprintf(stderr, "\n%s\n\n", str);}

#endif
