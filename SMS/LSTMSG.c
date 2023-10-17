#include"stdlib.h"
#include"stdio.h"
#include"string.h"


#include"MSGPRIMLST.h"
#include"MSGPRIMELT.h"


NOEUD_MSG noeudCreer_MSG(ELEMENT_MSG e)
{
  NOEUD_MSG n;
  n =(NOEUD_MSG)malloc(sizeof(structNoeudMSG));
  if(!n)
    printf ("\nPlus d'espace");
  else{
    elementAffecter_MSG (&n->info, e);
    n->suivant = NULL;
    n->precedent = NULL;
  }
 return n;
}


void noeudDetruire_MSG(NOEUD_MSG n)
{
  elementDetruire_MSG (n->info);
  free(n);
}


int inserer_MSG (LISTE_MSG L, ELEMENT_MSG e, int pos)
{
   int succee=1;
   int i;
   NOEUD_MSG n, p, q;
  if (estSaturee_MSG (L))
   {
     printf ("\nListe msg est saturee");
     succee=0;}
     
   else
   {
   
   
        if ((pos < 1) || (pos > L->lg + 1))
        {
         printf ("\nPosition invalide");
         succee=0;
        }
        else
        {
         n=noeudCreer_MSG (e);
            if (L->lg == 0)
            {
             L->tete = n;
             L->queue = n;
            }
            else
            {
                if (pos == 1) /*insertion en t�te de liste*/
                {
                 L->tete->precedent = n;
                 n->suivant=L->tete;
                 L->tete = n;
                }
                else
                {
                     if (pos == (L->lg +1)) /* ajout � la fin */
                    {
                     L->queue->suivant = n;
                     n->precedent = L->queue;
                     L->queue = n;
                    }
                    else
                    {
                     q= L->tete;
                        for (i=1; i<pos; i++)
                        {
                         p = q;
                         q = q->suivant;
                        }
                     /* q d�signe l��l�ment de rang pos et p son pr�d�cesseur*/
                     p->suivant=n;
                     n->precedent =p;
                     n->suivant=q;
                     q->precedent =n;
                    }
                }
            }
         (L->lg)++;
        }
    }
 return succee;
}


int supprimer_MSG (LISTE_MSG L, int pos )
{
    int i;
    int succee=1;
    NOEUD_MSG p, q;
    if (estVide_MSG(L))
    {
     printf ("\nListe vide");
     succee=0;}
    else
    {
        if ((pos < 1) || (pos > L->lg))
        {
            printf ("\nPosition invalide");
            succee=0;
        }
        else
        {
            if (L->lg ==1) /* un seul element donc pos == 1*/
            {
                q=L->tete;
                L->tete = NULL;
                L->queue = NULL;
            }
            else
            {
                if (pos == 1) /*suppression en t�te de liste*/
                {
                    q=L->tete;
                    L->tete=L->tete->suivant;
                    L->tete->precedent = NULL;
                }
                else
                {
                    if (pos == L->lg)
                    {
                        q=L->queue;
                        L->queue = L->queue->precedent;
                        L->queue->suivant = NULL;
                    }
                    else
                    {
                        q= L->tete;
                        for (i=1; i<pos; i++)
                        q->suivant->precedent = p;
                        p->suivant=q->suivant;
                    }
                }
            }
        noeudDetruire_MSG(q);
        (L->lg)--;
        }
    }
  return succee;
}


int estVide_MSG(LISTE_MSG L)
{
    return (L->lg == 0);
}

int estSaturee_MSG(LISTE_MSG L)
{
    NOEUD_MSG temp;
    int saturee = 1; /* on suppose m�moire satur�e */
    temp = (NOEUD_MSG)malloc(sizeof(structNoeudMSG));
    if (temp != NULL)
    {
        saturee = 0; /* m�moire non satur�e */
        free(temp);
    }
    return saturee;
}

int listeTaille_MSG(LISTE_MSG L)
{
    return (L->lg);
}


ELEMENT_MSG recuperer_MSG (LISTE_MSG L, int pos)
{
    /* s'il ya une erreur on affiche un message et on
    retourne un element vide */
    ELEMENT_MSG elt = elementCreer_MSG();
    int i;
    NOEUD_MSG p;
    if (estVide_MSG (L))
        printf("\nListe vide");
    else
    {
        if ((pos < 1) || (pos > L->lg))
            printf("\nPosition invalide");
        else
        {
            p = L->tete;
            for (i = 1; i < pos; i++)
                p = p->suivant;
            elementAffecter_MSG (&elt, p->info);
        }
    }
    return (elt);
}

LISTE_MSG listeCreer_MSG (void)
{
    LISTE_MSG L;
    L = (LISTE_MSG )malloc(sizeof(laStructMSG ));
    if (!L)
        printf("\nProbleme de memoire");
    else
    {
        L->lg = 0;
        L->tete = NULL; /* initialiser la t�te */
    }
    return (L);
}

void listeDetruire_MSG (LISTE_MSG L)
{
    int i;
    NOEUD_MSG p, q;
    q = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        p = q;
        q = q->suivant;
        noeudDetruire_MSG (p);
    }
    free(L);
}

void listeAfficher_MSG (LISTE_MSG L)
{
    int i = 1;
    NOEUD_MSG p;
    p = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        elementAfficher_MSG  (p->info);
        p = p->suivant;
    }
}

LISTE_MSG listeCopier_MSG (LISTE_MSG L)
{
    LISTE_MSG LR = listeCreer_MSG ();
    int i;
    ELEMENT_MSG elt;
    for (i = 1; i <= L->lg; i++)
    {
        elt = elementCreer_MSG ();
        elementCopier_MSG (&elt, recuperer_MSG (L, i));
        inserer_MSG (LR, elt, i);
    }
    return LR;
}

int listeComparer_MSG (LISTE_MSG L1, LISTE_MSG L2)
{
    int test = 1;
    int i = 1;
    if (listeTaille_MSG (L1) != listeTaille_MSG (L2))
        test = 0;
    while ((i <= listeTaille_MSG(L1)) && (test))
    {
        if (elementComparer_MSG (recuperer_MSG(L1, i), recuperer_MSG(L2, i)) != 0)
            test = 0;
        i++;
    }
    return test;
}
