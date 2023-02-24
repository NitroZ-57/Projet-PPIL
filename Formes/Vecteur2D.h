#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Vecteur2D {
    
public:
    double x;
    double y;


    explicit Vecteur2D(const double & x = 0, const double & y = 0):x(x),y(y){} 
    explicit Vecteur2D(const Vecteur2D& v1, const Vecteur2D& v2) :x(v2.x-v1.x), y(v2.y-v1.y) {}
    virtual ~Vecteur2D(){};

    static const Vecteur2D creerPolaire(const double& alpha);
    static Vecteur2D* creerString(char* v);
    static double aireTriangle(const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C);
    static double determinant(const Vecteur2D& A, const Vecteur2D& B);
    static bool determinantEstPositifOuNul(const Vecteur2D& A, const Vecteur2D& B);
    static double getNorme(const Vecteur2D& A, const Vecteur2D& B);


    double getNorme() const;    

    operator string () const;
    const Vecteur2D operator + (const Vecteur2D& v) const;
    const Vecteur2D operator * (const double& a) const;
    const Vecteur2D operator - () const;
    const Vecteur2D operator - (const Vecteur2D& v) const;

    

    /**
     * @brief Produit au sens des nombres complexes
     * 
     * @param v 
     * @return const Vecteur2D 
     */
    const Vecteur2D operator ^(const Vecteur2D& v) const;

}; // Vecteur2D

inline ostream& operator << (ostream & os, const Vecteur2D& v) {
    return os << (string)v;
}

inline const Vecteur2D operator * (const double& a, const Vecteur2D& v) {
    return v*a;
}

inline Vecteur2D operator * (const Vecteur2D& a, const Vecteur2D& b) {
    return Vecteur2D(a.x * b.x, a.y * b.y);
}

inline Vecteur2D operator / (const Vecteur2D& a, const Vecteur2D& b) {
    return Vecteur2D(a.x / b.x, a.y / b.y);
}

inline Vecteur2D abs(const Vecteur2D& v) {
    return Vecteur2D(abs(v.x), abs(v.y));
}
