#pragma once

#include "../Formes/Forme.h"
#include "Sauvegarde.h"
#include <vector>
#include <istream>

/*
* @brief Cette classe abstraite est une d�riv�e de la classe de Sauvegarde, elle correspond aux sauvegarde dans un fichier texte (.txt). En l'impl�mentant on peut choisir la mani�re de lire les fichiers 
*/
class SauvegardeTxt : public Sauvegarde {

private:
	/*
	* @brief La longueure maximum du fichier � ne pas d�passer
	*/
	static const int LONGEUR_MAX_NOM_FICHIER = 100;

	const char* nomFichier = nullptr;

public:

	SauvegardeTxt();

	/*
	* @brief Cette m�thode sert � d�finir un nom de fichier pour pouvoir l'utiliser par la suite
	* @param nomFichier : le nom du fichier de max 100 caract�res
	*/
	void setNomFichier(const char* nomFichier);

	virtual ~SauvegardeTxt();

	/*
	* @brief Cette m�thode renvoit une exception car l'on ne peut pas lire qu'une seule forme dans un fichier texte
	*/
	virtual Forme*& lire() const;

	/*
	* @brief Cette m�thode renvoit une exception car l'on ne peut pas �crire qu'une seule forme dans un fichier texte
	*/
	virtual bool ecrire(const Forme*& forme) const;

	/*
	* @brief Cette m�thode abtraite doit �tre � d�river et sera utilis� dans la fonction lireEns() pour lire un ensemble de forme selon le protocole
	* @param msg : une chaine de caract�re � d�crypter en forme
	* @return Forme : un pointeur sur la forme lue dans le fichier
	*/
	virtual Forme* lire(const char *msg) const = 0;

	/*
	* @breif Cette m�thode sert � lire un ensemble de forme dans un fichier texte suivant le protocole et retourne un vector de pointeurs sur des formes
	* @return vector<Forme*> : l'ensemble des formes lues dans le fichier
	*/
	virtual vector<Forme*> lireEns() const;

	/*
	* @brief Cette m�thode sert � �crire un ensemble de forme pass� en param�tre via un vector dans un fichier texte en utilisant l'op�rateur (string)
	* @param vector<Forme*> : l'ensemble de formes � �crire dans le fichier
	* @return bool : vrai si l'�criture � r�ussie, faux sinon
	*/
	virtual bool ecrireEns(const vector<Forme*>&) const;

};
