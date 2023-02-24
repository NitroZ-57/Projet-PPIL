#include "SauvegardeTxtCORGroupe.h"
#include "SauvegardeTxtCORCercle.h"
#include "SauvegardeTxtCORPolygone.h"
#include "SauvegardeTxtCORSegment.h"
#include "../Formes/Groupe.h"

SauvegardeTxtCORGroupe::SauvegardeTxtCORGroupe(SauvegardeTxtCOR* suivant):
	SauvegardeTxtCOR(suivant)
{
}

Forme* SauvegardeTxtCORGroupe::sousLire(const char* msg) const
{
	char* msg2 = _strdup(msg);

	string s = (string)msg2;

	// création de la chaine de responsabilité pour refaire chaque forme du groupe
	SauvegardeTxtCOR *sauvegarde = new SauvegardeTxtCORGroupe(nullptr);
	sauvegarde = new SauvegardeTxtCORPolygone(sauvegarde);
	sauvegarde = new SauvegardeTxtCORSegment(sauvegarde);
	sauvegarde = new SauvegardeTxtCORCercle(sauvegarde);

	if (s.rfind("groupe", 0) == 0) {
		// debut de la couleur
		char* deb = strchr(msg2, '[');
		deb += 1;

		char* end = strchr(deb, ';');
		end[0] = '\0';
		// fin de la couleur

		int couleur = Forme::getIntCouleur(deb);
		Groupe *grp = new Groupe(couleur);
		end[0] = ';';
		end += 2;

		vector<char*> formes = Groupe::parseurGroupe(end);

		for (int i = 0; i < formes.size(); i++) {
			grp->ajouter(sauvegarde->lire(formes[i]));
			delete formes[i];
		}



		delete msg2;
		return grp;


	}
	delete msg2;
	return nullptr;
}
