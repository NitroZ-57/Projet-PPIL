#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Vecteur2D/Vecteur2D.h"
#include "../Forme/Forme.h"

class VisiteurForme;
using namespace std;

class Polygone : public Forme {

private:
    vector<Vecteur2D> points;

public:

    Polygone(const string& couleur, const Vecteur2D& origine);
    virtual ~Polygone(){};

    void ajouter(const Vecteur2D& vecteur);
    Vecteur2D get(int index) const;
    void retirer(const Vecteur2D* vecteur);

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Polygone

inline ostream& operator << (ostream & os, const Polygone& polygone) {
    return os << (string)polygone;
}