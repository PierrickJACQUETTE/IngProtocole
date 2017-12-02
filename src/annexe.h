#ifndef ANNEXE_H
#define ANNEXE_H

#include "core.h"
/**
* affiche la chaine avec cette valeur
* @param chaine a afficher
* @param value  valeur decimal de l'affichage
*/
void print(char* chaine, int value);

/**
* affiche le header
*/
void printHeader();

/**
* permet de lire 8 octets
* @param message le texte à lire
* @param i       indice courant de lecture
*/
void read8(unsigned char** message, int* i);

/**
* permet de lire 16 octets
* @param message le texte à lire
* @param i       indice courant de lecture
*/
void read16(unsigned char** message, int* i);

/**
* permet de lire 32 octets
* @param message le texte à lire
* @param i       indice courant de lecture
*/
void read32(unsigned char** message, int* i);

/**
* permet de lire jusqu'à lire un IAC (=255)
* @param message le texte à lire
* @param i       indice courant de lecture
* @param print   savoir si j'affiche en tant que char, entier
*/
void read255(unsigned char** message, int* i, int print);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param zero    texte a afficher si 0
* @param one     texte a afficher si 1
*/
void checkZeroOne(unsigned char** message, int* i, char* zero, char* one);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param zero    texte a afficher si 0
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
*/
void checkZeroUntilTwo(unsigned char** message, int* i, char* zero, char* one, char* two);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param zero    texte a afficher si 0
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
* @param three   texte a afficher si 3
*/
void checkZeroUntilThree(unsigned char** message, int* i, char* zero, char* one, char* two, char* three);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param zero    texte a afficher si 0
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
* @param three   texte a afficher si 3
* @param four    texte a afficher si 4
*/
void checkZeroUntilFour(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four);


/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param zero    texte a afficher si 0
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
* @param three   texte a afficher si 3
* @param four    texte a afficher si 4
* @param five    texte a afficher si 5
* @param six     texte a afficher si 6
* @param seven   texte a afficher si 7
* @param eight   texte a afficher si 8
*/
void checkZeroUntilEight(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four, char* five, char* six, char* seven, char* eight);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param eight   texte a afficher si 8
* @param nine    texte a afficher si 9
* @param ten     texte a afficher si 10
* @param eleven  texte a afficher si 11
*/
void checkEightUntilEleven(unsigned char** message, int* i, char* eight, char* nine, char* ten, char* eleven);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param zero    texte a afficher si 0
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
* @param three   texte a afficher si 3
* @param four    texte a afficher si 4
* @param eight   texte a afficher si 8
* @param nine    texte a afficher si 9
* @param ten     texte a afficher si 10
* @param eleven  texte a afficher si 11
*/
void check0Until4And8Until11(unsigned char** message, int* i, char* zero, char* one, char* two, char* three, char* four, char* eight, char* nine, char* ten, char* eleven);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
* @param three   texte a afficher si 3
*/
void checkOneUntilThree(unsigned char** message, int* i, char* one, char* two, char* three);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
* @param three   texte a afficher si 3
* @param four    texte a afficher si 4
*/
void checkOneUntilFour(unsigned char** message, int* i, char* one, char* two, char* three, char* four);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param one     texte a afficher si 1
* @param two     texte a afficher si 2
* @param three   texte a afficher si 3
* @param four    texte a afficher si 4
* @param five    texte a afficher si 5
* @param six     texte a afficher si 6
* @param seven   texte a afficher si 7
*/
void checkOneUntilSeven(unsigned char** message, int* i, char* one, char* two, char* three, char* four, char* five, char* six, char* seven);

#endif
