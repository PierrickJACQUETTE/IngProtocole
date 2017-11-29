#ifndef PAQUET_H
#define PAQUET_H

#include "tcp.h"
#include "telnet.h"

/**
 * Permet de recuperer un paquet et de le traiter
 * @param args
 * @param hdr
 * @param truepacket
 */
void paquet(u_char* args, const struct pcap_pkthdr* hdr, const u_char* truepacket);

#endif
