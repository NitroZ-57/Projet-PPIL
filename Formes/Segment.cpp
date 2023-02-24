#include <sstream>
#include "Segment.h"
#include "../VisiteursForme/VisiteurDessin.h"
#include "../CoordMonde/CoordMonde.h"

Segment::Segment(const int& couleur, const Vecteur2D& origine, const Vecteur2D& vecteur) : Forme(couleur, origine)
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

Vecteur2D Segment::getRectangleBG() const {
    double x, y;
    if (getOrigine().x < getSegment().x)
        x = getOrigine().x;
    else
        x = getSegment().x;

    if (getOrigine().y < getSegment().y)
        y = getOrigine().y;
    else
        y = getSegment().y;

    return Vecteur2D(x, y);
}
Vecteur2D Segment::getRectangleHD() const {
    double x, y;
    if (getOrigine().x > getSegment().x)
        x = getOrigine().x;
    else
        x = getSegment().x;

    if (getOrigine().y > getSegment().y)
        y = getOrigine().y;
    else
        y = getSegment().y;

    return Vecteur2D(x, y);
}

Forme* Segment::getTransformation(const CoordMonde& c) const {
    Vecteur2D o2 = c.transformer(getOrigine());
    Vecteur2D s2 = c.transformer(segment);
    return (Forme*)new Segment(getIntCouleur(), o2, s2);
}

void Segment::homothetie(const Vecteur2D& o, const double& k) {
    Vecteur2D inter = (1 - k) * o;
    setOrigine(getOrigine() * k + inter);
    setSegment(getSegment() * k + inter);
}
void Segment::translation(const Vecteur2D& v) {
    setOrigine(getOrigine() + v);
    setSegment(getSegment() + v);
}
void Segment::rotation(const Vecteur2D& o, const double& a) {
    Vecteur2D rot = Vecteur2D::creerPolaire(a);
    setOrigine((rot ^ (getOrigine() - o)) + o);
    setSegment((rot ^ (getSegment() - o)) + o);
}

double Segment::getAire() const {
    return 0;
}


/*
segment[rouge; (12, 89); (67, 90)]; 
segment[couleur; (xorigine, yorigine); (xdestination, ydestination)]; 
*/
Segment::operator string() const
{
    ostringstream o;
    o << "segment[" << getCouleur() << "; " << (string)getOrigine() << "; " << (string)getSegment() << "]; ";
    return o.str();
}

bool Segment::accepte(const VisiteurDessin* visiteurForme)
{
    return visiteurForme->dessine(this);
}
