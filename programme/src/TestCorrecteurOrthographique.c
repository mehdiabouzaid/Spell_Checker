#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADCorr.h"
#include "Mot.h"
#include "dictionnaire.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_sous_string1(void) {
  char* testString = "TestMot";
  char* test = "Test";
  //int booleen = strcmp(sous_string(testString,0,3),test);
  CU_ASSERT_TRUE(test==sous_string(testString,0,3));
}
void test_sous_string2(void) { // a voir comment ca fonctionne
  char* String = "azedsq";
  char* String_faux = sous_string(String,3,0);

  CU_ASSERT_TRUE(String_faux=NULL);
//  int booleen = strcmp(String_faux,""); je resous un conflit, je ne suis pas sure lequel des deux laisser, alors je laisse un des deux en commentaire.
//  CU_ASSERT_TRUE(booleen=TRUE)
}
void test_estSeparateur1(void){
  char* String ="j'aime les choux-fleurs";
  int booleen=estSeparateur(String[1]);
  CU_ASSERT_TRUE(booleen=TRUE);
}

void test_estSeparateur2(void){
  char* String ="j'aime les choux-fleurs";
  int booleen=estSeparateur(String[6]);
  CU_ASSERT_TRUE(booleen=TRUE);
}
void test_estSeparateur3(void){
  char* String ="j'aime les choux-fleurs";
  int booleen=estSeparateur(String[16]);
  CU_ASSERT_TRUE(booleen=TRUE);
}
void test_decomposer_compteurDeMots(void){
  char* String_a_decomposer = "String a decomposer";
  char ** tabMots;
  int * pos;
  int compteur=compteurDeMots(String_a_decomposer);
  decomposerLaChaine(String_a_decomposer,&tabMots,&pos);
  char* charTest=tabMots[0];
  int position_a=pos[1];
  CU_ASSERT_TRUE((strcmp(charTest,"String")==0) && (compteur==3) && (position_a==7));
}

void test_estCorrigeable1(void){
	MOT_Mot mot = MOT_mot("vrai");
	Dictionnaire dico;
	DICTIONNAIRE_ajouterDico(&dico, "vrai");
//	FILE* fichier=NULL;
 //   fichier=fopen("test.txt","w");
 //   fwrite(mot, MOT_longueurMot(mot)+1, 1, fichier);
 //   Dictionnaire dico=DICTIONNAIRE_creationDictionnaire(fichier);
	CU_ASSERT_TRUE(CORR_estCorrigeable(mot, dico)==0);
}

void test_estCorrigeable2(void){
	MOT_Mot mot = MOT_mot("vrei");
//	MOT_Mot motVr = MOT_mot("vrai");
	Dictionnaire dico;
	DICTIONNAIRE_ajouterDico(&dico, "vrai");
	CU_ASSERT_TRUE(CORR_estCorrigeable(mot, dico)==1);
}

void test_corriger(void){
	MOT_Mot mot = MOT_mot("vraei");
//	MOT_Mot motVr = MOT_mot("vrai");
	MOT_Mot *tableauDesMots;
	Dictionnaire dico;
	DICTIONNAIRE_ajouterDico(&dico, "vrai");
	tableauDesMots=(MOT_Mot*)malloc(sizeof(MOT_Mot)*(2*MOT_longueurMot(mot)-1));
	int compteurDesCorrections=0;
//	FILE* fichier=NULL;
//	fichier=fopen("test.txt","w");
//	fwrite(motVr, MOT_longueurMot(motVr)+1, 1, fichier);
//	Dictionnaire dico=DICTIONNAIRE_creationDictionnaire(fichier);
	CORR_corriger (dico, mot, tableauDesMots, &compteurDesCorrections);
	CU_ASSERT_TRUE((tableauDesMots[1]==MOT_mot("vrai"))&&(compteurDesCorrections==1));
}

void test_correcteur(void){
	int nbMots=2;
	MOT_Mot *tableauDesMots;
	tableauDesMots=(MOT_Mot*)malloc(sizeof(MOT_Mot)*nbMots);
	Correction *tableauDesCorrections;
	tableauDesCorrections=(Correction*)malloc(sizeof(Correction)*nbMots);
	Dictionnaire dico;
	DICTIONNAIRE_ajouterDico(&dico, "vrai");
//	FILE* fichier=NULL;
//	fichier=fopen("test.txt","w");
//	fwrite(MOT_mot("vrai"), MOT_longueurMot(MOT_mot("vrai"))+1, 1, fichier);
//	Dictionnaire dico=DICTIONNAIRE_creationDictionnaire(fichier);
	tableauDesMots[1]=MOT_mot("vrai");
	tableauDesMots[2]=MOT_mot("vraei");
	tableauDesCorrections = correcteur(dico, tableauDesMots,&nbMots);
	CU_ASSERT_TRUE((tableauDesCorrections[1].mot==tableauDesMots[1])&&(tableauDesCorrections[1].siMotBienEcrit==1));
	CU_ASSERT_TRUE((tableauDesCorrections[1].nbCorrections==0)&&(tableauDesCorrections[1].tabCorrections[1]==NULL));
	CU_ASSERT_TRUE((tableauDesCorrections[2].mot==tableauDesMots[2])&&(tableauDesCorrections[1].siMotBienEcrit==0));
	CU_ASSERT_TRUE((tableauDesCorrections[1].nbCorrections==1)&&(tableauDesCorrections[1].tabCorrections[1]==MOT_mot("vrai")));
}
int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests ? la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "partie d'une chaine1", test_sous_string1))
      || (NULL == CU_add_test(pSuite, "partie d'une chaine2", test_sous_string2))
      || (NULL == CU_add_test(pSuite, "caractere est separateur1", test_estSeparateur1))
      || (NULL == CU_add_test(pSuite, "caractere est separateur2", test_estSeparateur2))
      || (NULL == CU_add_test(pSuite, "caractere est separateur3", test_estSeparateur3))
      || (NULL == CU_add_test(pSuite, "Decomposer une phrase", test_decomposer_compteurDeMots))
      || (NULL == CU_add_test(pSuite, "mot est corrigeable1", test_estCorrigeable1))
      || (NULL == CU_add_test(pSuite, "mot est corrigeable2", test_estCorrigeable2))
      || (NULL == CU_add_test(pSuite, "corriger un mot", test_corriger))
      || (NULL == CU_add_test(pSuite, "corriger suite des mots", test_correcteur))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}
