#include "CoordMonde.h"
#include "../Exceptions/QExceptionsCoordMonde.h"


CoordMonde::CoordMonde(const vector<Forme*>& v, Vecteur2D tailleFenetre) {
	if (v.size() == 0)
		throw new QExceptionsNombreFormeIncorrect("Aucune forme pour faire les coordonnees mondes");
	
	P1prime = Vecteur2D(0, tailleFenetre.y);
	P2prime = Vecteur2D(tailleFenetre.x, 0);

	calculerRect(v);
	calculerLambda(calculerE1(), calculerE2());
	calculerAB();
	
}


void CoordMonde::calculerRect(const vector<Forme*>& v) {

	Vecteur2D HD1 = v[0]->getRectangleHD();
	Vecteur2D BG1 = v[0]->getRectangleBG();
	for (vector<Forme*>::const_iterator it = v.begin() + 1; it != v.end(); it++) {
		Vecteur2D HD2 = (*it)->getRectangleHD();
		Vecteur2D BG2 = (*it)->getRectangleBG();

		if (HD2.x > HD1.x)
			HD1.x = HD2.x;
		if (HD2.y > HD1.y)
			HD1.y = HD2.y;

		if (BG2.x < BG1.x)
			BG1.x = BG2.x;
		if (BG2.y < BG1.y)
			BG1.y = BG2.y;
	}

	P1 = Vecteur2D(HD1.x, HD1.y);
	P2 = Vecteur2D(BG1.x, BG1.y);

}


void CoordMonde::calculerLambda(double e1, double e2) {
	Vecteur2D v = abs(P2prime - P1prime) / abs(P2 - P1);
	double l;
	if (v.x < v.y)
		l = v.x;
	else
		l = v.y;
	lambda = Vecteur2D(l * e1, l * e2);
}

double CoordMonde::calculerE1() const {
	bool positif1 = (P2.x - P1.x) > 0;
	bool positif2 = (P2prime.x - P1prime.x) > 0;
	if (positif1 == positif2)
		return 1;
	else
		return -1;
}
double CoordMonde::calculerE2() const {
	bool positif1 = (P2.y - P1.y) > 0;
	bool positif2 = (P2prime.y - P1prime.y) > 0;
	if (positif1 == positif2)
		return 1;
	else
		return -1;
}


void CoordMonde::calculerAB() {
	Vecteur2D C = (P1 + P2) * 0.5;
	Vecteur2D Cprime = (P1prime + P2prime) * 0.5;
	cout << "C" << C << endl << "C'" << Cprime << endl;
	ab = Cprime - lambda * C;

}


Vecteur2D CoordMonde::transformer(const Vecteur2D& v) const {
	return v * lambda + ab;
}