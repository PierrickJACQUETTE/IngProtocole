#include "paquet.h"

int parsePaquet(const u_char* truepacket, struct paquet** paquet){
    int parse = 0;
    (*paquet)->ip=(struct ip*)(truepacket+14);
    if((*paquet)->ip->ip_p == IPPROTO_TCP){
        (*paquet)->tcp=(struct tcphdr*)(truepacket+14+(4*(*paquet)->ip->ip_hl));
        if (((unsigned short int)ntohs((*paquet)->tcp->dest) == 23) || (unsigned short int)ntohs((*paquet)->tcp->source) == 23){
            struct telnet* t = malloc(sizeof(struct telnet));
            ERROR_NULL(t, "malloc telnet : parsePaquet : paquet.c");
            t->message=(unsigned char*)(truepacket+14+(4*(*paquet)->ip->ip_hl)+(*paquet)->tcp->doff*4);
            t->size_telnet=ntohs((*paquet)->ip->ip_len)-(*paquet)->tcp->doff*4-20;
            (*paquet)->telnet = t;
            parse = 1;
        }
    }else{
        printf("ccc\n");
    }
    return parse;
}

void displayPaquet(struct paquet** paquet){
    if((*paquet)->ip->ip_p == IPPROTO_TCP){
        numero++;
        printf("%4i | ",numero);
        if ((unsigned short int)ntohs((*paquet)->tcp->dest) == 23){
            couleur(YELLOW);
            printf("Serveur ");
            couleur(DEFAULT);
            if((*paquet)->telnet->size_telnet>0){
                print_telnet(&(*paquet)->telnet);
            }else{
                print_tcp_apli(&(*paquet)->tcp);
            }
        }
        if ((unsigned short int)ntohs((*paquet)->tcp->source) == 23){
            couleur(CYAN);
            printf("Client  ");
            couleur(DEFAULT);
            if((*paquet)->telnet->size_telnet>0){
                print_telnet(&(*paquet)->telnet);
            }else{
                print_tcp_apli(&(*paquet)->tcp);
            }
        }
        printf("\n");
    }
}

void destroyPaquet(struct paquet** paquet){
    destroyTelnet(&(*paquet)->telnet);
    free(*paquet);
}

void paquet(u_char* args, const struct pcap_pkthdr* hdr, const u_char* truepacket){
    struct paquet* paquet = malloc(sizeof(struct paquet));
    ERROR_NULL_P(paquet, "parsePaquet : paquet : paquet.c");
    if(paquet != NULL){
        int error = parsePaquet(truepacket, &paquet);
        ERROR_SYS_P(error, "parsePaquet : paquet : paquet.c");
        if(error == 1){
            displayPaquet(&paquet);
        }
        destroyPaquet(&paquet);
    }
}
