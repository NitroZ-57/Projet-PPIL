#include <sstream>
#include "Groupe.h"
#include "../../VisiteursForme/VisiteurForme/VisiteurForme.h"


Groupe::Groupe(const string& couleur) : Forme(couleur, Vecteur2D(0, 0))
{
}

void Groupe::ajouter(Forme* forme)
{
    formes.push_back(forme);
}

Vecteur2D Groupe::get(int index) const
{
    if (index < 0 || index > formes.size())
        return Vecteur2D(); //exception
    
}

void Groupe::retirer(const Forme* forme)
{
    /*TODO*/
}

Groupe::operator string() const
{
    ostringstream o;
    o << "groupe [ ";
    /*TODO*/
    o << "] ;";
    return o.str();
}

const Forme Groupe::accepte(const VisiteurForme* visiteurForme)
{
    return visiteurForme->visite(this);
}
