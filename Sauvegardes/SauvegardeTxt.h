#pragma once

#include "../Formes/Forme.h"
#include "Sauvegarde.h"
#include <vector>
#include <istream>

/*
* @brief Cette classe abstraite est une dérivée de la classe de Sauvegarde, elle correspond aux sauvegarde dans un fichier texte (.txt). En l'implémentant on peut choisir la manière de lire les fichiers 
*/
class SauvegardeTxt : public Sauvegarde {

private:
	/*
	* @brief La longueure maximum du fichier à ne pas dépasser
	*/
	static const int LONGEUR_MAX_NOM_FICHIER = 100;

	const char* nomFichier = nullptr;

public:

	SauvegardeTxt();

	/*
	* @brief Cette méthode sert à définir un nom de fichier pour pouvoir l'utiliser par la suite
	* @param nomFichier : le nom du fichier de max 100 caractères
	*/
	void setNomFichier(const char* nomFichier);

	virtual ~SauvegardeTxt();

	/*
	* @brief Cette méthode renvoit une exception car l'on ne peut pas lire qu'une seule forme dans un fichier texte
	*/
	virtual Forme*& lire() const;

	/*
	* @brief Cette méthode renvoit une exception car l'on ne peut pas écrire qu'une seule forme dans un fichier texte
	*/
	virtual bool ecrire(const Forme*& forme) const;

	/*
	* @brief Cette méthode abtraite doit être à dériver et sera utilisé dans la fonction lireEns() pour lire un ensemble de forme selon le protocole
	* @param msg : une chaine de caractère à décrypter en forme
	* @return Forme : un pointeur sur la forme lue dans le fichier
	*/
	virtual Forme* lire(const char *msg) const = 0;

	/*
	* @breif Cette méthode sert à lire un ensemble de forme dans un fichier texte suivant le protocole et retourne un vector de pointeurs sur des formes
	* @return vector<Forme*> : l'ensemble des formes lues dans le fichier
	*/
	virtual vector<Forme*> lireEns() const;

	/*
	* @brief Cette méthode sert à écrire un ensemble de forme passé en paramètre via un vector dans un fichier texte en utilisant l'opérateur (string)
	* @param vector<Forme*> : l'ensemble de formes à écrire dans le fichier
	* @return bool : vrai si l'écriture à réussie, faux sinon
	*/
	virtual bool ecrireEns(const vector<Forme*>&) const;

};
