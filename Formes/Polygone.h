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
* @brief Cette classe est une d�riv�e de la classe forme. Un polygone est repr�sent� par un ensemble de vecteur2D (au moins 3).
*/
class Polygone : public Forme {

private:
    vector<Vecteur2D> points;

public:
    /**
    * @brief Constructeur de polygone � partir de 3 points
    * @param couleur : la couleur du polygone parmi celles disponibles dans la classe Forme
    * @param A : les coordonn�es du point A du polygone
    * @param B : les coordonn�es du point B du polygone
    * @param C : les coordonn�es du point C du polygone
    */
    Polygone(const int& couleur, const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C);

    /**
    * @brief Constructeur de polygone � partir d'un ensemble de points
    * @param couleur : la couleur du polygone parmi celles disponibles dans la classe Forme
    * @param points : un vecteur d'au moins 3 points repr�sentant les coordon�es des diff�rents points du polygone, le polygone doit �tre convexe
    */
    Polygone(const int& couleur, const vector<Vecteur2D>& points);
    virtual ~Polygone(){};

    Vecteur2D get(int index) const;

    /*
    * @brief Cette m�thode calcule les coordonn�es du coin haut droit correspondant au rectangle englobant le polygone
    * @return Vecteur2D : les coordonn�es du coin haut droit correspondant au rectangle englobant le polygone
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette m�thode calcule les coordonn�es du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonn�es du coin bas gauche correspondant au rectangle englobant le polygone
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette m�thode modifie le polygone pour le faire passer des coordonn�es mondes vers les coordon�es �crans
    * @param c : les coordonn�es mondes selon lesquelles transformer le polygone
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette m�thode modifie le polygone selon une homoth�tie
    * @pram o : le centre de l'homoth�tie
    * @param k : le coefficient d'homoth�tie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette m�thode modifie le polygone selon une translation
    * @param v : la translation � effectuer
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette m�thode modifie le polygone selon une rotation
    * @param o : le centre de la rotation
    * @param a : l'angle de rotation en degr�
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette m�thode retourne l'aire du polygone
    * @return double : l'aire du polygone
    */
    virtual double getAire() const;

    operator string () const;

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Polygone

inline ostream& operator << (ostream & os, const Polygone& polygone) {
    return os << (string)polygone;
}