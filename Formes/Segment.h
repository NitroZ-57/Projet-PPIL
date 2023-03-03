#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

/*
* @brief Cette classe est une d�riv�e de la classe forme. Un segment est repr�sent� par deux points (Vecteur2D). Un point d'origine ainsi qu'un point d'arriv�e
*/
class Segment : public Forme {

private:
    Vecteur2D segment;

public:

    /**
    * @brief Constructeur de segment
    * @param couleur : la couleur du segment parmi celles disponibles dans la classe Forme
    * @param origine : les coordonn�es d'origine du segment
    * @param vecteur : les coordonn�es d'arriv�e du segment
    */
    Segment(const int& couleur, const Vecteur2D& origine, const Vecteur2D& vecteur);
    virtual ~Segment(){};

    void setSegment(const Vecteur2D& vecteur);
    Vecteur2D getSegment() const;

    /*
    * @brief Cette m�thode calcule les coordonn�es du coin haut droit correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonn�es du coin haut droit correspondant au rectangle englobant le segment
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette m�thode calcule les coordonn�es du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonn�es du coin bas gauche correspondant au rectangle englobant le segment
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette m�thode modifie le segment pour le faire passer des coordonn�es mondes vers les coordon�es �crans
    * @param c : les coordonn�es mondes selon lesquelles transformer le segment
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette m�thode modifie le segment selon une homoth�tie
    * @pram o : le centre de l'homoth�tie
    * @param k : le coefficient d'homoth�tie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette m�thode modifie le segment selon une translation
    * @param v : la translation � effectuer
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette m�thode modifie le segment selon une rotation
    * @param o : le centre de la rotation
    * @param a : l'angle de rotation en degr�
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette m�thode retourne l'aire du segment
    * @return double : l'aire du segment
    */
    virtual double getAire() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurForme);

}; // Segment

inline ostream& operator << (ostream & os, const Segment& segment) {
    return os << (string)segment;
}