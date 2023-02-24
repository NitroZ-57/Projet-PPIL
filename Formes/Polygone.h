#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
class CoordMonde;
using namespace std;

class Polygone : public Forme {

private:
    vector<Vecteur2D> points;

public:

    Polygone(const int& couleur, const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C);
    Polygone(const int& couleur, const vector<Vecteur2D>& points);
    virtual ~Polygone(){};

    Vecteur2D get(int index) const;

    virtual Vecteur2D getRectangleHD() const;
    virtual Vecteur2D getRectangleBG() const;
    virtual Forme* getTransformation(const CoordMonde& c) const;
    virtual void homothetie(const Vecteur2D& o, const double& k);
    virtual void translation(const Vecteur2D& v);
    virtual void rotation(const Vecteur2D& o, const double& a);

    virtual double getAire() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Polygone

inline ostream& operator << (ostream & os, const Polygone& polygone) {
    return os << (string)polygone;
}