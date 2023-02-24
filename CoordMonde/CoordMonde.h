#pragma once
#include "../Formes/Vecteur2D.h"
#include "../Formes/Forme.h"
#include <vector>

class CoordMonde {
public:
	CoordMonde() {};
	Vecteur2D P1; //(x1, y1)
	Vecteur2D P2; //(x2, y2)
	Vecteur2D P1prime; //(x1', y1')
	Vecteur2D P2prime; //(x2', y2')

	Vecteur2D lambda;
	Vecteur2D ab;
	
	void calculerRect(const vector<Forme*>& v);
	void calculerLambda(double e1, double e2);
	double calculerE1() const;
	double calculerE2() const;
	void calculerAB();


public:
	CoordMonde(const vector<Forme*> &v, Vecteur2D tailleFenetre);
	Vecteur2D transformer(const Vecteur2D& v) const;

	



};