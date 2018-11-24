#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Mot.h"
#include"MotPrive.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_mot(void){
  MOT_Mot newMot=MOT_mot("essay�");
  CU_ASSERT_TRUE(strcmp(newMot,MOT_motEnChaine("essay�"))==0);
}

void test_est_un_mot(void){
  int booleen=MOT_estUnMot("�S��b���n");
  CU_ASSERT_TRUE(booleen);
}

void test_est_un_mot2(void){
  int booleen=MOT_estUnMot("essay&");
  CU_ASSERT_TRUE(booleen == FALSE);
}

void test_longueur_mot(void){
  MOT_Mot mot=MOT_mot("essay�");
  int longueur=MOT_longueurMot(mot);
  CU_ASSERT_TRUE(longueur==6);
}

void test_ieme_caractere(void){
  char c=MOT_iemeCaractere("essay�",6);
  CU_ASSERT_TRUE(c=='�');
}

void test_supprimer_1_lettre(void){
  MOT_Mot motSuppr=supprimerUneLettre("essay�",6);
  CU_ASSERT_TRUE(strcmp(motSuppr,MOT_motEnChaine("essay"))==0);
}

void test_inverser_2_lettres(void){
  MOT_Mot motInv=inverserDeuxLettres("essay�",1);
  CU_ASSERT_TRUE(strcmp(motInv,MOT_motEnChaine("sesay�"))==0);
}

void test_mot_en_chaine(void){
  MOT_Mot mot=MOT_mot("essay�");
  CU_ASSERT_TRUE(strcmp(MOT_motEnChaine(mot),"essay�")==0);
}

void test_supprimer_lettre(void){
  MOT_Mot mot=MOT_mot("essay�");
  MOT_Mot* tableauSuppressions=MOT_supprimerLettre(mot);
  CU_ASSERT_TRUE(strcmp(tableauSuppressions[0],"ssay�")==0);
  CU_ASSERT_TRUE(strcmp(tableauSuppressions[1],"esay�")==0);
  CU_ASSERT_TRUE(strcmp(tableauSuppressions[2],"esay�")==0);
  CU_ASSERT_TRUE(strcmp(tableauSuppressions[3],"essy�")==0);
  CU_ASSERT_TRUE(strcmp(tableauSuppressions[4],"essa�")==0);
  CU_ASSERT_TRUE(strcmp(tableauSuppressions[5],"essay")==0);
}

void test_inverser_lettre(void){
  MOT_Mot mot=MOT_mot("essay�");
  MOT_Mot* tableauInversions=MOT_inverserLettre(mot);
  CU_ASSERT_TRUE(strcmp(tableauInversions[0],"sesay�")==0);
  CU_ASSERT_TRUE(strcmp(tableauInversions[1],"essay�")==0);
  CU_ASSERT_TRUE(strcmp(tableauInversions[2],"esasy�")==0);
  CU_ASSERT_TRUE(strcmp(tableauInversions[3],"essya�")==0);
  CU_ASSERT_TRUE(strcmp(tableauInversions[4],"essa�y")==0);
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
  if ((NULL == CU_add_test(pSuite, "mot", test_mot))
      || (NULL == CU_add_test(pSuite, "est un mot", test_est_un_mot))
      || (NULL == CU_add_test(pSuite, "est un mot2", test_est_un_mot2))
      || (NULL == CU_add_test(pSuite, "longueur", test_longueur_mot))
      || (NULL == CU_add_test(pSuite, "ieme caractere", test_ieme_caractere))
      || (NULL == CU_add_test(pSuite, "supprimer 1 lettre", test_supprimer_1_lettre))
      || (NULL == CU_add_test(pSuite, "inverser 2 lettres", test_inverser_2_lettres))
      || (NULL == CU_add_test(pSuite, "mot en chaine", test_mot_en_chaine))
      || (NULL == CU_add_test(pSuite, "tableau supprimer lettre", test_supprimer_lettre))
      || (NULL == CU_add_test(pSuite, "tableau inverser lettre", test_inverser_lettre))
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
