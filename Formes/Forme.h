#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"

class VisiteurDessin;
class CoordMonde;
using namespace std;

/*
* @brief Cette classe abstraite sert � repr�senter une forme quelconque et � faire des calculs et tranformations sur cette forme. Toute forme concr�te d�rive de cette classe.
*/
class Forme {

private:
    int couleur;
    bool appartientGroupe;
    Vecteur2D origine;


    static const int couleurMax = 5;
    static vector<string> str_coul;

public:
    /*
    * Couleur noire pour une forme
    */
    static const int BLACK = 0;

    /*
    * Couleur bleue pour une forme
    */
    static const int BLUE = 1;

    /*
    * Couleur rouge pour une forme
    */
    static const int RED = 2;

    /*
    * Couleur verte pour une forme
    */
    static const int GREEN = 3;

    /*
    * Couleur jaune pour une forme
    */
    static const int YELLOW = 4;

    /*
    * Couleur cyan pour une forme
    */
    static const int CYAN = 5;

    /*
    * Retourne la valeur num�rique d'une couleur selon son format textuel
    */
    static int getIntCouleur(const char* c);

    /**
    * @brief Constructeur de forme
    * @param couleur : la couleur du forme parmi celles disponibles dans la classe Forme
    * @param origine : les coordonn�es d'origine du forme
    * @param rayon : vecteur du rayon du forme
    */
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

    /*
    * @brief Cette m�thode abstraite calcule les coordonn�es du coin haut droit correspondant au rectangle englobant la forme
    * @return Vecteur2D : les coordonn�es du coin haut droit correspondant au rectangle englobant le forme
    */
    virtual Vecteur2D getRectangleHD() const = 0;

    /*
    * Cette m�thode calcule les coordonn�es du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonn�es du coin bas gauche correspondant au rectangle englobant le forme
    */
    virtual Vecteur2D getRectangleBG() const = 0;

    /*
    * @brief Cette m�thode modifie le forme pour le faire passer des coordonn�es mondes vers les coordon�es �crans
    * @param c : les coordonn�es mondes selon lesquelles transformer le forme
    */
    virtual void getTransformation(const CoordMonde& c) = 0;

    /*
    * @brief Cette m�thode modifie le forme selon une homoth�tie
    * @pram o : le centre de l'homoth�tie
    * @param k : le coefficient d'homoth�tie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k) = 0;

    /*
    * @brief Cette m�thode modifie le forme selon une translation
    * @param v : la translation � effectuer
    */
    virtual void translation(const Vecteur2D& v) = 0;

    /*
    * @brief Cette m�thode modifie le forme selon une rotation
    * @param o : le centre de la rotation
    * @param a : l'angle de rotation en degr�
    */
    virtual void rotation(const Vecteur2D& o, const double& a) = 0;

    /*
    * @brief Cette m�thode retourne l'aire du forme
    * @return double : l'aire du forme
    */
    virtual double getAire() const = 0;

    virtual operator string () const = 0;

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Forme

inline ostream& operator << (ostream & os, const Forme& forme) {
    return os << (string)forme;
}