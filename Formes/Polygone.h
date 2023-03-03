#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
class CoordMonde;
using namespace std;

/*
* @brief Cette classe est une dérivée de la classe forme. Un polygone est représenté par un ensemble de vecteur2D (au moins 3).
*/
class Polygone : public Forme {

private:
    vector<Vecteur2D> points;

public:
    /**
    * @brief Constructeur de polygone à partir de 3 points
    * @param couleur : la couleur du polygone parmi celles disponibles dans la classe Forme
    * @param A : les coordonnées du point A du polygone
    * @param B : les coordonnées du point B du polygone
    * @param C : les coordonnées du point C du polygone
    */
    Polygone(const int& couleur, const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C);

    /**
    * @brief Constructeur de polygone à partir d'un ensemble de points
    * @param couleur : la couleur du polygone parmi celles disponibles dans la classe Forme
    * @param points : un vecteur d'au moins 3 points représentant les coordonées des différents points du polygone, le polygone doit être convexe
    */
    Polygone(const int& couleur, const vector<Vecteur2D>& points);
    virtual ~Polygone(){};

    Vecteur2D get(int index) const;

    /*
    * @brief Cette méthode calcule les coordonnées du coin haut droit correspondant au rectangle englobant le polygone
    * @return Vecteur2D : les coordonnées du coin haut droit correspondant au rectangle englobant le polygone
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette méthode calcule les coordonnées du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonnées du coin bas gauche correspondant au rectangle englobant le polygone
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette méthode modifie le polygone pour le faire passer des coordonnées mondes vers les coordonées écrans
    * @param c : les coordonnées mondes selon lesquelles transformer le polygone
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette méthode modifie le polygone selon une homothétie
    * @pram o : le centre de l'homothétie
    * @param k : le coefficient d'homothétie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette méthode modifie le polygone selon une translation
    * @param v : la translation à effectuer
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette méthode modifie le polygone selon une rotation
    * @param o : le centre de la rotation
    * @param a : l'angle de rotation en degré
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette méthode retourne l'aire du polygone
    * @return double : l'aire du polygone
    */
    virtual double getAire() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Polygone

inline ostream& operator << (ostream & os, const Polygone& polygone) {
    return os << (string)polygone;
}