#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Vecteur2D.h"
#include "Forme.h"

class VisiteurDessin;
using namespace std;

/*
* @brief Cette classe est une d�riv�e de la classe forme. Un groupe est compos� d'un ensemble de forme et n'a pas de propri�t�s � proprement parler.
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
    * @brief Cette m�thode calcule les coordonn�es du coin haut droit correspondant au rectangle englobant le groupe
    * @return Vecteur2D : les coordonn�es du coin haut droit correspondant au rectangle englobant le groupe
    */
    virtual Vecteur2D getRectangleHD() const;

    /*
    * Cette m�thode calcule les coordonn�es du coin bas gauche correspondant au rectangle englobant le segment
    * @return Vecteur2D : les coordonn�es du coin bas gauche correspondant au rectangle englobant le groupe
    */
    virtual Vecteur2D getRectangleBG() const;

    /*
    * @brief Cette m�thode modifie le groupe pour le faire passer des coordonn�es mondes vers les coordon�es �crans
    * @param c : les coordonn�es mondes selon lesquelles transformer le groupe
    */
    virtual void getTransformation(const CoordMonde& c);

    /*
    * @brief Cette m�thode modifie le groupe selon une homoth�tie
    * @pram o : le centre de l'homoth�tie
    * @param k : le coefficient d'homoth�tie
    */
    virtual void homothetie(const Vecteur2D& o, const double& k);

    /*
    * @brief Cette m�thode modifie le groupe selon une translation
    * @param v : la translation � effectuer
    */
    virtual void translation(const Vecteur2D& v);

    /*
    * @brief Cette m�thode modifie le groupe selon une rotation
    * @param o : le centre de la rotation
    * @param a : l'angle de rotation en degr�
    */
    virtual void rotation(const Vecteur2D& o, const double& a);

    /*
    * @brief Cette m�thode retourne l'aire du groupe
    * @return double : l'aire du groupe
    */
    virtual double getAire() const;

    /*
    * @brief Cette m�thode d�compose une chaine de caract�re comportant les donn�es d'un groupe en un vecteur de formes du groupe
    * @param chaine : chaine de caract�re repr�sentant les formes qui sont apr�s la couleur du groupe sous la forme du protocole
    * @return vector<char*> : un ensemble de forme dans des chaines de caract�res diff�rentes
    */
    static vector<char*> parseurGroupe(const char* chaine);

    operator string () const;

    const Groupe& operator += (Forme*& v);

    bool accepte(const VisiteurDessin* visiteurDessin);

}; // Groupe

inline ostream& operator << (ostream & os, const Groupe& groupe) {
    return os << (string)groupe;
}