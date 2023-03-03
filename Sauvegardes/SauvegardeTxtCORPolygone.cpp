#include "SauvegardeTxtCORPolygone.h"
#include "../Formes/Polygone.h"

#include <vector>

SauvegardeTxtCORPolygone::SauvegardeTxtCORPolygone(SauvegardeTxtCOR* suivant):
	SauvegardeTxtCOR(suivant)
{
}

Forme* SauvegardeTxtCORPolygone::sousLire(const char* msg) const
{
	char* msg2 = _strdup(msg);

	string s = (string)msg2;
	vector<Vecteur2D> v;

	if (s.rfind("polygone", 0) == 0) {
		char* deb = strchr(msg2, '[');
		deb += 1;

		char* nxtStr = strtok(deb, ";");
		int couleur = Forme::getIntCouleur(nxtStr);

		nxtStr = strtok(nullptr, ";");
		while (strchr(nxtStr, ']') == nullptr) {
			nxtStr += 1; //enlever l'espace
			Vecteur2D* point = Vecteur2D::creerString(nxtStr);

			v.push_back(*point);

			nxtStr = strtok(nullptr, ";");
			delete point;
		}
		delete msg2;
		return (Forme*)new Polygone(couleur, v);

	}
	delete msg2;
	return nullptr;
}
