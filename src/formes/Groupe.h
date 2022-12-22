#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

using namespace std;

class Groupe : public Forme {

private:
    vector<Forme> formes;

public:

    Groupe(const string& couleur);
    virtual ~Groupe();

    void add(Forme& forme);
    Vecteur2D get(int index) const;
    void remove(const Forme* forme);

    operator string () const;

}; // Segment

inline ostream& operator << (ostream & os, const Groupe& groupe) {
    return os << (string)groupe;
}