#include "Mot.h"
#include "dictionnaire.h"
#include "ArbreBinaire.h"
#include <stdio.h>
#ifndef __CORRECTEURORTHOGRAPHE__

/**
 * \file TADCorr.h
 * \brief SDD correcteur orthographique
 * \author ABOUZAID Mehdi, ANGELOVA Tanya, BELLAMLIH Ali et BERNARD Pierre
 *
 * Implémentation des fonctions et procédures du TAD Correcteur orthographique
 *
 **/

typedef struct Correction
{
	MOT_Mot mot;
	int siMotBienEcrit;
	int nbCorrections;
	MOT_Mot tabCorrections[20];
}Correction;
/**
\fn int estSeparateur(char c);
* \brief Fonction permettant de savoir si un caractère est un séparateur de type espace, tiret ou apostrophe
* \param ChaineDeCaractere,tableau de ChaineDeCaractere,Entier,tableau d'entiers
* \return tableau de ChaineDeCaractere,Entier,tableau d'entiers
**/
int estSeparateur(char c);
/**
\fn void decomposerLaChaine (const char* chaine,char*** adrPtrMots , int** adrPosDansChaines)
* \brief Fonction permettant de morceler la chaine de caractère en entrée pour former les mots sur lesquels on va travailler
*
* \param ChaineDeCaractere,tableau de ChaineDeCaractere,Entier,tableau d'entiers
* \return tableau de ChaineDeCaractere,Entier,tableau d'entiers
**/
void decomposerLaChaine (const char* chaine,char*** adrPtrMots , int** adrPosDansChaines);
/**
\fn int compteurDeMots (const char* chaine)
* \brief Fonction permettant de compter le nombre de mots contenu dans une chaine
*
* \param char* chaine
* \return integer
**/
int compteurDeMots (const char* chaine);
/**
\fn void char *sous_string (const char *s, unsigned int start, unsigned int end)
* \brief Fonction permettant de découper une chaine de caractère en sous chaine de caractère
*
* \param const char *s, unsigned int start, unsigned int end
* \return chaine de caractère
**/
char *sous_string (const char *s, unsigned int start, unsigned int end);

/**
\fn void CORR_corriger(*Dictionnaire, MOT_mot LeMot)
* \brief Fonction permettant de corriger le mot en entrée
*
* \param MOT_Mot,Dictionnaire
* \return Tableau de Mots
**/
void CORR_corriger (Dictionnaire dico, MOT_Mot LeMot, MOT_Mot *tableauDeMots, int* compteurDesCorrections);

/**
\fn void CORR_decomposer(*ChaineDeCaractere,*tableau de ChaineDeCaractere, Entier, tableau d'entiers)
* \brief Fonction permettant de morceler la chaine de caractère en entrée pour former les mots sur lesquels on va travailler
*
* \param ChaineDeCaractere,tableau de ChaineDeCaractere,Entier,tableau d'entiers
* \return tableau de ChaineDeCaractere,Entier,tableau d'entiers
**/

int CORR_nbMots(char* str, Dictionnaire dico);
/**
\fn int CORR_estCorrigeable(char str, *Dictionnaire);
* \brief Fonction permettant de verifier si une chaine est bien ecrite ou pas.
*
* \param Chaine de Caractere, Dictionnaire
* \return Boolean
**/
int CORR_estCorrigeable(MOT_Mot mot, Dictionnaire dico);
/**
\fn Correction* correcteur(Dictionnaire *dico, MOT_Mot** tableauDesMots, int nbMots);
* \brief Fonction permettant de regrouper tout l'information necessaire sur chaque mot.
*
* \param tableau, compose de tous les mots en entree, Dictionnaire, Entier - nombre de mot a corriger
* \return un tableau de tous les mots avec tableau des ses corrections, nb de corrections,booleen si le mot est bien ecrit
**/

Correction* correcteur(Dictionnaire dico, MOT_Mot* tableauDesMots, int *nbMots);

#endif
