#include <sstream>
#include "Polygone.h"
#include "../../VisiteursForme/VisiteurForme/VisiteurForme.h"


Polygone::Polygone(const string& couleur, const Vecteur2D& origine) : Forme(couleur, origine)
{
}

void Polygone::ajouter(const Vecteur2D& vecteur)
{
    // verifier si le point appartient
    points.push_back(vecteur);
}

Vecteur2D Polygone::get(int index) const
{
    if (index < 0 || index > points.size())
        return Vecteur2D(); //exception
}

void Polygone::retirer(const Vecteur2D* vecteur)
{
    /*TODO*/
}

Polygone::operator string() const
{
    ostringstream o;
    o << "polygone ";
    /*TODO*/
    return o.str();
}

const Forme Polygone::accepte(const VisiteurForme* visiteurForme)
{
    return visiteurForme->visite(this);
}
