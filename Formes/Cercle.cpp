#include <sstream>
#include "Cercle.h"
#include "../VisiteursForme/VisiteurDessin.h"
#include "../CoordMonde/CoordMonde.h"
#define PI 3.1415

Cercle::Cercle(const int& couleur, const Vecteur2D& origine, const Vecteur2D &rayon) : Forme(couleur, origine)
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

Vecteur2D Cercle::getRectangleHD() const {
    double x = getOrigine().x + rayon.x;
    double y = getOrigine().y + rayon.y;
    return Vecteur2D(x, y);
}
Vecteur2D Cercle::getRectangleBG() const {
    double x = getOrigine().x - rayon.x;
    double y = getOrigine().y - rayon.y;
    return Vecteur2D(x, y);
}
Forme* Cercle::getTransformation(const CoordMonde& c) const {
    Vecteur2D o2 = c.transformer(getOrigine());
    Vecteur2D r2 = c.transformer(rayon);
    return (Forme*) new Cercle(getIntCouleur(), o2, r2);
}
void Cercle::homothetie(const Vecteur2D& o, const double& k) {
    Vecteur2D inter = (1 - k) * o;
    setOrigine(getOrigine() * k + inter);
    setRayon(getRayon() * k + inter);
}
void Cercle::translation(const Vecteur2D& v) {
    setOrigine(getOrigine() + v);
    setRayon(getRayon() + v);
}
void Cercle::rotation(const Vecteur2D& o, const double& a) {
    Vecteur2D rot = Vecteur2D::creerPolaire(a);
    setOrigine((rot ^ (getOrigine() - o)) + o);
    setRayon((rot ^ (getRayon() - o)) + o);
}

double Cercle::getAire() const {
    return PI*rayon.getNorme()*rayon.getNorme();
}

/*
cercle[jaune; (12, 89); 12]; 
cercle[couleur; (xorigine, yorigine); rayon]; 
*/
Cercle::operator string() const
{
    ostringstream o;
    o << "cercle[" << getCouleur() << "; " << (string)getOrigine() << "; " << rayon.getNorme() << "]; ";
    return o.str();

}

bool Cercle::accepte(const VisiteurDessin* visiteurDessin)
{
    return visiteurDessin->dessine(this);
}
