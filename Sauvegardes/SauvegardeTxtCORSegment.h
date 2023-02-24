#pragma once
#include "SauvegardeTxtCOR.h"

class SauvegardeTxtCORSegment : public SauvegardeTxtCOR {


public:
	SauvegardeTxtCORSegment(SauvegardeTxtCOR * suivant);
	virtual Forme* sousLire(const char* msg) const;


};