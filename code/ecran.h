/*
* ecran.h
* Contient toutes les fonctions pour interagir avec l'ecran modele
* NHD-0420D3Z-FL-GBW
*
* Auteur : Philippe Lefebvre
*/

#ifndef ECRAN_H
#define ECRAN_H

/***********Includes************/


/************Defines************/


/*********Declarations**********/

/*
* Fonction : ecranAllume
* Description : Envoie la commande pour allumer l'ecran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void ecranAllume(void);

/*
* Fonction : ecranEteint
* Description : Envoie la commande pour eteindre l'ecran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void ecranEteint(void);

/*
* Fonction : ecranEteint
* Description : Envoie la commande pour placer le courseur dans l'ecran
*
* Params : Position
* 
* Retour : Aucun
*/
void cursorPosition(int position);

/*
* Fonction : videEcran
* Description : Envoie la commande pour vider l'ecran
*
* Params : position
* 
* Retour : Aucun
*/
void videEcran(void);

/*
* Fonction : ecranEteint
* Description : Envoie la commande pour montrer un caracter sur l'ecran
*
* Params : character
* 
* Retour : Aucun
*/
void ecrireCaracter(char caracter);


#endif