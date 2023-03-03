#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;


/*
* @brief Cette classe sera principalement utilis�e comme un type simple. Il s'agit d'un vecteur dans le plan ou d'un point dans le plan avec deux champs, x et y des r�els. x et y correspodent aux coordon�es du vecteur ou du point. Cette classe permet de faire des transformations et des calculs sur des points ou vecteurs.
*/
class Vecteur2D {
    
public:
    /*
    * @brief Abcisse du Vecteur2D
    */
    double x;

    /*
    * @brief Ordonn�e du Vecteur2D
    */
    double y;

    /*
    * @brief Constructeur d'un Vecteur2D
    * @param x : Abcisse du Vecteur2D
    * @param y : Ordonn�e du Vecteur2D
    */
    explicit Vecteur2D(const double & x = 0, const double & y = 0):x(x),y(y){} 

    /*
    * @brief Constructeur d'un Vecteur2D en faisant la soustraction du vecteur 2 par le vecteur 1
    * @param v1 : Premier Vecteur2D
    * @param v2 : Deuxi�me Vecteur2D
    */
    explicit Vecteur2D(const Vecteur2D& v1, const Vecteur2D& v2) :x(v2.x-v1.x), y(v2.y-v1.y) {}
    virtual ~Vecteur2D(){};

    /*
    * @brief Cr�er un Vecteur2D � partir de coordon�es polaires
    * @param alpha : l'angle du Vecteur2D
    * @return Vecteur2D : le Vecteur2D cr��
    */
    static const Vecteur2D creerPolaire(const double& alpha);

    /*
    * @brief Construit un vecteur � partir de son protocole en chaine de caract�re
    * @return Vecteur2D* nullptr si la forme n'a pas �t� reconnue, le Vecteur2D correspondant aux valeurs sinon
    */
    static Vecteur2D* creerString(char* v);

    /*
    * @brief Calcule l'aire d'un triangle 
    * @param A : les coordonn�es du point A du triangle
    * @param B : les coordonn�es du point B du triangle
    * @param C : les coordonn�es du point C du triangle
    * @return double : l'aire du triangle
    */
    static double aireTriangle(const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C);

    /*
    * @brief Calcule le d�terminant (l'aire entre deux Vecteur2D) 
    * @param A : le premier Vecteur2D
    * @param B : le deuxi�me Vecteur2D
    * @return double : le determinant des deux vecteurs
    */
    static double determinant(const Vecteur2D& A, const Vecteur2D& B);

    /*
    * @brief V�rifie si le determinant (l'aire entre deux Vecteur2D) est positif ou nul
    * @param A : le premier Vecteur2D
    * @param B : le deuxi�me Vecteur2D
    * @return bool : vrai si le determinant est positif ou nul, faux sinon
    */
    static bool determinantEstPositifOuNul(const Vecteur2D& A, const Vecteur2D& B);

    /*
    * @brief Calcule la diff�rence des normes entre deux vecteurs
    * @param A : le premier Vecteur2D
    * @param B : le deuxi�me Vecteur2D
    * @return double : la diff�rence des normes des deux vecteurs
    */
    static double getNorme(const Vecteur2D& A, const Vecteur2D& B);

    /*
    * @brief Calcule la norme du Vecteur2D
    * @return la norme du Vecteur2D
    */
    double getNorme() const;    

    operator string () const;

    /*
    * @brief Op�ration d'addition de deux vecteurs
    */
    const Vecteur2D operator + (const Vecteur2D& v) const;

    /*
    * @brief le vecteur associ� � la r�p�tition d'un vecteur a fois 
    */
    const Vecteur2D operator * (const double& a) const;

    /*
    * @brief Op�rateur de n�gation unaire, retourne l'oppos� du vecteur
    */
    const Vecteur2D operator - () const;

    /*
    * @brief Op�ration de soustraction de deux vecteurs 
    */
    const Vecteur2D operator - (const Vecteur2D& v) const;

    
    /*
    * @brief Produit au sens des nombres complexes
    */
    const Vecteur2D operator ^(const Vecteur2D& v) const;

}; // Vecteur2D


inline ostream& operator << (ostream & os, const Vecteur2D& v) {
    return os << (string)v;
}

/*
* @brief Obtenir le vecteur associ� � la r�p�tition d'un vecteur a fois
*/
inline const Vecteur2D operator * (const double& a, const Vecteur2D& v) {
    return v*a;
}

/*
* @brief Correspond � la multiplication de deux vecteurs entre eux champ par champ
*/
inline Vecteur2D operator * (const Vecteur2D& a, const Vecteur2D& b) {
    return Vecteur2D(a.x * b.x, a.y * b.y);
}

/*
* @brief Correspond � la division des deux champs du premier vecteur par le deuxi�me vecteur
*/
inline Vecteur2D operator / (const Vecteur2D& a, const Vecteur2D& b) {
    return Vecteur2D(a.x / b.x, a.y / b.y);
}

/*
* @brief Retourne la valeur absolue d'un vecteur sur la coordonn�e en x et en y
* @param v le vecteur dont changer les valeurs
* @return le vecteur avec les valeurs positives
*/
inline Vecteur2D abs(const Vecteur2D& v) {
    return Vecteur2D(abs(v.x), abs(v.y));
}
