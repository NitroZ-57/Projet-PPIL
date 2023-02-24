#include "SauvegardeTxtCOR.h"

SauvegardeTxtCOR::SauvegardeTxtCOR(SauvegardeTxtCOR* suivant)
{
	this->suivant = suivant;

}

Forme* SauvegardeTxtCOR::lire(const char* msg) const
{

	Forme* f = sousLire(msg);
	if (f != nullptr)
		return f;
	
	if (suivant != nullptr)
		return suivant->lire(msg);
	
	return nullptr;


}
