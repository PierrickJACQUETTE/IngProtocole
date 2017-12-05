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

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param eight   texte a afficher si 8
* @param nine    texte a afficher si 9
*/
void checkEightUntilNine(unsigned char** message, int* i, char* eight, char* nine);

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
* @param twelve    texte a afficher si 12
* @param thirteen  texte a afficher si 13
* @param fourteen  texte a afficher si 14
* @param fifteen   texte a afficher si 15
* @param sixteen   texte a afficher si 16
* @param seventeen texte a afficher si 17
* @param eighteen  texte a afficher si 18
* @param nineteen  texte a afficher si 19
* @param twenty    texte a afficher si 20
*/
void checkTwelveUntilTwenty(unsigned char** message, int* i, char* twelve, char* thirteen, char* fourteen, char* fifteen, char* sixteen, char* seventeen, char* eighteen, char* nineteen, char* twenty);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param one     texte a afficher si 21
* @param two     texte a afficher si 22
* @param three   texte a afficher si 23
* @param four    texte a afficher si 24
* @param five    texte a afficher si 25
* @param six     texte a afficher si 26
* @param seven   texte a afficher si 27
* @param eight   texte a afficher si 28
* @param nine    texte a afficher si 29
* @param thirty  texte a afficher si 30
*/
void checkTwentyOneUtilThirty(unsigned char** message, int* i, char* one, char* two, char* three, char* four, char* five, char* six, char* seven, char* eight, char* nine, char* thirty);

/**
* permet d afficher un texte personnaliser en fonction de l octet lu
* @param message le texte à lire
* @param i       indice courant de lecture
* @param one     texte a afficher si 31
* @param two     texte a afficher si 32
* @param three   texte a afficher si 33
* @param four    texte a afficher si 34
* @param five    texte a afficher si 35
* @param six     texte a afficher si 36
* @param seven   texte a afficher si 37
* @param eight   texte a afficher si 38
* @param nine    texte a afficher si 39
* @param forty   texte a afficher si 40
* @param fortyOne texte a afficher si 41
*/
void checkThirtyOneUtilFortyOne(unsigned char** message, int* i, char* one, char* two, char* three, char* four, char* five, char* six, char* seven, char* eight, char* nine, char* forty, char* fortyOne);

#endif
