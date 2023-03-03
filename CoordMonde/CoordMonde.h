#pragma once
#include "../Formes/Vecteur2D.h"
#include "../Formes/Forme.h"
#include <vector>

/*
* @brief Classe permettant de faire des calculs sur les coordonn�es mondes pour les transformer en coordon�es �cran
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
	* @brief Cette m�thode calcule le premier rectangle du monde � partir d'un ensemble de formes
	* @param v : l'ensemble de formes � afficher
	*/
	void calculerRect(const vector<Forme*>& v);

	/*
	* @brief Cette m�thode calcule la valeur de lambda � partir de e1 et de e2
	* @param e1 : la valeur de e1 
	* @param e2 : la valeur de e2
	*/
	void calculerLambda(double e1, double e2);

	/*
	* @brief Cette m�thode calcule la valeur de e1 � partir des rectangles P1 et P2 en champ de la classe
	* @return double : la valeur de e1
	*/
	double calculerE1() const;

	/*
	* @brief Cette m�thode calcule la valeur de e2 � partir des rectangles P1 et P2 en champ de la classe
	* @return double : la valeur de e2
	*/
	double calculerE2() const;

	/*
	* @brief Cette m�thode calcule la valeur a et b pour faire la transformation de coordon�es mondes � �cran
	*/
	void calculerAB();


public:
	/*
	* @brief Cr�er une instance de coordon�es mondes pour faire les calculs vers les coordonn�es �crans
	* @param v : l'ensemble de formes � afficher
	* @param tailleFenetre : la taille de fenetre associ� (x pour hauteur et y largeur)
	*/
	CoordMonde(const vector<Forme*> &v, Vecteur2D tailleFenetre);

	/*
	* @brief Transforme un Vecteur2D avec ses coordon�es mondes vers un Vecteur2D avec ses coordonn�es �cran
	* @return Vecteur2D : le vecteur avec les coordon�es �cran
	*/
	Vecteur2D transformer(const Vecteur2D& v) const;

	/*
	* @brief Modifie un enseble de formes de leurs coordon�es mondes vers leurs coordonn�es �cran
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