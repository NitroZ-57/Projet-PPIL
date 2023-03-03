#pragma once

#include <iostream>
#include <string>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

/*
* @brief Cette classe est une dérivée de la classe forme. Un segment est représenté par deux points (Vecteur2D). Un point d'origine ainsi qu'un point d'arrivée
*/
class Segment : public Forme {

private:
    Vecteur2D segment;

public:

    /**
    * @brief Constructeur de segment
    * @param couleur : la couleur du segment parmi celles disponibles dans la classe Forme
    * @param origine : les coordonnées d'origine du segment
    * @param vecteur : les coordonnées d'arrivée du segment
    */
    Segment(const int& couleur, const Vecteur2D& origine, const Vecteur2D& vecteur);
    virtual ~Segment(){};

    void setSegment(const Vecteur2D& vecteur);
    Vecteur2D getSegment() const;

    /*
    * @brief Cette méthode calcule les coordonnées du coin haut droit correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonnées du coin haut droit correspondant au rectangle englobant le segment
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette méthode calcule les coordonnées du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonnées du coin bas gauche correspondant au rectangle englobant le segment
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette méthode modifie le segment pour le faire passer des coordonnées mondes vers les coordonées écrans
    * @param c : les coordonnées mondes selon lesquelles transformer le segment
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette méthode modifie le segment selon une homothétie
    * @pram o : le centre de l'homothétie
    * @param k : le coefficient d'homothétie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette méthode modifie le segment selon une translation
    * @param v : la translation à effectuer
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette méthode modifie le segment selon une rotation
    * @param o : le centre de la rotation
    * @param a : l'angle de rotation en degré
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette méthode retourne l'aire du segment
    * @return double : l'aire du segment
    */
    virtual double getAire() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurForme);

}; // Segment

inline ostream& operator << (ostream & os, const Segment& segment) {
    return os << (string)segment;
}