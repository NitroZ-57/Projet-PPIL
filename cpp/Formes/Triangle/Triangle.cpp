#include <sstream>
#include "Triangle.h"
#include "../../VisiteursForme/VisiteurForme/VisiteurForme.h"


Triangle::Triangle(const string& couleur, const Vecteur2D& cote1, const Vecteur2D& cote2, const Vecteur2D& origine) : Forme(couleur, origine)
{
    setCote1(cote1);
    setCote2(cote2);
}

void Triangle::setCote1(const Vecteur2D& cote1)
{
    this->cote1 = cote1;
}

void Triangle::setCote2(const Vecteur2D& cote2)
{
    this->cote2 = cote2;
}

Vecteur2D Triangle::getCote1() const
{
    return cote1;
}

Vecteur2D Triangle::getCote2() const
{
    return cote2;
}

Triangle::operator string() const
{
    ostringstream o;
    o << "triangle " << (string)getOrigine() << " " << (string)cote1 << " " << (string)cote2 << " ;";
    return o.str();
}

const Forme Triangle::accepte(const VisiteurForme* visiteurForme)
{
    return visiteurForme->visite(this);
}
