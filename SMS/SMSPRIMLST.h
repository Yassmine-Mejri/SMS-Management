#ifndef SMSPRIMLST_H_INCLUDED
#define SMSPRIMLST_H_INCLUDED

#include"LSTSMS.h"
#include"ELTSMS.h"

LISTE_SMS listeCreer_SMS(void);
void listeDetruire_SMS(LISTE_SMS);
int estVide_SMS(LISTE_SMS);
int estSaturee_SMS(LISTE_SMS);
int listeTaille_SMS(LISTE_SMS);
ELEMENT_SMS recuperer_SMS(LISTE_SMS, int);
int inserer_SMS(LISTE_SMS, ELEMENT_SMS,int);
int supprimer_SMS(LISTE_SMS, int);
void listeAfficher_SMS(LISTE_SMS);
LISTE_SMS listeCopier_SMS(LISTE_SMS);
int listeComparer_SMS(LISTE_SMS, LISTE_SMS);

#endif // SMSPRIMLST_H_INCLUDED
