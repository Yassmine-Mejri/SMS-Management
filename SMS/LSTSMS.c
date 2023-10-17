#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>

#include"SMSPRIMLST.h"
#include"SMSPRIMELT.h"

LISTE_SMS listeCreer_SMS(void)
{
    LISTE_SMS L;
    L = (LISTE_SMS) malloc(sizeof(laStructSMS));
    if(!L)
    {
        printf(" \nProbleme de memoire") ;
        exit(0) ;
    }
  L->lg = 0;
  return(L);
}


void listeDetruire_SMS(LISTE_SMS L)
{
    int i;
    for(i = 1;i <= L->lg; i++)
    {
        elementDetruire_SMS(L->elements[i]);
    }
   free(L);
}


int inserer_SMS (LISTE_SMS L, ELEMENT_SMS e, int pos)
{
    int i;
    int succee=1;
    if (estSaturee_SMS(L))
    {
        printf ("\nListe d'sms est saturee");
        succee=0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg + 1))
        {
            printf ("\nPosition invalide");
            succee=0;
        }
        else
        {
            for(i = L->lg; i>= pos; i--)
            elementAffecter_SMS(&L->elements[i+1], L->elements[i]);
            elementAffecter_SMS(&L->elements[pos], e);
            (L->lg)++;
        }
    }
 return(succee);
}


int supprimer_SMS (LISTE_SMS L, int pos )
{
    int i;
    int succee=1;
    if (estVide_SMS(L))
    {
        printf ("\nListe vide");
        succee=0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg))
        {
            printf ("\nPosition invalide");
            succee=0;}
       else
        {
            elementDetruire_SMS(L->elements[pos]);
            for(i=pos;i<=L->lg;i++)
            elementAffecter_SMS(&L->elements[i], L->elements[i+1]);
            (L->lg)--;
        }
   }
  return(succee);
}


ELEMENT_SMS recuperer_SMS(LISTE_SMS L, int pos)
{
    ELEMENT_SMS elt= elementCreer_SMS();
    if (estVide_SMS(L))
        printf ("\nListe vide");
    else
    {
        if ((pos < 1) || (pos > L->lg))
            printf (" \nPosition invalide");
       else
            elt=(L->elements[pos]);
    }
  return(elt);
}


LISTE_SMS listeCopier_SMS(LISTE_SMS L)
{
    LISTE_SMS LR = listeCreer_SMS();
    int i;
    ELEMENT_SMS elt;
    for(i = 1;i <= L->lg; i++)
    {
        elt=elementCreer_SMS();
        elementCopier_SMS(&elt, recuperer_SMS(L,i));
        inserer_SMS(LR, elt, i);
    }
  return LR;
}



int listeComparer_SMS (LISTE_SMS L1,LISTE_SMS L2 )
{
    int test= 1;
    int i=1;
    if (listeTaille_SMS(L1) != listeTaille_SMS(L2))
        test= 0;
   while ((i<=listeTaille_SMS(L1)) && (test))
   {
        if (elementComparer_SMS(recuperer_SMS(L1,i),recuperer_SMS(L2,i))!=0)
            test=0;
     i++;
   }
 return test;
}


void listeAfficher_SMS(LISTE_SMS L)
{
    int i;
    for(i = 1; i <= L->lg; i++){
    printf("\n     SMS N: %i",i);
    elementAfficher_SMS(L->elements[i]);
    }
}


int estVide_SMS(LISTE_SMS L)
{
    return (L->lg == 0);
}



int estSaturee_SMS(LISTE_SMS L)
{
    return (L->lg == LongMax);
}


int listeTaille_SMS(LISTE_SMS L)
{
    return (L->lg);
}

