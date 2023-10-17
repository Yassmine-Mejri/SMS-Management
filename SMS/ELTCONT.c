#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>


#include"CONTPRIMELT.h"


ELEMENT_CONT elementCreer_CONT (void)
{
    ELEMENT_CONT L;
    L = (ELEMENT_CONT) malloc(sizeof(CONTACT));
    return L;
}

void elementDetruire_CONT (ELEMENT_CONT L)
{
    free (L);
}


void elementLire_CONT(ELEMENT_CONT* elt)
{



    printf("     Saisir votre nom svp: ");
    fflush(stdin);
    fgets((*elt)->nom,50,stdin);
  

 int test=0;
    do
    {
         printf("     Saisir votre numero svp: ");
         fflush(stdin);
         fgets((*elt)->numero,9,stdin);

         if ((*elt)->numero[0] == '2' || (*elt)->numero[0] =='9' || (*elt)->numero[0] =='5') /*&& ((*elt)->numero>=20000000 && (*elt)->numero<=99999999))*/
         {
             test=1;
         }

    } while ( strlen((*elt)->numero)!=8 || test==0);



 int i, test1=0,test2=0,pos1=0,pos2=0;
 do
   {
    printf("     Saisir votre email svp: ");
    fflush(stdin);
    fgets((*elt)->email,30,stdin);

   for(i=0;i<=strlen((*elt)->email);i++)
   {
       if ((*elt)->email[i] == '@')
       {
           test1=1;
           pos1=i;
       }else if ((*elt)->email[i] == '.')
       {
           test2=1;
           pos2=i;
           
       }

   }

  } while((test1 ==0) && (test2==0) || (pos1>pos2));

}



void elementAfficher_CONT(ELEMENT_CONT elt)
{ 
   printf("\n---------------------------------------------------------------------");
   printf("\n-------------------------------CONTACT-------------------------------");
   printf("\n    Nom: %s ",elt->nom );
   printf("      Numero: %s ", elt->numero );
   printf("\n    Email: %s", elt->email);
   printf("\n-------------------------------CONTACT-------------------------------");
   printf("\n---------------------------------------------------------------------");

}


void elementAffecter_CONT(ELEMENT_CONT* e1, ELEMENT_CONT e2)
{
   *e1 = e2 ;
}


void elementCopier_CONT(ELEMENT_CONT *e1, ELEMENT_CONT e2)
{
    strcpy((*e1)->nom, e2->nom);
    strcpy((*e1)->numero, e2->numero);
    strcpy((*e1)->email, e2->email);
}


int elementComparer_CONT(ELEMENT_CONT e1, ELEMENT_CONT e2)
{
    if (strcmp(e1->nom,e2->nom) != 0) 
    {
        return strcmp(e1->nom,e2->nom);
    } 
    else 
    {
        return strcmp(e1->numero,e2->numero);
    }
}
