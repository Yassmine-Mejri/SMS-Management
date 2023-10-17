#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


#include"PILEPRIMELT.h"

ELEMENT_PILE elementCreer_PILE (void) 
{
    ELEMENT_PILE L;
    L = (ELEMENT_PILE) malloc(sizeof(Pile)); 
    return L;
}

void elementDetruire_PILE (ELEMENT_PILE L) 
{
    free (L);
}


void elementLire_PILE(ELEMENT_PILE *elt) 
{
}



void elementAfficher_PILE(ELEMENT_PILE elt) 
{ 
    printf("\nChaine du caractere = %s", elt->texte1);
}



void elementAffecter_PILE(ELEMENT_PILE* e1, ELEMENT_PILE e2) 
{
   *e1 = e2 ; 
}


void elementCopier_PILE(ELEMENT_PILE *e1, ELEMENT_PILE e2) 
{
   strcpy((*e1)->texte1,e2->texte1);
}


int elementComparer_PILE(ELEMENT_PILE e1, ELEMENT_PILE e2) 
{

    return strcmp(e1->texte1,e2->texte1);
}
