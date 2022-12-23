#pragma once

#include <iostream>
#include <string>


class VisiteurForme;
using namespace std;

class Forme {

private:
    string couleur;
    bool estDansUnGroupe;

public:
    static const string BLACK;
    static const string BLUE;
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string CYAN;

    Forme(const string& couleur);
    virtual ~Forme();

    void setCouleur(const string& couleur);
    string getCouleur() const;
    bool estDansUnGroupe() const;

    operator string () const;

    const Forme accepte(const VisiteurForme* visiteurForme);

}; // Forme

inline ostream& operator << (ostream & os, const Forme& forme) {
    return os << (string)forme;
}