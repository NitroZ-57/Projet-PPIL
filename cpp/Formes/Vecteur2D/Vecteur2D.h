#pragma once
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Vecteur2D {
    
public:
    double x;
    double y;

    explicit Vecteur2D(const double & x = 0, const double & y = 0):x(x),y(y){} 
    virtual ~Vecteur2D(){};

    operator string () const {
        ostringstream os;
        os << "(" << x << "," << y << ")";
        return os.str();
    }

    /*
    créé un vecteur (cos alpha, sin alpha)
    static <===> this n'existe pas
    */
    static const Vecteur2D creerPolaire(const double& alpha) {
        return Vecteur2D(cos(alpha), sin(alpha));
    }


    const Vecteur2D operator + (const Vecteur2D& v) const {
        return Vecteur2D(this->x+v.x, this->y+v.y);
    } 

    const Vecteur2D operator * (const double& a) const {
        return Vecteur2D(this->x*a, this->y*a);
    }

    const Vecteur2D operator - () const {
        return Vecteur2D(-this->x , -this->y);
    } 

    const Vecteur2D operator - (const Vecteur2D &v) const {
        return *this + -v;
    }

    /**
     * @brief Produit au sens des nombres complexes
     * 
     * @param v 
     * @return const Vecteur2D 
     */
    const Vecteur2D operator ^(const Vecteur2D &v) const {
        return Vecteur2D(
                            x*v.x - y*v.y, 
                            x*v.y + y*v.x
                        );
    }

}; // Vecteur2D

inline ostream& operator << (ostream & os, const Vecteur2D& v) {
    return os << (string)v;
}

inline const Vecteur2D operator * (const double& a, const Vecteur2D& v) {
    return v*a;
}


