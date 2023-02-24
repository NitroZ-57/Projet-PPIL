#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

class Cercle : public Forme {

private:
    Vecteur2D rayon;

public:

    Cercle(const int& couleur, const Vecteur2D& origine, const Vecteur2D& rayon);
    virtual ~Cercle(){};

    void setRayon(const Vecteur2D& rayon);
    Vecteur2D getRayon() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurForme);

    virtual Vecteur2D getRectangleHD() const;
    virtual Vecteur2D getRectangleBG() const;
    virtual Forme* getTransformation(const CoordMonde& c) const;
    virtual void homothetie(const Vecteur2D& o, const double& k);
    virtual void translation(const Vecteur2D& v);
    virtual void rotation(const Vecteur2D& o, const double& a);

    virtual double getAire() const;


}; // Cercle

inline ostream& operator << (ostream & os, const Cercle& cercle) {
    return os << (string)cercle;
}