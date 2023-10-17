#ifndef LSTCONT_H_INCLUDED
#define LSTCONT_H_INCLUDED


#include"ELTCONT.h"

typedef struct structNoeudCONT
{
ELEMENT_CONT info;
struct structNoeudCONT * suivant;
}structNoeudCONT, * NOEUD_CONT;


typedef struct
{
NOEUD_CONT tete;
int lg;
}
laStructCONT,*LISTE_CONT;

#endif // LSTCONT_H_INCLUDED
