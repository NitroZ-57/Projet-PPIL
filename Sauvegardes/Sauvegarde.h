#pragma once

#include "../Formes/Forme.h"
#include <vector>


/*
* @brief Cette classe sert à sauvegarder des formes ou à les charger. Cette classe est abstraite, en la dérivant on implémente les fonctions d'écriture et de lecture pour pouvoir stocker les données dans d'autres endroits ou formats
*/
class Sauvegarde {

public:
	/*
	* @brief Cette méthode abstraite sert à lire une forme
	* @return Forme : pointeur sur la forme lue
	*/
	virtual Forme*& lire() const = 0;

	/*
	* @brief Cette méthode abstraite sert à écrire une forme
	* @param forme : la forme à écrire
	* @return bool : vrai si l'écriture à réussie, faux sinon
	*/
	virtual bool ecrire(const Forme*& forme) const = 0;

	/*
	* @brief Cette méthode abstraite sert à lire un ensemble de formes
	* @return vector<Forme*> : un ensemble de pointeurs sur les formes lues
	*/
	virtual vector<Forme*> lireEns() const = 0;

	/*
	* @brief Cette méthode abstraite sert à écrire un ensemble de forme
	* @param vector<Forme*> : l'ensemble des formes à écrire 
	* @return bool : vrai si l'écriture à réussie, faux sinon
	*/
	virtual bool ecrireEns(const vector<Forme*>& formes) const = 0;

};
