#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>

#include"PILEPRIMLST.h"
#include"PILEPRIMELT.h"

#define LongMax 8 

PILE PileCreer(void) {
PILE P;

P = (PILE) malloc(sizeof(laStruct_PILE));
if(!P) {
printf(" \nProblème de mémoire") ;
}
else P->Sommet = 0; //puisque l’indice le plus faible est 1
return(P);
}


void PileDetruire(PILE P)
{
int i; 
for(i = 1; i <= P->Sommet; i++) 
elementDetruire_PILE(P->elements[i]);
free(P);
}

void PileAfficher(PILE P) 
{
int i;
for(i = P->Sommet; i >= 1; i--) 
elementAfficher_PILE(P->elements[i]);
}


int EstVide_PILE(PILE P) 
{
return (P->Sommet == 0);
}


int EstSaturee_PILE(PILE P) 
{
return (P->Sommet == LongMax);
}


int PileTaille(PILE P) 
{
return (P->Sommet);
}

int Empiler (PILE P, ELEMENT_PILE e) {
int succes=1;
if (EstSaturee_PILE(P)){ 
printf ("\n Pile saturée"); 
succes=0;}
else
{
(P->Sommet)++; 
elementAffecter_PILE(&P->elements[P->Sommet], e);
}
return(succes);
}

ELEMENT_PILE Depiler (PILE P ) 
{
ELEMENT_PILE elt = elementCreer_PILE();
if (EstVide_PILE(P)) {
printf ("\n Pile vide"); 
}
else {
elementCopier_PILE(&elt, (P->elements)[P->Sommet]);
elementDetruire_PILE(P->elements[P->Sommet]);
(P->Sommet)--;
}
return (elt);
}

ELEMENT_PILE Sommet (PILE P) 
{
ELEMENT_PILE elt= elementCreer_PILE();
if (EstVide_PILE(P)) 
printf (" \n Pile vide"); 
else 
elt = (P->elements[P->Sommet]);
return(elt);
}
