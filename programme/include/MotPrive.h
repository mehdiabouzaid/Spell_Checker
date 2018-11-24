#ifndef __MOT_PRIVE__
#define __MOT_PRIVE__
#include "Mot.h"

/**
 * \fn void supprimerUneLettre(MOT_Mot *leMot, int position)
 * \brief Fonction permettant de supprimer la ième lettre d'un mot
 *
 * \param MOT_Mot le  MOT_Mot* blabla;
  return blabla;Mot, int position
 * \return MOT_Mot le mot avec la lettre supprimée
 */
MOT_Mot supprimerUneLettre(MOT_Mot leMot, int position);

/**
 * \fn void inverserDeuxLettres(MOT_Mot leMot, int position1)
 * \brief Fonction permettant d'inverser les ieme et i+1eme caracteres d'un mot
 *
 * \param MOT_Mot leMot, int position1
 * \return MOT_Mot le mot avec le mot avec les lettres inversees (position1 et position1+1)
 */
MOT_Mot inverserDeuxLettres(MOT_Mot leMot, int position1);

#endif
