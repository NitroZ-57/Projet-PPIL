#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurForme;
using namespace std;

class Polygone : public Forme {

private:
    vector<Vecteur2D> points;

public:

    Polygone(const string& couleur);
    virtual ~Polygone();

    void add(const Vecteur2D& vecteur);
    Vecteur2D get(int index) const;
    void remove(const Vecteur2D* vecteur);

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Polygone

inline ostream& operator << (ostream & os, const Polygone& polygone) {
    return os << (string)polygone;
}