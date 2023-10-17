  #include"stdlib.h"
#include"stdio.h"
#include "string.h"
#include <time.h>


#include"MSGPRIMELT.h"


// primitive date

void elementlire_date2(DATE * e)
{   do{
    printf ("\n     Donner le jour :");
    scanf("%i",&(*e).jour);
    }while ((*e).jour<1 ||  (*e).jour>31);

   do{
    printf ("\n     Donner le mois :");
    scanf("%i",&(*e).mois);
   }while ((*e).mois<1 || (*e).mois>12);


   do{
    printf ("\n     Donner l'annee :");
    scanf("%i",&(*e).annee);
   }while ((*e).annee<2000 || (*e).annee>2022);
}

void elementLire_DATE(DATE * elt)
{
  
 time_t now;
 now = time(NULL);
 struct tm *local = localtime(&now);
(*elt).jour=local->tm_mday; 
(*elt).mois= local->tm_mon + 1;
(*elt).annee=  local->tm_year + 1900 ;

}


void elementAfficher_DATE(DATE elt)
{
    printf("\n     La date : %02i/%02i/%i ", elt.jour, elt.mois,elt.annee);
}


int elementComparer_DATE(DATE e1, DATE e2)
{
  if(e1.annee==e2.annee)
  {
      if(e1.mois==e2.mois)
      {
          if(e1.jour==e2.jour)
          {
              return 0; // kifkif
          }
          else if (e1.jour>e2.jour)
          {
              return 1; //  1er date  akber
          }
          else return -1; // 2eme date akber
      }
      else if (e1.mois>e2.mois)
      {
          return 1; // mois lowem akber
      }
      else return -1; // mois theni akber
  } 
  else if (e1.annee>e2.annee)
  {
      return 1; // annee lowel akber
  }
  else return -1; // annee theni akber
}


// primitive Heure


void elementLire_HEURE(HEURE *elt)
{
 
  time_t now1;
  now1 = time(NULL);
 struct tm *local = localtime(&now1);
(*elt).heure= local->tm_hour ;
(*elt).minute= local->tm_min;
(*elt).seconde=  local->tm_sec;



}


void elementAfficher_HEURE(HEURE elt)
{
    printf("\n     L'heure : %02i:%02i:%02i", elt.heure, elt.minute,elt.seconde);
}


int elementComparer_HEURE(HEURE e1, HEURE e2)
{
    return ((e1.heure)-(e2.heure));
}



// primitive msg elt

int existe(char caractere)
{
    //char caractere_standard[131]={'A' ,'B', 'C', 'D','E', 'F', 'G' ,'H', 'I', 'J', 'K', 'L' ,'M ','N', 'O','P','Q' ,'R', 'S' ,'T','U', 'V','W' ,'X', 'Y', 'Z','a' ,'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j', 'k', 'l', 'm', 'n' ,'o' ,'p','q', 'r' ,'s', 't', 'u' ,'v', 'w', 'x','y' ,'z','@', '£', '$' ,'¥ ','è', 'é' ,'ù' ,'ì' ,'ò', 'Ç', 'Ø', 'ø' ,'Å' ,'å', 'Δ' ,'_', 'Φ' ,'Γ', 'Λ', 'Ω', 'Π', 'Ψ', 'Σ', 'Θ', 'Ξ', '^','{', '}' ,'[', '~', ']', '|', '€' ,'Æ', 'æ', 'ß', 'É', '!', '"', '#', '¤', '%', '&' ,'(' ,')', '*', '+', ',', '.', '/', '0', '1', '2', '3', '4' ,'5' ,'6' ,'7' ,'8' ,'9' ,':' ,';', '<','=', '>', '?', '¡', 'Ä', 'Ö', 'Ñ', 'Ü', '§', '¿', 'ä', 'ö', 'ñ', 'ü', 'à'};
    char caractere_standard [20]="c";
    int i,test =0;
    while(test==0 && i<=strlen(caractere_standard))
    {
       if (caractere_standard[i]==caractere)
       {
           test = 1 ; //special
       }
       i++;
    }
  return test;

}
int SMS_standard (char *ch)
{
      int i;
  if (strlen(ch)<=1224 && strlen(ch)>1071)
  {
     // 8sms
     return 8;
  }else if (strlen(ch)<=1071 && strlen(ch)>918)
  {
      // 7 sms
    return 7;
  }else if (strlen(ch)<=918 && strlen(ch)>765)
  {
      // 6 sms
     return 6;
  }else if (strlen(ch)<=765 &&strlen(ch)>612)
  {
      // 5 sms
    return 5;
  }else if (strlen(ch)<=612 && strlen(ch)>459)
  {
      // 4 sms
    return 4;
  }else if (strlen(ch)<=459 &&strlen(ch)>306)
  {
      // 3 sms
     return 3;
  }else if (strlen(ch)<=306 && strlen(ch)>160) 
  {
      // 2 sms
      return 2;

  }else
   { 
       // 1 sms 
       return 1;
  }

}

int SMS_special (char *ch )
{
   
  if (strlen(ch)<=536 && strlen(ch)>469)
  {
     // 8sms
     return 8;
  }else if (strlen(ch)<=469 && strlen(ch)>402)
  {
      // 7 sms
    return 7;
  }else if (strlen(ch)<=402 &&strlen(ch)>335)
  {
      // 6 sms
     return 6;
  }else if (strlen(ch)<=335 &&strlen(ch)>268)
  {
      // 5 sms
     return 5;
  }else if (strlen(ch)<=268 && strlen(ch)>201)
  {
      // 4 sms
     return 4;
  }else if (strlen(ch)<=201 &&strlen(ch)>134)
  {
      // 3 sms
     return 3;
  }else if (strlen(ch)<=134 && strlen(ch)>71)
  {
      // 2 sms
      return 2;
  }else
   {
       // 1 sms 
       return 1;
  }

}


