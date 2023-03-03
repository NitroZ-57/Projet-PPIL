#include <sstream>
#include "Polygone.h"
#include "../VisiteursForme/VisiteurDessin.h"
#include "../Exceptions/QExceptionsGeometrie.h"
#include "../CoordMonde/CoordMonde.h"

Polygone::Polygone(const int& couleur, const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C) : Forme(couleur, A)
{
    // ajouter dans le sens anti-horraire
    points.push_back(A);
    if (Vecteur2D::determinantEstPositifOuNul(A, B)) {
        points.push_back(B);
        points.push_back(C);
    }
    else {
        points.push_back(C);
        points.push_back(B);
    }

}

Polygone::Polygone(const int& couleur, const vector<Vecteur2D>& points) : Forme(couleur, points[0]) {
    
    if (points.size() < 3)
        throw new QExceptionsNombrePointsInsuffisant("Il faut au moins 3 points pour creer un polygone");
    
    Vecteur2D v1(points[points.size()-1], points[0]);
    Vecteur2D v2(points[0], points[1]);
    bool signe = Vecteur2D::determinantEstPositifOuNul(v1, v2);
    this->points.push_back(points[0]);
    
    for (int i = 1; i < points.size()-1; i++) {
        v1 = Vecteur2D(points[i-1], points[i]);
        v2 = Vecteur2D(points[i], points[i+1]);
        if (signe != Vecteur2D::determinantEstPositifOuNul(v1, v2)) {
            throw new QExceptionsFormeNonConnexe("La forme ne doit pas avoir de creux");
        }
        this->points.push_back(points[i]);
    }

    v1 = Vecteur2D(points[points.size()-2], points[points.size()-1]);
    v2 = Vecteur2D(points[points.size()-1], points[0]);
    if (signe != Vecteur2D::determinantEstPositifOuNul(v1, v2)) {
        throw new QExceptionsFormeNonConnexe("La forme ne doit pas avoir de creux");
    }
    this->points.push_back(points[points.size() - 1]);
    
    Vecteur2D inter;
    if (!signe) { // inverse pour avoir le centre à gauche
        for (int i = 0; i < points.size() / 2; i++) {
            inter = this->points[i];
            this->points[i] = this->points[this->points.size() - i- 1];
            this->points[this->points.size() - i - 1] = inter;
        }
        setOrigine(points[0]);
    }

}

Vecteur2D Polygone::get(int index) const
{
    if (index < 0 || index > points.size())
        throw new QExceptionsIndiceHorsPortee("Get impossible, indice en dehors de la portee");
    return points[index];
}

Vecteur2D Polygone::getRectangleBG() const {
    double xMin = points[0].x, yMin = points[0].y;
    for (vector<Vecteur2D>::const_iterator it = points.begin() + 1; it != points.end(); it++) {
        if (it->x < xMin)
            xMin = it->x;
        if (it->y < yMin)
            yMin = it->y;
    }
    return Vecteur2D(xMin, yMin);
};
Vecteur2D Polygone::getRectangleHD() const {
    double xMax = points[0].x, yMax = points[0].y;
    for (vector<Vecteur2D>::const_iterator it = points.begin() + 1; it != points.end(); it++) {
        if (it->x > xMax)
            xMax = it->x;
        if (it->y > yMax)
            yMax = it->y;
    }
    return Vecteur2D(xMax, yMax);
}

void Polygone::getTransformation(const CoordMonde& c) {

    for (vector<Vecteur2D>::iterator it = points.begin(); it != points.end(); it++) {
        (*it) = c.transformer((*it));
    }

}

void Polygone::homothetie(const Vecteur2D& o, const double& k) {
    Vecteur2D inter = (1 - k) * o;
    for (int i = 0; i < points.size(); i++) {
        points[i] = (points[i] * k + inter);
    }
}
void Polygone::translation(const Vecteur2D& v) {
    for (int i = 0; i < points.size(); i++) {
        points[i] = (points[i] + v);
    }
}
void Polygone::rotation(const Vecteur2D& o, const double& a) {
    Vecteur2D rot = Vecteur2D::creerPolaire(a);
    for (int i = 0; i < points.size(); i++) {
        points[i] = ((rot ^ (points[i] - o)) + o);
    }
}
double Polygone::getAire() const {

    if (points.size() == 3)
        return Vecteur2D::aireTriangle(points[0], points[1], points[2]);

    Vecteur2D centre(0, 0);
    double aire = 0;
    for (int i = 0; i < points.size(); i++) {
        centre = centre + points[i];
    }
    double ratio = (points.size());
    centre = (1/ratio) * centre;
    for (int i = 1; i < points.size(); i ++) {
        aire += Vecteur2D::aireTriangle(points[i], points[i - 1], centre);
    }
    aire += Vecteur2D::aireTriangle(points[0], points[points.size() - 1], centre);
    return aire;
}

/*
polygone[couleur; (x, y); (x, y); (x, y); ]; 
*/
Polygone::operator string() const
{
    ostringstream o;
    o << "polygone[" << getCouleur() << "; ";
    for (vector<Vecteur2D>::const_iterator it = points.begin(); it != points.end(); it++) {
        o << (string)(*it) << "; ";
    }
    o << "]; ";
    return o.str();
}

bool Polygone::accepte(const VisiteurDessin* visiteurDessin)
{
    return visiteurDessin->dessine(this);
}
