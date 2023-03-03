#pragma once

#include "../Formes/Forme.h"
#include <vector>


/*
* @brief Cette classe sert � sauvegarder des formes ou � les charger. Cette classe est abstraite, en la d�rivant on impl�mente les fonctions d'�criture et de lecture pour pouvoir stocker les donn�es dans d'autres endroits ou formats
*/
class Sauvegarde {

public:
	/*
	* @brief Cette m�thode abstraite sert � lire une forme
	* @return Forme : pointeur sur la forme lue
	*/
	virtual Forme*& lire() const = 0;

	/*
	* @brief Cette m�thode abstraite sert � �crire une forme
	* @param forme : la forme � �crire
	* @return bool : vrai si l'�criture � r�ussie, faux sinon
	*/
	virtual bool ecrire(const Forme*& forme) const = 0;

	/*
	* @brief Cette m�thode abstraite sert � lire un ensemble de formes
	* @return vector<Forme*> : un ensemble de pointeurs sur les formes lues
	*/
	virtual vector<Forme*> lireEns() const = 0;

	/*
	* @brief Cette m�thode abstraite sert � �crire un ensemble de forme
	* @param vector<Forme*> : l'ensemble des formes � �crire 
	* @return bool : vrai si l'�criture � r�ussie, faux sinon
	*/
	virtual bool ecrireEns(const vector<Forme*>& formes) const = 0;

};
