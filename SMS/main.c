#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


#include "SMSSDD.h"
#include "MSGSDD.h"
#include "CONTSDD.h"
#include "PILESDD.h"

typedef struct compteMot
{
  char * mot;
  int nbOcc;
}CompteMot;


int nbrmsg(LISTE_MSG L1, ELEMENT_CONT E1);
CONTACT lePlusContacte(LISTE_MSG L1, LISTE_CONT L2);
LISTE_CONT jamaisContactes(LISTE_MSG L1, LISTE_CONT L2);
LISTE_MSG messages_D1_D2(LISTE_MSG L, DATE D1, DATE D2);
ELEMENT_MSG messageLePlusLong(LISTE_MSG L);
PILE unigrammes(LISTE_MSG L, int M);
PILE bigrammes(LISTE_MSG L, int M);
//int nbr_occurence(char *mot,LISTE_MSG L);
//void REMPLIR_TAB (LISTE_MSG L,compteM *tab ,int taille);

enum {MAXLONGUEUR = 200};
/* Le tableau où seront rangées les structures de type CompteMot */
CompteMot *tableau;

/* Le nombre de mots*/
int nbMots = 0;

/* La taille du tableau contenant les mots */
int tailleTableau = 50;

char chercherIndice(char *, int *);
char placer(char *, int);




