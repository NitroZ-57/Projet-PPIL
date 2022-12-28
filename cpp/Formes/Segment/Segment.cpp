#include <sstream>
#include "Segment.h"
#include "../../VisiteursForme/VisiteurForme/VisiteurForme.h"


Segment::Segment(const string& couleur, const Vecteur2D& vecteur, const Vecteur2D& origine) : Forme(couleur, origine)
{
    setSegment(vecteur);
}

void Segment::setSegment(const Vecteur2D& vecteur)
{
    segment = vecteur;
}

Vecteur2D Segment::getSegment() const
{
    return segment;
}

Segment::operator string() const
{
    ostringstream o;
    o << "segment " << (string)getOrigine() << " " << (string)getSegment() << " ;";
    return o.str();
}

const Forme Segment::accepte(const VisiteurForme* visiteurForme)
{
    return visiteurForme->visite(this);
}
