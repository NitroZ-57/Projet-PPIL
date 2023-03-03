#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

/*
* @brief Cette classe est une dérivée de la classe forme. Un groupe est composé d'un ensemble de forme et n'a pas de propriétés à proprement parler.
*/
class Groupe : public Forme {

private:
    vector<Forme*> formes;

public:
    /**
    * @brief Constructeur de groupe
    * @param couleur : la couleur du groupe parmi celles disponibles dans la classe Forme
    */
    Groupe(const int& couleur);
    virtual ~Groupe(){};

    Groupe& ajouter(Forme* forme);
    Forme* get(int index) const;
    Forme* retirer(int index);

    /*
    * @brief Cette méthode calcule les coordonnées du coin haut droit correspondant au rectangle englobant le groupe
    * @return Vecteur2D : les coordonnées du coin haut droit correspondant au rectangle englobant le groupe
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette méthode calcule les coordonnées du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonnées du coin bas gauche correspondant au rectangle englobant le groupe
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette méthode modifie le groupe pour le faire passer des coordonnées mondes vers les coordonées écrans
    * @param c : les coordonnées mondes selon lesquelles transformer le groupe
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette méthode modifie le groupe selon une homothétie
    * @pram o : le centre de l'homothétie
    * @param k : le coefficient d'homothétie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette méthode modifie le groupe selon une translation
    * @param v : la translation à effectuer
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette méthode modifie le groupe selon une rotation
    * @param o : le centre de la rotation
    * @param a : l'angle de rotation en degré
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette méthode retourne l'aire du groupe
    * @return double : l'aire du groupe
    */
    virtual double getAire() const;

    /*
    * @brief Cette méthode décompose une chaine de caractère comportant les données d'un groupe en un vecteur de formes du groupe
    * @param chaine : chaine de caractère représentant les formes qui sont après la couleur du groupe sous la forme du protocole
    * @return vector<char*> : un ensemble de forme dans des chaines de caractères différentes
    */
    static vector<char*> parseurGroupe(const char* chaine);

    operator string () const;

    const Groupe& operator += (Forme*& v);

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Groupe

inline ostream& operator << (ostream & os, const Groupe& groupe) {
    return os << (string)groupe;
}