int main()
{
    int choix, M;
    LISTE_CONT repertoire = listeCreer_CONT();
    ELEMENT_CONT contact, contact1;
    LISTE_MSG boite_de_messagerie = listeCreer_MSG();
    ELEMENT_MSG message, message1;
    DATE D1, D2;

    FILE *fp,*fpp;
    char buffer[90];
    char recepteur[50], prix[4], date_envoi[10], heure_envoi[8], msg[1224], j[2], m[2], a[4], h[2], min[2], sec[2];
    char buff[1300];

    ELEMENT_SMS p ;
    ELEMENT_SMS sms ;
    LISTE_SMS l ;
    int i, x = 0, c = 0,taille;
    int nb_sms_std , nb_sms_sp;

    ELEMENT_PILE PI;
    PILE P = PileCreer();
    //char *mot;
    //compteM *tab ;

    int K;

    do
    {
        printf("\n");
        printf("\n");
        printf("\n---------------------------------------------------------------------");
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*--REPERTOIRE--*-*-*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n---------------------------------------------------------------------");
        printf("\n    1-Ajouter manuellement un contact au liste de repertoire");
        printf("\n    11-Ajouter automatiquement un contact au liste de repertoire");
        printf("\n    2-Afficher la repertoire  ");
        printf("\n    3-Afficher le contact le plus contactee");
        printf("\n    4-Afficher les contactes jamais contactee");
        printf("\n---------------------------------------------------------------------");
        printf("\n");
        printf("\n");
        printf("\n---------------------------------------------------------------------");
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*--BOITE-DE-RECEPTION--*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n---------------------------------------------------------------------");
        printf("\n    5-Envoyer un message manuellement  ");
        printf("\n    55-Envoyer un message automatiquement  ");
        printf("\n    6-Afficher la boite de messagerie  ");
        printf("\n    7-Afficher le message entre deux dates  ");
        printf("\n    8-Afficher le message le plus long");
        printf("\n---------------------------------------------------------------------");
        printf("\n");
        printf("\n");
        printf("\n---------------------------------------------------------------------");
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*--N-GRAMME--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n---------------------------------------------------------------------");
        printf("\n    9-Afficher les Unigrammes les plus envoyes");
        printf("\n    10-Afficher les Bigrammes les plus envoyes");
        printf("\n---------------------------------------------------------------------");
        printf("\n");
        printf("\n");
        printf("\n---------------------------------------------------------------------");
        printf("\n");
        printf("\n    Choisir une option svp:");
        scanf ("\n%i", &choix);
        printf("\n---------------------------------------------------------------------");
        printf("\n");

        //scanf("%i", &choix);

        switch (choix)
        {

        case 1:
            contact1 = elementCreer_CONT();
            elementLire_CONT(&contact1);
            inserer_CONT(repertoire, contact1);

            break;
        case 11:
            fp = fopen("contact.txt", "r");
            
            while (!feof(fp))
            {

                contact = elementCreer_CONT();

                fgets(buffer, 90, (FILE *)fp);
                printf("\n\n");
                printf("\n---------------------------------------------------------------------");
                printf("\n     contact: %s", buffer);

                strcpy(contact->nom, strtok(buffer, "/"));
                strcpy(contact->numero, strtok(NULL, "/"));
                strcpy(contact->email, strtok(NULL, "\n"));
                printf("\n     nom:%s \n     numero:%s \n     email:%s ", contact->nom, contact->numero, contact->email);
                printf("\n---------------------------------------------------------------------");

                inserer_CONT(repertoire, contact);
            }
            fclose(fp);

            break;

        case 2:
            listeAfficher_CONT(repertoire);
            break;

        case 3:
            printf("\n---------------------------------------------------------------------");
            printf("\n     Nom %s ", lePlusContacte(boite_de_messagerie, repertoire).nom);
            printf("\n     Numero %s ", lePlusContacte(boite_de_messagerie, repertoire).numero);
            printf("\n     Email %s ", lePlusContacte(boite_de_messagerie, repertoire).email);
            printf("\n---------------------------------------------------------------------");
            break;

        case 4:
            listeAfficher_CONT(jamaisContactes(boite_de_messagerie, repertoire));
            break;

        case 5:
            message1 = elementCreer_MSG();
            elementLire_MSG(&message1);
            inserer_MSG(boite_de_messagerie, message1, 1);
            break;

        case 6:
            listeAfficher_MSG(boite_de_messagerie);
            break;

        case 7:
            printf("\n---------------------------------------------------------------------");
            printf("\n     Donner le 1er date jj/mm/aaaa");
            elementlire_date2(&D1);
            printf("\n     Donner le 2eme date jj/mm/aaaa");
            elementlire_date2(&D2);
            listeAfficher_MSG(messages_D1_D2(boite_de_messagerie, D1, D2));
            printf("\n---------------------------------------------------------------------");
            break;

        case 8:
            elementAfficher_MSG(messageLePlusLong(boite_de_messagerie));
            break;

        case 9:
            /* printf("\nDonner le nombre du Unigramme");
             scanf("%i",&M);
             PileAfficher( unigrammes(boite_de_messagerie,  M));
            */
            elementLire_PILE(&PI);
            Empiler(P, PI);
            PileAfficher(P);

            break;

        case 10:
            /*
                printf("\nDonner le nombre du Bigramme");
                scanf("%i",&M);
                PileAfficher( bigrammes(boite_de_messagerie,  M));
                */
            break;

        case 55:
            fpp = fopen("message.txt", "r");

            while (!feof(fpp))
            {

                message = elementCreer_MSG();

                fgets(buff, 1300, (FILE *)fpp);
                printf("\n\n");
                printf("\n---------------------------------------------------------------------");
                printf("\n     msg.txt: \n%s", buff);
                printf("\n---------------------------------------------------------------------");
                printf("\n\n");

                strcpy(recepteur, strtok(buff, "/"));
                strcpy(message->recepteur, recepteur);
                printf("\n---------------------------------------------------------------------");
                printf("\n     recepteur: %s", recepteur);
                printf("\n");

                p = elementCreer_SMS();
                l = listeCreer_SMS();
               
                strcpy(msg, strtok(NULL, "/"));
                printf("\n     texte: \n%s",msg);
                printf("\n\n     taille de msg: %i", strlen(msg)-1);
                printf("\n");


                while (i <= strlen(msg) && x == 1)
                {
                    if (existe(msg[i]) == 1) // special
                    {
                        x = 1;
                    }
                    i++;
                }
                 
                printf("\n"); 
                printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                printf("\n*-*-*-*-*--VERIFICATION --*-*-*-*-*");
                printf("\n     type de sms: %i", x);
                if (x == 0)
                {
                    nb_sms_std = SMS_standard(msg);
                    printf("\n     nombre de sms: %i", nb_sms_std);
                    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    printf("\n\n");

                    if (nb_sms_std == 1)
                    {
                        sms = elementCreer_SMS();
                        strcpy(sms->texte, msg);
                        sms->taille = strlen(sms->texte);

                        inserer_SMS(l, sms, 1);
                        message->msg = listeCopier_SMS(l);

                
                    }
                    else
                    {

                        for (i = 1; i <= nb_sms_std; i++)
                        {

                            sms = elementCreer_SMS();
                            strncpy(sms->texte, msg + c, 153);
                            c = c + 153;
                            //printf("\nchaine jdida %s", msg);
                            sms->taille = strlen(sms->texte) ;

                            inserer_SMS(l, sms, i);
                            message->msg = listeCopier_SMS(l);
                            
                        }
                
                    }
                }
                 else if (x==1)
                {    
                    nb_sms_sp=SMS_special(msg);
                    printf("\n     nombre de sms: %i",nb_sms_sp);
                    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
                    printf("\n");

                    if (nb_sms_sp==1)
                    {    
                        sms = elementCreer_SMS();
                        strcpy(sms->texte,msg);
                        sms->taille=strlen(sms->texte);

                        inserer_SMS(l,sms,1);
                        message->msg = listeCopier_SMS(l);
             

                    }
                   else 
                    {
                        for (i=0;i<=nb_sms_sp;i++)
                        {

                            sms = elementCreer_SMS();
                            strncpy(sms->texte,msg + c,67);
                            c = c + 67;
                            sms->taille=strlen(sms->texte);

                            inserer_SMS(l,sms,i);
                            message->msg = listeCopier_SMS(l);
                        }

                    }
                }




                // date
                strcpy(j, strtok(NULL, "/"));
                message->date_envoi.jour = atoi(j);
                printf("\n     jour: %i", atoi(j));

                strcpy(m, strtok(NULL, "/"));
                message->date_envoi.mois = atoi(m);
                printf("\n     mois: %i", atoi(m));

                strcpy(a, strtok(NULL, "/"));
                message->date_envoi.annee = atoi(a);
                printf("\n     annee: %i", atoi(a));


                printf("\n");

                // heure
                strcpy(h, strtok(NULL, "/"));
                message->heure_envoi.heure = atoi(h);
                printf("\n     heure: %i", atoi(h));

                strcpy(min, strtok(NULL, "/"));
                message->heure_envoi.minute = atoi(min);
                printf("\n     minute: %i", atoi(min));

                strcpy(sec, strtok(NULL, "/"));
                message->heure_envoi.seconde = atoi(sec);
                printf("\n     seconde: %i", atoi(sec));

                printf("\n");
                
                // prix
                strcpy(prix, strtok(NULL, "\n"));
                message->prix = atof(prix);
                printf("\n     prix: %.3f", prix);
                printf("\n---------------------------------------------------------------------");
                printf("\n");

                inserer_MSG(boite_de_messagerie, message, 1);
            }

            fclose(fpp);

            break;

            case 111:
            break;

        case 44:
            //mot="mejri";
            //printf ("\n nbocc mejri %i",nbr_occurence(mot, boite_de_messagerie));
            //REMPLIR_TAB (boite_de_messagerie,tab ,taille);
            unigrammes(boite_de_messagerie, K);


            break;

        default:
            break;
        }

    } while (choix != -1);

    return 0;
}
// fonction qui compare les numeros et compte les messages repetees
int nbrmsg(LISTE_MSG L1, ELEMENT_CONT E1)
{
    NOEUD_MSG q = L1->tete;
    int compteur = 0;
    for (int i = 1; i <= L1->lg; i++)
    {
        if (strcmp(E1->numero, q->info->recepteur) == 0)
        {
            compteur++;
        }
        q = q->suivant;
    }
    return compteur;
}

