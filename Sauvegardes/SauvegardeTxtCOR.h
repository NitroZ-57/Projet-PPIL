#pragma once
#include "SauvegardeTxt.h"

class SauvegardeTxtCOR : public SauvegardeTxt
{

	SauvegardeTxtCOR* suivant;  

public:
	SauvegardeTxtCOR(SauvegardeTxtCOR* suivant);

	virtual Forme* lire(const char* msg) const;

protected:
	virtual Forme* sousLire(const char* msg) const = 0;
};


