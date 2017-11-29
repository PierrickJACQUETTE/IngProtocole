#ifndef PCAP_H
#define PCAP_H

#include "paquet.h"

/**
 * Permet de lire le fichier, de filter les informations, de les afficher
 * @param  fichier le fichier pcap
 * @return int : 0 si tout ce passe bien et -1 en cas d'erreur
 */
int pcap(char* fichier);

#endif
