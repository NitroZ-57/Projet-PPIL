#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Vecteur2D/Vecteur2D.h"
#include "../Forme/Forme.h"

class VisiteurForme;
using namespace std;

class Groupe : public Forme {

private:
    vector<Forme*> formes;

public:

    Groupe(const string& couleur);
    virtual ~Groupe(){};

    void ajouter(Forme* forme);
    Vecteur2D get(int index) const;
    void retirer(const Forme* forme);

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Groupe

inline ostream& operator << (ostream & os, const Groupe& groupe) {
    return os << (string)groupe;
}