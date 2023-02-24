#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

class Groupe : public Forme {

private:
    vector<Forme*> formes;

public:

    Groupe(const int& couleur);
    virtual ~Groupe(){};

    Groupe& ajouter(Forme* forme);
    Forme* get(int index) const;
    Forme* retirer(int index);

    virtual Vecteur2D getRectangleHD() const;
    virtual Vecteur2D getRectangleBG() const;
    virtual Forme* getTransformation(const CoordMonde& c) const;
    virtual void homothetie(const Vecteur2D& o, const double& k);
    virtual void translation(const Vecteur2D& v);
    virtual void rotation(const Vecteur2D& o, const double& a);

    static vector<char*> parseurGroupe(const char* chaine);

    virtual double getAire() const;

    operator string () const;

    const Groupe& operator += (Forme*& v);

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Groupe

inline ostream& operator << (ostream & os, const Groupe& groupe) {
    return os << (string)groupe;
}