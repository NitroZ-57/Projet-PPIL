#pragma once
#include "SauvegardeTxtCOR.h"

/*
* Cette classe hérite de SauvegardeTxtCOR, elle correspond au maillon de la chaine de responsabilité pouvant lire un polygone
*/
class SauvegardeTxtCORPolygone : public SauvegardeTxtCOR {


public:
	/*
	* @brief Créer un maillon de la chaine de responsabilité et ajoute le maillon donné en paramètre en queue
	* @param le prochain maillon de la chaine de responsabilité
	*/
	SauvegardeTxtCORPolygone(SauvegardeTxtCOR* suivant);

	/*
	* @brief Cette méthode tente de lire un Polygone dans la chaine de caractère
	* @param msg : la chaine de caractère sur laquelle lire la forme
	* @return Fome : un pointeur sur la forme lue, nullptr si la forme n'a pas été reconnue
	*/
	virtual Forme* sousLire(const char* msg) const;


};