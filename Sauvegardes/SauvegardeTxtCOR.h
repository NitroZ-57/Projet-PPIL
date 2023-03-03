#pragma once
#include "SauvegardeTxt.h"


/*
* @brief Cette classe sert de d�but de chaine de responsabilit� pour permettre de lire des formes dans un fichier texte. Cette classe h�rite de la classe SauvegardeTxt
*/
class SauvegardeTxtCOR : public SauvegardeTxt
{
	SauvegardeTxtCOR* suivant;  

public:

	/*
	* @brief Cr�er un maillon de la chaine de responsabilit� et ajoute le maillon donn� en param�tre en queue 
	* @param le prochain maillon de la chaine de responsabilit�
	*/
	SauvegardeTxtCOR(SauvegardeTxtCOR* suivant);

	/*
	* @brief Cette m�thode sert de point de lancement de la chaine de responsabilit�
	* @param msg : la chaine de caract�re sur laquelle lire la forme
	* @return Fome : un pointeur sur la forme lue
	*/
	virtual Forme* lire(const char* msg) const;

protected:

	/*
	* @brief Cette m�thode abstraite est � red�finir pour chaque type de forme qui � pour but d'�tre reconnu dans un fichier texte
	* @param msg : la chaine de caract�re sur laquelle lire la forme
	* @return Fome : un pointeur sur la forme lue, nullptr si la forme n'a pas �t� reconnue
	*/
	virtual Forme* sousLire(const char* msg) const = 0;
};


