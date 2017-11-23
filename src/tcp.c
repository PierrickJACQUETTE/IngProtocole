#include "tcp.h"

void print_tcp_apli(struct tcphdr** tcp){
	printf("| ");
	couleur(GREEN);
	printf("TCP: ");
	couleur(DEFAULT);
	if((*tcp)->urg){
		printf("URG ");
	}
	if((*tcp)->ack){
		printf("ACK ");
	}
	if((*tcp)->psh){
		printf("PSH ");
	}
	if((*tcp)->rst){
		printf("RST ");
	}
	if((*tcp)->syn){
		printf("SYN ");
	}
	if((*tcp)->fin){
		printf("FIN ");
	}
}
