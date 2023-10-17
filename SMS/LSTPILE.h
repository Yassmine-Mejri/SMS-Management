#ifndef LSTPILE_H_INCLUDED
#define LSTPILE_H_INCLUDED


#define LongMax1 100 /* longueur maximale d'une pile */

#include"ELTPILE.h" 

typedef struct {
ELEMENT_PILE elements[LongMax1]; /* tableau automatique */
int Sommet; /* indice du Sommet de la Pile */
} laStruct_PILE,*PILE;


#endif