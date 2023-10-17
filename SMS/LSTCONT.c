#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>


#include"CONTPRIMLST.h"
#include"CONTPRIMELT.h"




NOEUD_CONT noeudCreer_CONT(ELEMENT_CONT e)
{
    NOEUD_CONT n;
    n = (NOEUD_CONT)malloc(sizeof(structNoeudCONT));
    if (!n)
        printf("\nPlus d'espace");
    else
    {
        elementAffecter_CONT(&n->info, e);
        n->suivant = NULL;
    }
    return n;
}

void noeudDetruire_CONT(NOEUD_CONT n)
{
    elementDetruire_CONT(n->info);
    free(n);
}

int estVide_CONT(LISTE_CONT L)
{
    return (L->lg == 0);
}

int estSaturee_CONT(LISTE_CONT L)
{
    NOEUD_CONT temp;
    int saturee = 1; /* on suppose m�moire satur�e */
    temp = (NOEUD_CONT)malloc(sizeof(structNoeudCONT));
    if (temp != NULL)
    {
        saturee = 0; /* m�moire non satur�e */
        free(temp);
    }
    return saturee;
}

int listeTaille_CONT(LISTE_CONT L)
{
    return (L->lg);
}

int inserer_CONT(LISTE_CONT L, ELEMENT_CONT e)
{
  int i = 1,succee = 0;
    NOEUD_CONT n,q,p;
    p = L->tete;
    q = p;
    n = noeudCreer_CONT(e);
    if (estVide_CONT(L)) {
        n->suivant = L->tete;
        L->tete = n;
        (L->lg)++;
        succee = 1;
    } else {
        do {
            if (elementComparer_CONT(e,p->info) < 0) 
            {
                if (i == 1) 
                {
                    n->suivant = L->tete;
                    L->tete = n;
                    (L->lg)++;
                    succee = 1;
                } else 
                {
                    q->suivant = n;
                    n->suivant = p;
                    (L->lg)++;
                    succee = 1;
                }
            }   
            //else 
            //{
            //    q->suivant = n;
            //    n->suivant = p;
            //    (L->lg)++;
            //    succee = 1;
            //}
         q = p;
         p = p->suivant;
         i++;
        } while(p && succee == 0);
        
        if (succee == 0) {
            q->suivant = n;
            (L->lg)++;
            succee = 1;
        }
    }
    return succee;
}

int supprimer_CONT(LISTE_CONT L, int pos)
{
    int i;
    int succee = 1;
    NOEUD_CONT p, q;
    if (estVide_CONT(L))
    {
        printf("\nListe vide");
        succee = 0;
    }
    else
    {
        if ((pos < 1) || (pos > L->lg))
        {
           // printf("\nPosition invalide");
            succee = 0;
        }
        else
        {
            q = L->tete;
            /*suppression en t�te de liste*/
            if (pos == 1)
                L->tete = L->tete->suivant;
            else
            { /*cas g�n�ral (pos > 1) */
                for (i = 1; i < pos; i++)
                {
                    p = q;
                    q = q->suivant;
                }
                p->suivant = q->suivant;
            }
            // q d�signe l��l�ment de rang pos et p son pr�d�cesseur
            noeudDetruire_CONT(q);
            (L->lg)--;
        }
    }
    return succee;
}

ELEMENT_CONT recuperer_CONT(LISTE_CONT L, int pos)
{
    /* s'il ya une erreur on affiche un message et on
    retourne un element vide */
    ELEMENT_CONT elt = elementCreer_CONT();
    int i;
    NOEUD_CONT p;
    if (estVide_CONT(L))
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
            elementAffecter_CONT(&elt, p->info);
        }
    }
    return (elt);
}

LISTE_CONT listeCreer_CONT(void)
{
    LISTE_CONT L;
    L = (LISTE_CONT)malloc(sizeof(laStructCONT));
    if (!L)
        printf("\nProbleme de memoire");
    else
    {
        L->lg = 0;
        L->tete = NULL; /* initialiser la t�te */
    }
    return (L);
}

void listeDetruire_CONT(LISTE_CONT L)
{
    int i;
    NOEUD_CONT p, q;
    q = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        p = q;
        q = q->suivant;
        noeudDetruire_CONT(p);
    }
    free(L);
}

void listeAfficher_CONT(LISTE_CONT L)
{
    int i = 1;
    NOEUD_CONT p;
    p = L->tete;
    for (i = 1; i <= L->lg; i++)
    {
        elementAfficher_CONT(p->info);
        p = p->suivant;
    }
}

LISTE_CONT listeCopier_CONT(LISTE_CONT L)
{
    LISTE_CONT LR = listeCreer_CONT();
    int i;
    ELEMENT_CONT elt;
    for (i = 1; i <= L->lg; i++)
    {
        elt = elementCreer_CONT();
        elementCopier_CONT(&elt, recuperer_CONT(L, i));
        inserer_CONT(LR, elt);
    }
    return LR;
}

int listeComparer_CONT(LISTE_CONT L1, LISTE_CONT L2)
{
    int test = 1;
    int i = 1;
    if (listeTaille_CONT(L1) != listeTaille_CONT(L2))
        test = 0;
    while ((i <= listeTaille_CONT(L1)) && (test))
    {
        if (elementComparer_CONT(recuperer_CONT(L1, i), recuperer_CONT(L2, i)) != 0)
            test = 0;
        i++;
    }
    return test;
}
