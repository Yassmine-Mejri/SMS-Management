#ifndef CONTPRIMELT_H_INCLUDED
#define CONTPRIMELT_H_INCLUDED


#include"ELTCONT.h"


ELEMENT_CONT elementCreer_CONT (void);
void elementDetruire_CONT (ELEMENT_CONT );
void elementAffecter_CONT(ELEMENT_CONT * , ELEMENT_CONT );
void elementCopier_CONT(ELEMENT_CONT * , ELEMENT_CONT );
void elementLire_CONT(ELEMENT_CONT * );
void elementAfficher_CONT(ELEMENT_CONT );
//int elementComparer_CONT(ELEMENT_CONT , ELEMENT_CONT );



#endif // CONTPRIMELT_H_INCLUDED
