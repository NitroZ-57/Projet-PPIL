#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

/*
* @brief Cette classe est une dérivée de la classe forme. Un cercle est représenté par deux vecteurs (Vecteur2D). Un point d'origine ainsi que le vecteur associé à son rayon.
*/
class Cercle : public Forme {

private:
    Vecteur2D rayon;

public:
    /**
    * @brief Constructeur de cercle
    * @param couleur : la couleur du cercle parmi celles disponibles dans la classe Forme
    * @param origine : les coordonnées d'origine du cercle
    * @param rayon : vecteur du rayon du cercle
    */
    Cercle(const int& couleur, const Vecteur2D& origine, const Vecteur2D& rayon);
    virtual ~Cercle(){};

    void setRayon(const Vecteur2D& rayon);
    Vecteur2D getRayon() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurForme);

    /*
    * @brief Cette méthode calcule les coordonnées du coin haut droit correspondant au rectangle englobant le cercle
    * @return Vecteur2D : les coordonnées du coin haut droit correspondant au rectangle englobant le cercle
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette méthode calcule les coordonnées du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonnées du coin bas gauche correspondant au rectangle englobant le cercle
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette méthode modifie le cercle pour le faire passer des coordonnées mondes vers les coordonées écrans
    * @param c : les coordonnées mondes selon lesquelles transformer le cercle
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette méthode modifie le cercle selon une homothétie
    * @pram o : le centre de l'homothétie
    * @param k : le coefficient d'homothétie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette méthode modifie le cercle selon une translation 
    * @param v : la translation à effectuer 
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette méthode modifie le cercle selon une rotation 
    * @param o : le centre de la rotation 
    * @param a : l'angle de rotation en degré
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette méthode retourne l'aire du cercle
    * @return double : l'aire du cercle
    */
    virtual double getAire() const;


}; // Cercle

inline ostream& operator << (ostream & os, const Cercle& cercle) {
    return os << (string)cercle;
}