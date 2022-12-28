#include <sstream>
#include "Cercle.h"
#include "../../VisiteursForme/VisiteurForme/VisiteurForme.h"

Cercle::Cercle(const string& couleur, const Vecteur2D& rayon, const Vecteur2D origine) : Forme(couleur, origine)
{
    setRayon(rayon);
}

void Cercle::setRayon(const Vecteur2D& rayon)
{
    this->rayon = rayon;
}

Vecteur2D Cercle::getRayon() const
{
    return rayon;
}


Cercle::operator string() const
{
    ostringstream o;
    o << "cercle " << (string)getOrigine() << " " << (string)getRayon()/*avoir le rayon*/ << ";";
    return o.str();

}

const Forme Cercle::accepte(const VisiteurForme* visiteurForme)
{
    return visiteurForme->visite(this);
}
