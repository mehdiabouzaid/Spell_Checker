#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include"Mot.h"
#include"MotPrive.h"
#define TRUE 1
#define FALSE 0

/* Partie privée */

MOT_Mot inverserDeuxLettres(MOT_Mot leMot, int position1){
  MOT_Mot motAvecInversion=MOT_mot(leMot);
  if (position1<MOT_longueurMot(leMot)){
    motAvecInversion[position1]=leMot[position1-1];
    motAvecInversion[position1-1]=leMot[position1];
    return  motAvecInversion;
  }
  else{
    return NULL;
  }
}

MOT_Mot supprimerUneLettre(MOT_Mot leMot, int position){
  int i;
  MOT_Mot motAvecSuppression=MOT_mot(leMot);
  for (i=position-1; i < MOT_longueurMot(leMot) ; i++){
      motAvecSuppression[i] =  motAvecSuppression[i+1];
  }
   motAvecSuppression[i] = '\0';
  return  motAvecSuppression;
}

/* Partie publique */

int MOT_estUnMot(char* chaine){
  int i=0, estMot=TRUE;
  char c=chaine[i];

  while(estMot && c!='\0' && i<strlen(chaine)){
    c=chaine[i];
    if ((c>='a' && c<='z') || (c>='A' && c<='Z') || c=='¦' || c=='¨'|| c=='´' || c=='¸' || (c>='¼' && c<='¾') || (c>='À' && c<='Ö') || (c>='Ø' && c<='ö') || (c>='ø' && c<='ÿ')){
      i++;
    }
    else{
      estMot=FALSE;
    }
  }
  return estMot;
}

MOT_Mot MOT_mot(char* chaine){
  if (MOT_estUnMot(chaine)){
    MOT_Mot newMot=(char*)malloc(sizeof(char)*strlen(chaine));
    strcpy(newMot,chaine);
    return newMot;
  }
  else{
    return NULL;
  }
}

int MOT_longueurMot(MOT_Mot leMot){
  int i=0;
  while(leMot[i]!='\0'){
    i++;
  }
  return i;
}

char MOT_iemeCaractere(MOT_Mot leMot, int position){
  if(position<=MOT_longueurMot(leMot)){
      return leMot[position-1];
  }
  else{
    return 0;
  }
}

MOT_Mot* MOT_supprimerLettre(MOT_Mot leMot){
  int i;
  MOT_Mot* tableauSuppressions=(char**)malloc(sizeof(char)*MOT_longueurMot(leMot)*MOT_longueurMot(leMot));
  for (i=0; i<MOT_longueurMot(leMot); i++){
    tableauSuppressions[i]=supprimerUneLettre(leMot,i+1);
  }
  return tableauSuppressions;
}

MOT_Mot* MOT_inverserLettre(MOT_Mot leMot){
  int i;
  MOT_Mot* tableauInversions=(char**)malloc(sizeof(char)*MOT_longueurMot(leMot)*MOT_longueurMot(leMot));
  for (i=0; i<MOT_longueurMot(leMot)-1; i++){
    tableauInversions[i]=inverserDeuxLettres(leMot,i+1);
  }
  return tableauInversions;
}

char* MOT_motEnChaine(MOT_Mot leMot){
  return leMot;
}
