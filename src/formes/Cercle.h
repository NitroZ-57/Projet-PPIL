#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

using namespace std;

class Cercle : public Forme {

private:
    Vecteur2D centre;

public:

    Cercle(const string& couleur, const Vecteur2D& vecteur);
    virtual ~Cercle();

    void setCentre(const Vecteur2D& vecteur);
    Vecteur2D getCentre() const;

    operator string () const;

}; // Segment

inline ostream& operator << (ostream & os, const Cercle& cercle) {
    return os << (string)cercle;
}