#ifndef TELNET_OPTION_H
#define TELNET_OPTION_H

#include "annexe.h"

/**
 * Permet d afficher les options d un message d un paquet telnet
 * @param message caractere courant
 * @param i       indice du caractere courant
 * @param option  valeur de l option courante
 */
void print_option(unsigned char* message, int *i, int* option);

#endif
