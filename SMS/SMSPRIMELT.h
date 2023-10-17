#ifndef SMSPRIMELT_H_INCLUDED
#define SMSPRIMELT_H_INCLUDED

#include"ELTSMS.h"


ELEMENT_SMS elementCreer_SMS (void);
void elementDetruire_SMS (ELEMENT_SMS );
void elementAffecter_SMS(ELEMENT_SMS * , ELEMENT_SMS );
void elementCopier_SMS(ELEMENT_SMS * , ELEMENT_SMS );
void elementLire_SMS(ELEMENT_SMS * );
void elementAfficher_SMS(ELEMENT_SMS );
int elementComparer_SMS(ELEMENT_SMS , ELEMENT_SMS );


#endif // SMSPRIMELT_H_INCLUDED
