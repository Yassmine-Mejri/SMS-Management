#ifndef MSGPRIMELT_H_INCLUDED
#define MSGPRIMELT_H_INCLUDED


#include"ELTMSG.h"

// primitive element date

void elementLire_DATE(DATE * );
void elementlire_date2(DATE * );
void elementAfficher_DATE(DATE );
int elementComparer_DATE(DATE , DATE );


// primitive element HEURE

void elementLire_HEURE(HEURE * );
void elementAfficher_HEURE(HEURE );
int elementComparer_HEURE(HEURE , HEURE );

//primitive element msg
ELEMENT_MSG elementCreer_MSG (void);
void elementDetruire_MSG (ELEMENT_MSG );
void elementAffecter_MSG(ELEMENT_MSG * , ELEMENT_MSG );
void elementCopier_MSG(ELEMENT_MSG * , ELEMENT_MSG );
void elementLire_MSG(ELEMENT_MSG * );
void elementAfficher_MSG(ELEMENT_MSG );
int elementComparer_MSG(ELEMENT_MSG , ELEMENT_MSG );

#endif // MSGPRIMELT_H_INCLUDED
