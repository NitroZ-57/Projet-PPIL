#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

class Segment : public Forme {

private:
    Vecteur2D segment;

public:

    Segment(const int& couleur, const Vecteur2D& origine, const Vecteur2D& vecteur);
    virtual ~Segment(){};

    void setSegment(const Vecteur2D& vecteur);
    Vecteur2D getSegment() const;

    virtual Vecteur2D getRectangleHD() const;
    virtual Vecteur2D getRectangleBG() const;
    virtual Forme* getTransformation(const CoordMonde& c) const ;
    virtual void homothetie(const Vecteur2D& o, const double& k);
    virtual void translation(const Vecteur2D& v);
    virtual void rotation(const Vecteur2D& o, const double& a);

    virtual double getAire() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurForme);

}; // Segment

inline ostream& operator << (ostream & os, const Segment& segment) {
    return os << (string)segment;
}