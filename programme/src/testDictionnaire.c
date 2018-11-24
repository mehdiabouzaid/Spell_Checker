#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
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

void test_completer_dico(void){
  Dictionnaire dico;
  MOT_Mot mot=MOT_mot("blabla");
  DICTIONNAIRE_completerDico(&dico,"test.txt");
  int booleen=DICTIONNAIRE_motDansDico(dico,mot);
  CU_ASSERT_TRUE(booleen)
}



void test_mot_dans_dico(void){
  Dictionnaire dico;
  MOT_Mot mot=MOT_mot("bonjour");
  DICTIONNAIRE_ajouterDico(&dico,mot);
  int booleen=DICTIONNAIRE_motDansDico(dico,mot);
  CU_ASSERT_TRUE(booleen)
}


void test_ajouter_dico(void){
  Dictionnaire dico; 
  MOT_Mot mot=MOT_mot("bonjour");
  DICTIONNAIRE_ajouterDico(&dico,mot);
  int booleen=DICTIONNAIRE_motDansDico(dico,mot);
  CU_ASSERT_TRUE(booleen)
}

void test_detruire_dico(void){
  Dictionnaire dico;
  MOT_Mot mot=MOT_mot("bonjour");
  DICTIONNAIRE_detruireDico(&dico);
  int booleen=DICTIONNAIRE_motDansDico(dico,mot);
  CU_ASSERT_TRUE(booleen==FALSE)
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
  if ((NULL == CU_add_test(pSuite, "completer dico", test_completer_dico))
     || (NULL == CU_add_test(pSuite, "ajouter dico", test_ajouter_dico))
     || (NULL == CU_add_test(pSuite, "mot dans dico", test_mot_dans_dico))
     || (NULL == CU_add_test(pSuite, "detruire dico", test_detruire_dico))
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