// fonction le plus contacte
CONTACT lePlusContacte(LISTE_MSG L1, LISTE_CONT L2)
{
    LISTE_CONT lstplus_cont = listeCreer_CONT();
    ELEMENT_CONT plus_cont = elementCreer_CONT();
    ELEMENT_CONT e1, e2;
    int i, nbmax = -1;
    NOEUD_CONT q, p = L2->tete;
    for (i = 1; i <= L2->lg; i++)
    {
        int nb = nbrmsg(L1, recuperer_CONT(L2, i));
        if (nb > nbmax)
        {
            nbmax = nb;
        }
        p = p->suivant;
    }
    p = L2->tete;
    for (i = 1; i <= L2->lg; i++)
    {
        int nb = nbrmsg(L1, recuperer_CONT(L2, i));
        if (nb == nbmax)
        {
            elementCopier_CONT(&plus_cont, recuperer_CONT(L2, i));
            inserer_CONT(lstplus_cont, plus_cont);
        }
        p = p->suivant;
    }
    q = lstplus_cont->tete;
    e1 = recuperer_CONT(L2, 1);
    for (i = 2; i <= lstplus_cont->lg; i++)
    {
        e2 = recuperer_CONT(L2, i);
        if (strcmp(e1->nom, e2->nom) < 0)
        {
            e2 = e1;
            elementCopier_CONT(&plus_cont, e1);
        }
        else
        {
            e1 = e2;
            elementCopier_CONT(&plus_cont, e2);
        }
        q = q->suivant;
    }
    return *plus_cont;
}

