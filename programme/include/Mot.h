/**
 * \file mot.h
 * \brief SDD mot
 * \author ABOUZAID Mehdi, ANGELOVA Tanya, BELLAMLIH Ali et BERNARD Pierre
 *
 * Implémentation des fonctions et procédures du TAD mot
 *
 */

#ifndef __MOT__
#define __MOT__


typedef char* MOT_Mot;

/**
 * \fn MOT_Mot MOT_mot(char* chaine)
 * \brief Fonction permettant de transformer une chaine en un mot de type MOT_Mot
 *
 * \param char* chaine
 * \return MOT_Mot
 */
MOT_Mot MOT_mot(char* chaine);


/**
 * \fn int MOT_estUnMot(char* chaine)
 * \brief Fonction permettant de savoir si la chaine est un mot valide ou pas
 *
 * \param char* chaine à tester
 * \return le booléen 0 pour VRAI et 1 pour FAUX
 */
int MOT_estUnMot(char* chaine);

/**
 * \fn int MOT_longueurMot(MOT_Mot leMot)
 * \brief Fonction permettant de connaître la longueur d'un mot
 *
 * \param MOT_Mot
 * \return int la longueur du mot
 */
int MOT_longueurMot(MOT_Mot leMot);

/**
 * \fn char MOT_iemeCaractere(MOT_Mot leMot, int position)
 * \brief Fonction permettant de connaître le ième caractère d'un mot
 *
 * \param MOT_Mot leMot, int position
 * \return char le ième caractère
 */
char MOT_iemeCaractere(MOT_Mot leMot, int position);


/**
 * \fn MOT_Mot* MOT_supprimerLettre(MOT_Mot leMot)
 * \brief Fonction permettant de supprimer chaque lettre d'un mot une à une
 *
 * \param MOT_Mot leMot
 * \return MOT_Mot* le tableau de mots avec chacune des lettres supprimées par mot
 */
MOT_Mot* MOT_supprimerLettre(MOT_Mot leMot);

/**
 * \fn MOT_Mot* MOT_inverserLettre(MOT_Mot leMot)
 * \brief Fonction permettant d'inverser toutes les combinaisons de lettres à la suite d'un mot
 *
 * \param MOT_Mot leMot
 * \return MOT_Mot* le tableau de mots avec les combinaisons de lettres inversées
 */
MOT_Mot* MOT_inverserLettre(MOT_Mot leMot);

/**
 * \fn char* MOT_motEnChaine(MOT_Mot leMot)
 * \brief Fonction pour transformer un mot en chaine
 *
 * \param MOT_Mot leMot
 * \return char*
 */
char* MOT_motEnChaine(MOT_Mot leMot);

#endif
