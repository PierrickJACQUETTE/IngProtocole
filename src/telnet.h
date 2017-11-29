#ifndef TELNET_H
#define TELNET_H

#include "telnet_message.h"

/**
 * Permet d afficher un paquet telnet
 * @param telnet le paquet a afficher
 */
void print_telnet(struct telnet** telnet);

/**
 * Permet de detruire la structure donnee en argument
 * @param telnet le paquet a detruire
 */
void destroyTelnet(struct telnet** telnet);

#endif
