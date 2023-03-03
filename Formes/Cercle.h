#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

/*
* @brief Cette classe est une d�riv�e de la classe forme. Un cercle est repr�sent� par deux vecteurs (Vecteur2D). Un point d'origine ainsi que le vecteur associ� � son rayon.
*/
class Cercle : public Forme {

private:
    Vecteur2D rayon;

public:
    /**
    * @brief Constructeur de cercle
    * @param couleur : la couleur du cercle parmi celles disponibles dans la classe Forme
    * @param origine : les coordonn�es d'origine du cercle
    * @param rayon : vecteur du rayon du cercle
    */
    Cercle(const int& couleur, const Vecteur2D& origine, const Vecteur2D& rayon);
    virtual ~Cercle(){};

    void setRayon(const Vecteur2D& rayon);
    Vecteur2D getRayon() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurForme);

    /*
    * @brief Cette m�thode calcule les coordonn�es du coin haut droit correspondant au rectangle englobant le cercle
    * @return Vecteur2D : les coordonn�es du coin haut droit correspondant au rectangle englobant le cercle
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette m�thode calcule les coordonn�es du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonn�es du coin bas gauche correspondant au rectangle englobant le cercle
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette m�thode modifie le cercle pour le faire passer des coordonn�es mondes vers les coordon�es �crans
    * @param c : les coordonn�es mondes selon lesquelles transformer le cercle
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette m�thode modifie le cercle selon une homoth�tie
    * @pram o : le centre de l'homoth�tie
    * @param k : le coefficient d'homoth�tie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette m�thode modifie le cercle selon une translation 
    * @param v : la translation � effectuer 
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette m�thode modifie le cercle selon une rotation 
    * @param o : le centre de la rotation 
    * @param a : l'angle de rotation en degr�
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette m�thode retourne l'aire du cercle
    * @return double : l'aire du cercle
    */
    virtual double getAire() const;


}; // Cercle

inline ostream& operator << (ostream & os, const Cercle& cercle) {
    return os << (string)cercle;
}