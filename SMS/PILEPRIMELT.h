#ifndef PILEPRIMELT_H_INCLUDED
#define PILEPRIMELT_H_INCLUDED

#include"ELTPILE.h"


ELEMENT_PILE elementCreer_PILE (void);
void elementDetruire_PILE (ELEMENT_PILE );
void elementAffecter_PILE(ELEMENT_PILE * , ELEMENT_PILE );
void elementCopier_PILE(ELEMENT_PILE * , ELEMENT_PILE );
void elementLire_PILE(ELEMENT_PILE * );
void elementAfficher_PILE(ELEMENT_PILE );
int elementComparer_PILE(ELEMENT_PILE , ELEMENT_PILE );

#endif