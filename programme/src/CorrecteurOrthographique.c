 #include "TADCorr.h"
 #include "Mot.h"
 #include <string.h>
 #include "dictionnaire.h"
 #define TRUE 1
 #define FALSE 0
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>

 int estSeparateur(char c){
   int a = isspace(c); // détecte les espaces
   //int b = ispunct(c); // détecte la ponctuation
   return ((a!=0) || (c=='-') || (c=='\'')); //(b!=0));
    }

    int compteurDeMots (const char* chaine){ //rien de spécial à expliquer le code est assez explicite : dès qu'on trouve un mot on continue de le lire jusqu'a trouver un espace. Cet algorithme détecte aussi la suite d'espace et les ignore.
      int compteur=0;
      int i=0;
        while (i<strlen(chaine)){
          int mot_lu=0;
          while(!(estSeparateur(chaine[i]))){
            i+=1;
            mot_lu=1;
          }
          if(mot_lu) {
            compteur+=1;
          }
          while(estSeparateur(chaine[i])){
            i+=1;
          }
           //printf("%d\n",compteur);

         }
         return compteur;
      }


 char *sous_string (const char *s, unsigned int start, unsigned int end){
   char *nouveau_s = NULL;

   if (s != NULL && start <= end)
   {
 /* Calcul la taille de la sous chaine qui nous intéresse*/
      nouveau_s = malloc (sizeof (*nouveau_s) * (end - start + 2));
      /*end-start +2 correspond à la longueur du string + 1 du '\0'*/
      if (nouveau_s != NULL)
      {
         int i;

 /* On commence à parcourir s dans l'intervalle rentré en paramètre*/
         for (i = start; i <= end; i++)
         {
 /* On copie dans une nouvelle chaine ce qui nous intéresse */
            nouveau_s[i-start] = s[i];
         }
         nouveau_s[i-start] = '\0';
      }
    //}
      //else
      //{

      //   fprintf (stderr, "Problème dans la définition\n");
        // exit (EXIT_FAILURE);
    //  }
   }
   return nouveau_s;
 }

 void decomposerLaChaine (const char* chaine,char*** adrPtrMots , int** adrPosDansChaines){
 //  char ** tabDeMots;
   int nbreDeMots= compteurDeMots(chaine);
   *adrPtrMots = malloc( sizeof(char**) * nbreDeMots ); // allouer 'compteur' * pointeurs
   *adrPosDansChaines= malloc( sizeof(int*) * nbreDeMots);
   char** ptrMots = *adrPtrMots;// utiliser un nom avec un niveau de pointeur de moins
   int* PosDansChaines= *adrPosDansChaines;
   char* string_A_Afficher;
   int j=0;
   int i=0;
   int compteur=0;
   PosDansChaines[compteur]=0;
   while (i<strlen(chaine)){
     int mot_lu=0;
     while(!(estSeparateur(chaine[i]))){
       i+=1;
       mot_lu=1;
     }
       if(mot_lu) {
         char* string_A_Afficher=sous_string(chaine,j,i-1);
         ptrMots[compteur]=string_A_Afficher;
         PosDansChaines[compteur+1]=i+1;
         compteur+=1;
         //printf("%s \n",string_A_Afficher);
         j=i+1;
       }
       while(estSeparateur(chaine[i])){
         i+=1;
       }
     }
 }


void CORR_corriger (Dictionnaire dico, MOT_Mot LeMot, MOT_Mot *tableauDeMots, int* compteurDesCorrections){
//En entree, la procedure a besoin du dictionnaire et du mot a corriger. En sortie, la procedure retourne un tableau de tout les corrections possibles (qui sont deja dans le dictionnaire) et le nombre de ces corrections.
	MOT_Mot *t1,*t2,*t;
	t1=(MOT_Mot*)malloc(sizeof(MOT_Mot)*MOT_longueurMot(LeMot));
	t2=(MOT_Mot*)malloc(sizeof(MOT_Mot)*(MOT_longueurMot(LeMot)-1));
	t=(MOT_Mot*)malloc(sizeof(MOT_Mot)*2*MOT_longueurMot(LeMot));
	tableauDeMots=(MOT_Mot*)malloc(sizeof(MOT_Mot)*(2*MOT_longueurMot(LeMot)-1));
	int i,j;
	int l;
	l=MOT_longueurMot(LeMot);
	t1=MOT_supprimerLettre(LeMot);// nbMot=longeurDeMot
	t2=MOT_inverserLettre(LeMot);// nbMot=longueurDeMot-1
	//Concatener les deux tableaux
	*compteurDesCorrections = 0;
	for (i=0; i<=l-1; i++){
		t[i]=t1[i];
	}
	for (i=0; i<=(l-1); i++){
		t[i+l]=t2[i];
	}
	j=1;
	for (i=1; i<=((2*l)-1); i++){
		if (DICTIONNAIRE_motDansDico(dico, MOT_motEnChaine(t[i]))){
			tableauDeMots[j]=t[i];
			j++;

		}
	}
	*compteurDesCorrections = j;
}

int CORR_estCorrigeable(MOT_Mot mot, Dictionnaire dico){

	if (DICTIONNAIRE_motDansDico(dico, MOT_motEnChaine(mot))){
		return FALSE;
	}
	else{
		return TRUE;
	}
}
int CORR_nbMots(char* str, Dictionnaire dico){
	MOT_Mot mot;
	MOT_Mot *tableauDeMots;
	int res;
	mot = MOT_mot(str);
	CORR_corriger(dico, mot, tableauDeMots, &res );
	return res;
}

Correction* correcteur(Dictionnaire dico, MOT_Mot* tableauDesMots, int *nbMots){
	int i;
	Correction *tableauCorrections;
	tableauCorrections=(Correction*)malloc(sizeof(Correction)*(*nbMots));
	for (i=0; i<=*nbMots; i++){
		if (MOT_estUnMot(MOT_motEnChaine(tableauDesMots[i]))){
			tableauCorrections[i].mot=tableauDesMots[i];
			if (CORR_estCorrigeable(tableauDesMots[i], dico)){
				tableauCorrections[i].siMotBienEcrit=FALSE;
				CORR_corriger (dico, tableauDesMots[i], tableauCorrections[i].tabCorrections, &tableauCorrections[i].nbCorrections);
			}
			else {
				tableauCorrections[i].siMotBienEcrit=TRUE;
				tableauCorrections[i].nbCorrections=0;
				tableauCorrections[i].tabCorrections[1]=NULL;
			}
		}
	}
	return tableauCorrections;
}
