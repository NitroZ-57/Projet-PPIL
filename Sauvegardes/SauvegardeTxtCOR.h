#pragma once
#include "SauvegardeTxt.h"


/*
* @brief Cette classe sert de début de chaine de responsabilité pour permettre de lire des formes dans un fichier texte. Cette classe hérite de la classe SauvegardeTxt
*/
class SauvegardeTxtCOR : public SauvegardeTxt
{
	SauvegardeTxtCOR* suivant;  

public:

	/*
	* @brief Créer un maillon de la chaine de responsabilité et ajoute le maillon donné en paramètre en queue 
	* @param le prochain maillon de la chaine de responsabilité
	*/
	SauvegardeTxtCOR(SauvegardeTxtCOR* suivant);

	/*
	* @brief Cette méthode sert de point de lancement de la chaine de responsabilité
	* @param msg : la chaine de caractère sur laquelle lire la forme
	* @return Fome : un pointeur sur la forme lue
	*/
	virtual Forme* lire(const char* msg) const;

protected:

	/*
	* @brief Cette méthode abstraite est à redéfinir pour chaque type de forme qui à pour but d'être reconnu dans un fichier texte
	* @param msg : la chaine de caractère sur laquelle lire la forme
	* @return Fome : un pointeur sur la forme lue, nullptr si la forme n'a pas été reconnue
	*/
	virtual Forme* sousLire(const char* msg) const = 0;
};


