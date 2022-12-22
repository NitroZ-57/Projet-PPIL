#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurForme;
using namespace std;

class Segment : public Forme {

private:
    Vecteur2D segment;

public:

    Segment(const string& couleur, const Vecteur2D& vecteur);
    virtual ~Segment();

    void setSegment(const Vecteur2D& vecteur);
    Vecteur2D getSegment() const;

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Segment

inline ostream& operator << (ostream & os, const Segment& segment) {
    return os << (string)segment;
}