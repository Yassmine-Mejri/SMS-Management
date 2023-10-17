#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include <math.h>

#include"SMSPRIMELT.h"



ELEMENT_SMS elementCreer_SMS(void)
{
    ELEMENT_SMS L;
    L = (ELEMENT_SMS) malloc(sizeof(SMS));
    return L;
}

void elementDetruire_SMS (ELEMENT_SMS L)
{
    free (L);
}

void elementLire_SMS(ELEMENT_SMS * elt)
{
// ba3edd ma tkaseem 
//(*elt)->taille=strlen((*elt)->texte)-1;
}


void elementAfficher_SMS(ELEMENT_SMS elt)
{   printf("\n------------------SMS----------------------");
    printf("\n     SMS: %s \n     Taille: %i",elt->texte,elt->taille);
    printf("\n");
}


void elementAffecter_SMS(ELEMENT_SMS* e1, ELEMENT_SMS e2)
{
   *e1 = e2 ;
}


void elementCopier_SMS(ELEMENT_SMS *e1, ELEMENT_SMS e2)
{
    strcpy((*e1)->texte, e2->texte);
    (*e1)->taille = e2->taille;
}


int elementComparer_SMS(ELEMENT_SMS e1, ELEMENT_SMS e2)
{
    return ((e1->taille) - (e2->taille)) ;
}