int type_sms (LISTE_SMS l)
{ 
   char ch [1224];
    int x=0,i=0,c=0;
     printf ("\nDonner votre msg svp: ");
     fflush(stdin);
     fgets(ch,1224,stdin);
    while( i<=strlen(ch)&& x!=1)
    {      
        if (existe(ch[i])==1)//special
        {
            x = 1;
        }
        i++;
    }
 printf("\ntype %i",x);
    if (x==0)
    {

        int nb_sms_std=SMS_standard(ch); 
        printf("\nnb d'sms %i",nb_sms_std);
        if (nb_sms_std==1)
        {   
            ELEMENT_SMS sms = elementCreer_SMS();
            strcpy(sms->texte,ch);
            sms->taille=strlen(ch)-1;
            inserer_SMS(l,sms,1);
        
            //elementAfficher_SMS(sms);
            //listeAfficher_SMS(l);
        }
        else
        { 
    
        for (i=1;i<=nb_sms_std;i++)
        {   ELEMENT_SMS sms = elementCreer_SMS();
            //printf("\nchaine %s",ch);

            strncpy(sms->texte,ch + c,153);
            c = c + 153;
            //printf("\nchaine jdida %s",sms->texte);
               sms->taille=strlen(sms->texte)-1; 
            
             inserer_SMS(l,sms,i);
            //printf("khedmet l khra %i",k);
          

        }
            //elementAfficher_SMS(sms);
           // listeAfficher_SMS(l);
        }
    }
    else if (x==1)
    {    
        int nb_sms_sp=SMS_special(ch);
       printf("\nnb d'sms %i",nb_sms_sp);
        if (nb_sms_sp==1)
        {     ELEMENT_SMS sms = elementCreer_SMS();
            strcpy(sms->texte,ch);
            sms->taille=strlen(ch)-1;
            inserer_SMS(l,sms,1);

            //elementAfficher_SMS(sms);
            //listeAfficher_SMS(l);

        }
        else 
        {
        for (i=0;i<=nb_sms_sp;i++)
        {

            ELEMENT_SMS sms = elementCreer_SMS();
           strncpy(sms->texte,ch + c,67);
           c = c + 67;
           sms->taille=strlen(sms->texte)-1;
           inserer_SMS(l,sms,i);
        }
       // listeAfficher_SMS(l);

        }

    }

   return x;
}
ELEMENT_MSG elementCreer_MSG (void)
{
    ELEMENT_MSG L;
    L = (ELEMENT_MSG) malloc(sizeof(MESSAGE));
    return L;
}

void elementDetruire_MSG (ELEMENT_MSG L)
{
    free (L);
}


void elementLire_MSG(ELEMENT_MSG *elt)
{
    int i,test=0;
    char chaine[1224];
    do
    {
         printf("\n Saisir le numero du recepteur svp ");
         fflush(stdin);
         fgets((*elt)->recepteur,9,stdin);

         if ((*elt)->recepteur[0] == '2' || (*elt)->recepteur[0] =='9' || (*elt)->recepteur[0] =='5')
         {
             test=1;
         }

    } while ( strlen((*elt)->recepteur)!=8 || test==0);

    LISTE_SMS L = listeCreer_SMS();
    (*elt)->msg = L;
     //(*elt)->msg=listeCreer_SMS();
     //elementLire_SMS(&sms);
     type_sms((*elt)->msg);
     listeAfficher_SMS((*elt)->msg);
     
     elementLire_DATE(&(*elt)->date_envoi);
     elementLire_HEURE(&(*elt)->heure_envoi);




     for(i=1; i<=(*elt)->msg->lg ;i++ )
      {
        // printf("\nnbr d sms %i",i);
        if (existe(*chaine)==1)
        {
         (*elt)->prix= 0.050 * i;   
        }
        else 
        {
         (*elt)->prix= 0.050 * i;
        }
      }
     
}



void elementAfficher_MSG(ELEMENT_MSG elt)
{   
   printf("\n---------------------------------------------------------------------"); 
   printf("\n---------------------------------MSG---------------------------------");
   printf ("\n     Recepteur : %s",elt->recepteur);
   listeAfficher_SMS (elt->msg);
   elementAfficher_DATE(elt->date_envoi);
   elementAfficher_HEURE(elt->heure_envoi);
   printf("\n     Prix : %.3f",elt->prix);
   printf("\n---------------------------------------------------------------------");
}


void elementAffecter_MSG(ELEMENT_MSG* e1, ELEMENT_MSG e2)
{
   *e1 = e2 ;
}


void elementCopier_MSG(ELEMENT_MSG *e1, ELEMENT_MSG e2)
{ 
  
  strcpy((*e1)->recepteur,e2->recepteur);
  listeCopier_SMS(e2->msg);
  (*e1)->prix=e2->prix;
  (*e1)->date_envoi=e2->date_envoi;
  (*e1)->heure_envoi=e2->heure_envoi;
}


int elementComparer_MSG(ELEMENT_MSG e1, ELEMENT_MSG e2)
{
    return ((e1->prix)-(e2->prix)) ;
}
