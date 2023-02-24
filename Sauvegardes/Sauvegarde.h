#pragma once

#include "../Formes/Forme.h"
#include <vector>

class Sauvegarde {

public:
	virtual Forme*& lire() const = 0;
	virtual bool ecrire(const Forme*& forme) const = 0;
	virtual vector<Forme*> lireEns() const = 0;
	virtual bool ecrireEns(const vector<Forme*>& formes) const = 0;

};
