#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArbreBinaire.h"

void AB_ajouterArbreDroit(AB_Arbre **arbre, char element){
    AB_Arbre *tempNoeud;
    AB_Arbre *tempArbre = *arbre;

    AB_Arbre *elem = malloc(sizeof(AB_Arbre));
    elem->element = element;
    elem->filsGauche = NULL;
    elem->filsDroit = NULL;
    elem->estMot = 0;

    if(tempArbre)
    tempNoeud = tempArbre;
    tempArbre = tempArbre->filsGauche;
    if(!tempArbre) tempNoeud->filsGauche = elem;
    if(tempArbre)
    do{
        tempNoeud = tempArbre;
        tempArbre = tempArbre->filsDroit;
        if(!tempArbre) tempNoeud->filsDroit = elem;
    }while(tempArbre);
    else  *arbre = elem;
}

/***************************************************************************/

void AB_ajouterArbreGauche(AB_Arbre **arbre, char element){
    AB_Arbre *tempNoeud;
    AB_Arbre *tempArbre = *arbre;

    AB_Arbre *elem = malloc(sizeof(AB_Arbre));
    elem->element = element;
    elem->filsGauche = NULL;
    elem->filsDroit = NULL;
    elem->estMot = 0;

    if(tempArbre)
    do{
        tempNoeud = tempArbre;
        tempArbre = tempArbre->filsDroit;
        if(!tempArbre) tempNoeud->filsDroit = elem;
    }while(tempArbre);
    else  *arbre = elem;
}

/***************************************************************************/

void AB_supprimerArbre(AB_Arbre **arbre){
    AB_Arbre *tempArbre = *arbre;

    if(!arbre) return;

    if(tempArbre->filsGauche)  AB_supprimerArbre(&tempArbre->filsGauche);

    if(tempArbre->filsDroit) AB_supprimerArbre(&tempArbre->filsDroit);

    free(tempArbre);

    *arbre = NULL;
}

/***************************************************************************/

int AB_motEstPresent(AB_Arbre *arbre, char mot[]){
  int i = 0;
  AB_Arbre *tempArbre = arbre;

    while(i<=strlen(mot)){
    if(tempArbre->element == mot[i]){
      tempArbre = tempArbre->filsGauche;
      i++;
    }
    else
      tempArbre = tempArbre->filsDroit;

  if(tempArbre == NULL)
    return 0;
}
if(i==(strlen(mot)-1) && arbre->estMot == 1)
  return 1;

return 0;

}

void AB_insererMot(AB_Arbre **arbre, char mot[]){
  unsigned int longueurmot = strlen(mot);
  AB_Arbre *tempArbre = *arbre;

  AB_ajouterArbreDroit(&tempArbre,mot[0]);
  for(unsigned int i=1;i<longueurmot;i++){
    if(i==longueurmot-1)
      tempArbre->estMot = 1;
    AB_ajouterArbreGauche(&tempArbre,mot[i-1]);
    tempArbre = tempArbre->filsGauche;
  }
}
