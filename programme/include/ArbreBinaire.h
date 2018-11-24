/**
* \file ArbreBinaire.h
* \brief Implemantation du SDD Dictionnaire et des fonctions associees
* \author ABOUZAID Mehdi, ANGELOVA Tanya, BELLAMLIH Ali, BERNARD Pierre
**/

#ifndef __ARBREBINAIRE__
#define __ARBREBINAIRE__
typedef struct AB_Arbre{
    char element;
    struct AB_Arbre *filsGauche;
    struct AB_Arbre *filsDroit;
    int estMot;
} AB_Arbre;


/**
* \fn AB_ajouterArbreGauche(AB_Arbre **arbre, char element);
* \brief Fonction permettant d'ajouter un ArbreGauche à un autre arbre (le place à la racine si arbre vide)
*
* \param Arbre, element(char)
* \return Arbre
**/
    void AB_ajouterArbreGauche(AB_Arbre **arbre, char element);

/**
* \fn AB_ajouterArbreDroit(AB_Arbre **arbre, char element);
* \brief Fonction permettant d'ajouter un ArbreGDroit à un autre arbre (le place à la racine si arbre vide)
*
* \param Arbre, element(char)
* \return Arbre
**/
    void AB_ajouterArbreDroit(AB_Arbre **arbre, char element);

    /**
    * \fn AB_supprimerArbre(AB_Arbre **arbre);
    * \brief Fonction permettant de detruire un arbre en liberant la mémoire
    *
    * \param Arbre
    * \return Arbre
    **/
    void AB_supprimerArbre(AB_Arbre **arbre);

    /**
    * \fn AB_motEstPresent(AB_Arbre *arbre, char mot[]);
    * \brief Fonction permettant de savoir si une chaine de caractère est presente dans notre arbre
    *
    * \param Arbre, chaine de caracteres
    * \return booleen(int)
    **/
    int AB_motEstPresent(AB_Arbre *arbre, char mot[]);

    void AB_insererMot(AB_Arbre **arbre, char mot[]);

#endif
