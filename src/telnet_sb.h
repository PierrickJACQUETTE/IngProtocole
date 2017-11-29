#ifndef TELNET_SB_H
#define TELNET_SB_H

#include "annexe.h"

/**
 * Permet d afficher les sous options de sb d un paquet telnet
 * @param message caractere courant
 * @param i       indice du caractere courant
 * @param option  valeur de l option courante
 */
void print_sb(unsigned char** message, int* i, int* option);

#endif