LISTE_CONT jamaisContactes(LISTE_MSG L1, LISTE_CONT L2)
{
    LISTE_CONT non_cont = listeCreer_CONT();

    for (int i = 1; i <= L2->lg; i++)
    {
        if (nbrmsg(L1, recuperer_CONT(L2, i)) == 0)
        {
            inserer_CONT(non_cont, recuperer_CONT(L2, i));
        }
    }
    return non_cont;
}

LISTE_MSG messages_D1_D2(LISTE_MSG L, DATE D1, DATE D2)
{
    NOEUD_MSG p;
    LISTE_MSG liste_intervale = listeCreer_MSG();
    p = L->tete;
    int pos = 1;
    for (int i = 1; i <= L->lg; i++)
    {
        if (elementComparer_DATE(p->info->date_envoi, D1) == 1 && elementComparer_DATE(p->info->date_envoi, D2) == -1)
        {
            inserer_MSG(liste_intervale, recuperer_MSG(L, i), pos);
            pos++;
        }
        p = p->suivant;
    }
    return liste_intervale;
}

ELEMENT_MSG messageLePlusLong(LISTE_MSG L)
{
    ELEMENT_MSG plus_LONG = elementCreer_MSG();
    NOEUD_MSG p;
    p = L->tete;
    int i;
    ELEMENT_SMS s ;
    s = p->info->msg->elements[i];
    int nbmax = -1;
    int nbmax2 = -1;
    for (i = 1; i <= L->lg; i++)
    {
        if (p->info->msg->lg > nbmax)
        {
            nbmax = p->info->msg->lg;
        }
        else if (s->taille > nbmax2)
        {
            nbmax2 = s->taille;
        }
        elementAffecter_MSG(&plus_LONG, recuperer_MSG(L, i));
        p = p->suivant;
    }
    return plus_LONG;
}

