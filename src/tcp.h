#ifndef TCP_H
#define TCP_H

#include "core.h"

/**
 * Permet d'afficher le contenu du paquet si c'est du tcp
 * @param tcp le paquet tcp
 */
void print_tcp_apli(struct tcphdr** tcp);

#endif
