#pragma once

#include <iostream>
#include <string>
#include "../Vecteur2D/Vecteur2D.h"
#include "../Forme/Forme.h"

class VisiteurForme;
using namespace std;

class Cercle : public Forme {

private:
    Vecteur2D rayon;

public:

    Cercle(const string& couleur, const Vecteur2D& rayon, const Vecteur2D origine);
    virtual ~Cercle(){};

    void setRayon(const Vecteur2D& rayon);
    Vecteur2D getRayon() const;

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Cercle

inline ostream& operator << (ostream & os, const Cercle& cercle) {
    return os << (string)cercle;
}