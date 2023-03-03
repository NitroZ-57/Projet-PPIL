#pragma once
#include "../Formes/Vecteur2D.h"
#include "../Formes/Forme.h"
#include <vector>

/*
* @brief Classe permettant de faire des calculs sur les coordonnées mondes pour les transformer en coordonées écran
*/
class CoordMonde {
private:
	Vecteur2D P1; //(x1, y1)
	Vecteur2D P2; //(x2, y2)
	Vecteur2D P1prime; //(x1', y1')
	Vecteur2D P2prime; //(x2', y2')

	Vecteur2D lambda; // (l*e1, l*e2)
	Vecteur2D ab; //(a, b)
	
	/*
	* @brief Cette méthode calcule le premier rectangle du monde à partir d'un ensemble de formes
	* @param v : l'ensemble de formes à afficher
	*/
	void calculerRect(const vector<Forme*>& v);

	/*
	* @brief Cette méthode calcule la valeur de lambda à partir de e1 et de e2
	* @param e1 : la valeur de e1 
	* @param e2 : la valeur de e2
	*/
	void calculerLambda(double e1, double e2);

	/*
	* @brief Cette méthode calcule la valeur de e1 à partir des rectangles P1 et P2 en champ de la classe
	* @return double : la valeur de e1
	*/
	double calculerE1() const;

	/*
	* @brief Cette méthode calcule la valeur de e2 à partir des rectangles P1 et P2 en champ de la classe
	* @return double : la valeur de e2
	*/
	double calculerE2() const;

	/*
	* @brief Cette méthode calcule la valeur a et b pour faire la transformation de coordonées mondes à écran
	*/
	void calculerAB();


public:
	/*
	* @brief Créer une instance de coordonées mondes pour faire les calculs vers les coordonnées écrans
	* @param v : l'ensemble de formes à afficher
	* @param tailleFenetre : la taille de fenetre associé (x pour hauteur et y largeur)
	*/
	CoordMonde(const vector<Forme*> &v, Vecteur2D tailleFenetre);

	/*
	* @brief Transforme un Vecteur2D avec ses coordonées mondes vers un Vecteur2D avec ses coordonnées écran
	* @return Vecteur2D : le vecteur avec les coordonées écran
	*/
	Vecteur2D transformer(const Vecteur2D& v) const;

	/*
	* @brief Modifie un enseble de formes de leurs coordonées mondes vers leurs coordonnées écran
	*/
	void transformer(vector<Forme*>& formes) const;


	friend inline ostream& operator << (ostream& os, const CoordMonde& c);
};


inline ostream& operator << (ostream& os, const CoordMonde& c) {
	os << "P1  : " << c.P1 << endl;
	os << "P2  : " << c.P2 << endl;
	os << "P1' : " << c.P1prime << endl;
	os << "P2' : " << c.P2prime << endl;
	os << "l   : " << c.lambda << endl;
	os << "ab  : " << c.ab << endl;
	return os;
}