#include "SauvegardeTxtCORSegment.h"
#include "../Formes/Segment.h"


SauvegardeTxtCORSegment::SauvegardeTxtCORSegment(SauvegardeTxtCOR* suivant):
	SauvegardeTxtCOR(suivant)
{
}

Forme* SauvegardeTxtCORSegment::sousLire(const char* msg) const
{
	char* msg2 = _strdup(msg);
	string s = (string)msg2;
	stringstream splitChaine;

	if (s.rfind("segment", 0) == 0) {
		char* deb = strchr(msg2, '[');
		deb += 1;
		
		char* nxtStr = strtok(deb, ";");
		int couleur = Forme::getIntCouleur(nxtStr);

		nxtStr = strtok(nullptr, ";");
		nxtStr += 1; // enlever l'espace
		Vecteur2D *origine = Vecteur2D::creerString(nxtStr);
		
		nxtStr = strtok(nullptr, "]");
		nxtStr += 1; // enlever l'espace
		Vecteur2D* segment = Vecteur2D::creerString(nxtStr);

		delete msg2;
		return (Forme*)new Segment(couleur, *origine, *segment);

	}
	delete msg2;
	return nullptr;
}
