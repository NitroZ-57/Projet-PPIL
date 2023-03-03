#pragma once
#include "SauvegardeTxtCOR.h"

/*
* @brief Cette classe hérite de SauvegardeTxtCOR, elle correspond au maillon de la chaine de responsabilité pouvant lire un cercle
*/
class SauvegardeTxtCORCercle : public SauvegardeTxtCOR {


public:
	/*
	* @brief Créer un maillon de la chaine de responsabilité et ajoute le maillon donné en paramètre en queue
	* @param le prochain maillon de la chaine de responsabilité
	*/
	SauvegardeTxtCORCercle(SauvegardeTxtCOR * suivant);

	/*
	* @brief Cette méthode tente de lire un Cercle dans la chaine de caractère
	* @param msg : la chaine de caractère sur laquelle lire la forme
	* @return Fome : un pointeur sur la forme lue, nullptr si la forme n'a pas été reconnue
	*/
	virtual Forme* sousLire(const char* msg) const;

};