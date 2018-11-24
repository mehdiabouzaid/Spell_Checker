#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADCorr.h"
#include "Mot.h"
#include "dictionnaire.h"
#include "ArbreBinaire.h"


int main(int argc,char** argv){

int compteur,Corrections,i,nombreArguments=argc-1;
MOT_Mot* tableauDeMots;

  if ((nombreArguments==2) || (nombreArguments==4)) {
    if (strcmp(argv[1], "-h")==0) {
      //printf l'aide
    }
    else if(strcmp(argv[1], "-d")==0){
      //correction entree standard avec dico argv[2]
      char input[500];
      fgets(input,500,stdin);
      Correction *corrections;
      corrections=(Correction*)malloc(sizeof(Correction)*compteur);
      Dictionnaire dico;
      int *PositionDansChaine;
      *PositionDansChaine = malloc( sizeof(char**) * compteur );
      decomposerLaChaine (input,&tableauDeMots,&PositionDansChaine);
      compteur = compteurDeMots(input);
      Corrections=correcteur(dico,tableauDeMots,&compteurDeMots);
      for (i=0 ; i<compteur ; i++){
	       printf("%s/n",corrections[i]);
         if (nombreArguments==4) {
	          if (strcmp(argv[3], "-f")==0){
	             DICTIONNAIRE_completerDico(&argv[2],argv[4]);
	          }
         }
      }
    }
  }
  return 0;
}
