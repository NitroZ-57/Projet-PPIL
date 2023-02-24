#pragma once
#include "SauvegardeTxtCOR.h"

class SauvegardeTxtCORGroupe : public SauvegardeTxtCOR {


public:
	SauvegardeTxtCORGroupe(SauvegardeTxtCOR * suivant);
	virtual Forme* sousLire(const char* msg) const;


};