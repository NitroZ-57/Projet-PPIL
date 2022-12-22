#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurForme;
using namespace std;

class Triangle : public Forme {

private:
    Vecteur2D cote1;
    Vecteur2D cote2;

public:

    Triangle(const string& couleur, const Vecteur2D& cote1, const Vecteur2D& cote2);
    virtual ~Triangle();

    void setCote1(const Vecteur2D& cote1);
    void setCote2(const Vecteur2D& cote2);
    Vecteur2D getCote1() const;
    Vecteur2D getCote2() const;

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Triangle

inline ostream& operator << (ostream & os, const Triangle& triangle) {
    return os << (string)triangle;
}