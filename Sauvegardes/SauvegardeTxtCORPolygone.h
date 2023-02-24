#pragma once
#include "SauvegardeTxtCOR.h"

class SauvegardeTxtCORPolygone : public SauvegardeTxtCOR {


public:
	SauvegardeTxtCORPolygone(SauvegardeTxtCOR * suivant);
	virtual Forme* sousLire(const char* msg) const;


};