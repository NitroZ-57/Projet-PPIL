#pragma once
#include "SauvegardeTxtCOR.h"

/*
* Cette classe h�rite de SauvegardeTxtCOR, elle correspond au maillon de la chaine de responsabilit� pouvant lire un polygone
*/
class SauvegardeTxtCORPolygone : public SauvegardeTxtCOR {


public:
	/*
	* @brief Cr�er un maillon de la chaine de responsabilit� et ajoute le maillon donn� en param�tre en queue
	* @param le prochain maillon de la chaine de responsabilit�
	*/
	SauvegardeTxtCORPolygone(SauvegardeTxtCOR* suivant);

	/*
	* @brief Cette m�thode tente de lire un Polygone dans la chaine de caract�re
	* @param msg : la chaine de caract�re sur laquelle lire la forme
	* @return Fome : un pointeur sur la forme lue, nullptr si la forme n'a pas �t� reconnue
	*/
	virtual Forme* sousLire(const char* msg) const;


};