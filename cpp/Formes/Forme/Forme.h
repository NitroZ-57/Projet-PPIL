#pragma once

#include <iostream>
#include <string>
#include "../Vecteur2D/Vecteur2D.h"

class VisiteurForme;
using namespace std;

class Forme {

private:
    string couleur;
    bool appartientGroupe;
    Vecteur2D origine;

public:
    static const string BLACK;
    static const string BLUE;
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string CYAN;

    Forme(const string& couleur, const Vecteur2D& origine);
    virtual ~Forme(){};

    void setCouleur(const string& couleur);
    void setOrigine(const Vecteur2D& origine);
    void estAjouteGroupe();
    void estRetireGroupe();
    string getCouleur() const;
    Vecteur2D getOrigine() const;
    bool estDansUnGroupe() const;

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Forme

inline ostream& operator << (ostream & os, const Forme& forme) {
    return os << (string)forme;
}