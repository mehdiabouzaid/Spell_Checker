#include "dictionnaire.h"
#include "ArbreBinaire.h"
#include <stdio.h>
#include <stdlib.h>

void DICTIONNAIRE_completerDico(Dictionnaire *dico, char FichierTexte[]){
    FILE *fichier = NULL;
    char chaine[40];

    fichier = fopen(FichierTexte,"r");
    if(fichier==NULL)
        ;// fichier vide(erreur)
    else{
            do{
                fgets(chaine, 40, fichier);
                if(chaine!=NULL)
                    DICTIONNAIRE_ajouterDico(dico,chaine);
            }while(chaine!=NULL);

        }
    fclose(fichier);
}

/***************************************************************************/

void DICTIONNAIRE_ajouterDico(Dictionnaire *dico, char chaine[] ){
  AB_insererMot(&dico->Dico,chaine);

}

/***************************************************************************/

int DICTIONNAIRE_motDansDico(Dictionnaire dico, char chaine[]){
  int val = AB_motEstPresent(&dico.Dico,chaine);
  return val;
}

/***************************************************************************/

void DICTIONNAIRE_detruireDico(Dictionnaire *dico){
  AB_supprimerArbre(&dico->Dico);
}
