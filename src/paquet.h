#ifndef PAQUET_H
#define PAQUET_H

#include "tcp.h"
#include "telnet.h"

void paquet(u_char* args, const struct pcap_pkthdr* hdr, const u_char* truepacket);

#endif