/*PILE unigrammes(LISTE_MSG L,int M){
    PILE p;
    int x,i,t;
    ELEMENT_PILE e;
    compteM *tab ;
    REMPLIR_TAB(L,tab,t);
    p=PileCreer();
    e=elementCreer_PILE();
    for (i=0;i<=M;i++){
        x=maxgramme(L,t);
        e->texte1=tab[x].mot;
        Empiler(p,e);
        tab[x].occ=0;
    }
}
PILE bigrammes(LISTE_MSG L, int M)
{
}

int maxgramme (LISTE_MSG L,int t){
   compteM *tab;
   int max=tab[0].occ;
   int i ;
   for (i=1;i<=t;i++){
       if (max<tab [i].occ){
        return i;   
       }
   }
}
*/
//void REMPLIR_TAB (LISTE_MSG L,compteM *tab ,int taille)
//{
//    NOEUD_MSG p;
//    p=L->tete;
//    int i,k,Z;
//    char *ch,*MOT;
//    
//    for(i=0;i<=L->lg;i++)
//    {
//        for(k=1;k<=p->info->msg->lg;k++)
//        {
//            ch = p->info->msg->elements[k]->texte;
//            MOT=strtok(ch, " []{}\\\n{}()*/\"#.;:,\t'?!-<>&+=");
//              while(MOT!=NULL)
//              { 
//                tab[taille].mot=MOT;
//                Z=nbr_occurence(MOT,L);
//                tab[taille].occ=Z;
//                MOT=strtok(NULL, " []{}\\\n{}()*/\"#.;:,\t'?!-<>&+=");
//              }                                                                                  
//              printf ("\n MOT : %s OCC : %i",tab[taille].mot,tab[taille].occ);
//              taille++;
//        }
//        p=p->suivant;
//    }
//}
//
//
//int nbr_occurence(char *mot,LISTE_MSG L)
//{
//    NOEUD_MSG p;
//    char *ch,*x;
//    int k,i,j,nbr=0;
//    p=L->tete;
//
//    for (i=1;i<=L->lg;i++)
//    {   
//        for(k=1;k<=p->info->msg->lg;k++)
//        {
//            ch = p->info->msg->elements[k]->texte;
//            x=strtok(ch, " []{}\\\n{}()*/\"#.;:,\t'?!-<>&+=");
//              while(x!=NULL)
//              {    
//                  //printf ("\nchaine m liste  :%s",ch);
//                   if(strcmp(x,mot)==0)
//                   {
//                       nbr++; 
//                   }
//                  // printf ("\nnbrocc%i DU MOT %s",nbr,x);
//                   x=strtok(NULL, " []{}\\\n{}()*/\"#.;:,\t'?!-<>&+=");  
//              }          
//        }
//        p=p->suivant;
//    }
//
//    return nbr;
//}


char chercherIndice(char *mot, int *adrIndice)
{
  int gauche = 0,  droite = nbMots - 1;
  int milieu;
  int compare;
  
  while (gauche <= droite)
    {
      milieu = (gauche + droite) / 2;
      compare = strcmp(mot, tableau[milieu].mot);
      if (compare < 0) 
         droite = milieu - 1;
      else if (compare > 0) 
          gauche = milieu + 1;
      else 
	{
	  *adrIndice = milieu;
	  return 1;
	}
    }
  *adrIndice = gauche;
  return 0;
}



char placer(char  *mot, int indice)
{
  int i;
  char *leMot; 

  leMot = (char *) malloc((strlen(mot) + 1)*sizeof(char));
  if (leMot == NULL) 
    {
      printf("problème d'allocation\n");
      exit(1);
    }
  strcpy(leMot, mot); 
  if (nbMots == tailleTableau) 
    {    
      printf("Le tableau est plein, nous reallouons\n");
      tailleTableau += 50;
      tableau = (CompteMot *) realloc(tableau,tailleTableau * sizeof(CompteMot));
      if (tableau == NULL) 
	{
	  printf("problème d'allocation\n");
	  exit(1);
	}
    }
  for (i = nbMots; i > indice; i--)  
  tableau[i] = tableau[i - 1];
  tableau[indice].mot = leMot;
  tableau[indice].nbOcc = 1;
  nbMots++;
  return 1;
}



PILE unigrammes(LISTE_MSG L,int M)
{
     NOEUD_MSG p;
     char *ch,*x;
     int k,i;
     p=L->tete;
     char ligne[MAXLONGUEUR], *s, *mot;
     int indice;


      for (i=1;i<=L->lg;i++)
        {
            for(k=1;k<=p->info->msg->lg;k++){
            printf("\ndkhal for");
            ch = p->info->msg->elements[k]->texte;
            x=strtok(ch, " []{}\\\n{}()*/\"#.;:,\t'?!-<>&+=");
            printf("\nx %s",x);
              while(x!=NULL)
              {
                  printf("\ndkhal while");
                  printf("\ndkhal if %s",chercherIndice(mot,&indice));
                  if (!chercherIndice(mot, &indice)) {
                  printf("\ndkhal if %s",chercherIndice(mot,&indice));
                 placer(mot, indice);
                 printf("\n mot %s indice %i",mot,indice);
                  }
	             else 
                  tableau[indice].nbOcc++;
	             s = NULL;

         
              }
            }
              p=p->suivant;
        }
         printf("\n");
        for (i = 0; i < nbMots; i++)
        printf("%s : %d fois\n", tableau[i].mot, tableau[i].nbOcc); 
}