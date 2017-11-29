#ifndef TELNET_MESSAGE_H
#define TELNET_MESSAGE_H

#include "annexe.h"
#include "telnet_option.h"
#include "telnet_sb.h"

/**
 * Permet d afficher le message d un paquet telnet
 * @param message message a afficher
 * @param i       indice du caractere courant
 */
void print_message(unsigned char** message, int* i);

#endif
