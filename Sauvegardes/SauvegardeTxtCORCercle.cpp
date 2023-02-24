#include "SauvegardeTxtCORCercle.h"
#include "../Formes/Cercle.h"

SauvegardeTxtCORCercle::SauvegardeTxtCORCercle(SauvegardeTxtCOR* suivant):
	SauvegardeTxtCOR(suivant)
{
}

Forme* SauvegardeTxtCORCercle::sousLire(const char* msg) const
{
	char* msg2 = _strdup(msg);
	string s = (string)msg2;

	if (s.rfind("cercle", 0) == 0) {
		char* deb = strchr(msg2, '[');
		deb += 1;

		char* nxtStr = strtok(deb, ";");
		int couleur = Forme::getIntCouleur(nxtStr);

		nxtStr = strtok(nullptr, ";");
		nxtStr += 1; // enlever l'espace
		Vecteur2D* origine = Vecteur2D::creerString(nxtStr);

		nxtStr = strtok(nullptr, "]");
		nxtStr += 1; // enlever l'espace
		double r;
		int res = sscanf_s(nxtStr, "%lf", &r);

		if (res == 1) {
			delete msg2;
			return (Forme*)new Cercle(couleur, *origine, Vecteur2D(r) );
		}
	}
	delete msg2;
	return nullptr;
}
