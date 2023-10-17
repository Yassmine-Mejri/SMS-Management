#ifndef LSTMSG_H_INCLUDED
#define LSTMSG_H_INCLUDED

#include"ELTMSG.h"

typedef struct structNoeudMSG
{
ELEMENT_MSG info;
struct structNoeudMSG * suivant;
struct structNoeudMSG * precedent;
}structNoeudMSG, * NOEUD_MSG;

typedef struct
{
NOEUD_MSG tete;
NOEUD_MSG queue;
int lg;
}laStructMSG,*LISTE_MSG;


#endif // LSTMSG_H_INCLUDED
