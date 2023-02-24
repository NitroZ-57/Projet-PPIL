#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"

class VisiteurDessin;
class CoordMonde;
using namespace std;

class Forme {

private:
    int couleur;
    bool appartientGroupe;
    Vecteur2D origine;

    static const int couleurMax = 5;
    static vector<string> str_coul;

public:
    static const int BLACK = 0;
    static const int BLUE = 1;
    static const int RED = 2;
    static const int GREEN = 3;
    static const int YELLOW = 4;
    static const int CYAN = 5;

    static int getIntCouleur(const char* c);

    Forme(const int& couleur, const Vecteur2D& origine);
    virtual ~Forme(){};

    void setCouleur(const int& couleur);
    void setOrigine(const Vecteur2D& origine);
    void estAjouteGroupe();
    void estRetireGroupe();
    bool estDansUnGroupe() const;
    string getCouleur() const;
    int getIntCouleur() const;
    Vecteur2D getOrigine() const;
    
    virtual Vecteur2D getRectangleHD() const = 0;
    virtual Vecteur2D getRectangleBG() const = 0;
    virtual Forme* getTransformation(const CoordMonde& c) const = 0;
    virtual void homothetie(const Vecteur2D& o, const double& k) = 0;
    virtual void translation(const Vecteur2D& v) = 0;
    virtual void rotation(const Vecteur2D& o, const double& a) = 0;

    virtual double getAire() const = 0;

    virtual operator string () const = 0;

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Forme

inline ostream& operator << (ostream & os, const Forme& forme) {
    return os << (string)forme;
}