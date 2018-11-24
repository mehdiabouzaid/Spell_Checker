/**
* \file dictionnaire.h
* \brief Implemantation du SDD Dictionnaire et des fonctions associees
* \author ABOUZAID Mehdi, ANGELOVA Tanya, BELLAMLIH Ali, BERNARD Pierre
**/

#include <stdio.h>
#include <stdlib.h>
#include "ArbreBinaire.h"

#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

typedef struct Dictionnaire{
  AB_Arbre Dico;
}Dictionnaire;



  /**
  * \fn void DICTIONNAIRE_completerDico(*Dictionnaire, Chaine de caracteres(nom du fichier))
  * \brief Fonction permettant de compléter le dictionnaire
  *
  * \param Dictionnaire, FichierTexte
  * \return Dictionnaire
  **/
  void DICTIONNAIRE_completerDico(Dictionnaire *dico, char FichierTexte[]);

  /**
  * \fn void DICTIONNAIRE_ajouterDico(*Dictionnaire, ChaineDeCaractere)
  * \brief Fonction permettant de compléter le dictionnaire
  *
  * \param Dictionnaire, ChaineDeCaractere
  * \return Dictionnaire
  **/
	void DICTIONNAIRE_ajouterDico(Dictionnaire *dico, char mot[]); // a éditer selon notre tad mot

  /**
  * \fn int DICTIONNAIRE_motDansDico (*Dictionnaire, ChaineDeCaractere)
  * \brief Fonction permettant de compléter le dictionnaire
  *
  * \param Dictionnaire, ChaineDeCaractere
  * \return Booleen
  **/
	int DICTIONNAIRE_motDansDico(Dictionnaire dico, char mot[]);

  /**
  * \fn int DICTIONNAIRE_detruireDico (*Dictionnaire)
  * \brief Fonction permettant de cetruire le dictionnaire
  *
  * \param Dictionnaire
  * \return Dictionnaire
  **/
  void DICTIONNAIRE_detruireDico(Dictionnaire *dico);




#endif
