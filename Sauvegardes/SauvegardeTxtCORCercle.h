#pragma once
#include "SauvegardeTxtCOR.h"

class SauvegardeTxtCORCercle : public SauvegardeTxtCOR {


public:
	SauvegardeTxtCORCercle(SauvegardeTxtCOR * suivant);
	virtual Forme* sousLire(const char* msg) const;


};