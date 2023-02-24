#pragma once

#include "../Formes/Forme.h"
#include "Sauvegarde.h"
#include <vector>
#include <istream>

class SauvegardeTxt : public Sauvegarde {

private:
	static const int LONGEUR_MAX_NOM_FICHIER = 100;
	const char* nomFichier = nullptr;

public:

	SauvegardeTxt();

	void setNomFichier(const char* nomFichier);
	virtual Forme*& lire() const;
	virtual bool ecrire(const Forme*& forme) const;
	virtual Forme* lire(const char *msg) const = 0;
	virtual vector<Forme*> lireEns() const;
	virtual bool ecrireEns(const vector<Forme*>&) const;

};
