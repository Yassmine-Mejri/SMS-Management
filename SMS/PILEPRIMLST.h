#ifndef PILEPRIMLST_H_INCLUDED
#define PILEPRIMLST_H_INCLUDED

#include"LSTPILE.h"
#include"ELTPILE.h"


PILE PileCreer(void);
void PileDetruire(PILE);
int EstVide_PILE(PILE);
int EstSaturee_PILE(PILE);
int PileTaille(PILE);
ELEMENT_PILE Sommet(PILE);
int Empiler(PILE, ELEMENT_PILE);
ELEMENT_PILE Depiler(PILE);
void PileAfficher(PILE);
PILE PileCopier(PILE);
int PileComparer(PILE, PILE);

#endif


