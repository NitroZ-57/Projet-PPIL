#include "Vecteur2D.h"

#include <math.h>

Vecteur2D* Vecteur2D::creerString(char* v) {

    double a, b;
    
    int res = sscanf_s(v, "(%lf, %lf)", &a, &b);

    if (res == 2) {
        return new Vecteur2D(a, b);
    }
    else {
        return nullptr;
    }


}




const Vecteur2D Vecteur2D::creerPolaire(const double& alpha) {
    return Vecteur2D(cos(alpha), sin(alpha));
}

double Vecteur2D::aireTriangle(const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C) {
    Vecteur2D AC = C - A;
    Vecteur2D AB = B - A;

    double d = determinant(AC, AB);
    return 0.5 * abs(d);
}

double Vecteur2D::determinant(const Vecteur2D& A, const Vecteur2D& B) {
    return A.x * B.y - A.y * B.x;
}

bool Vecteur2D::determinantEstPositifOuNul(const Vecteur2D& A, const Vecteur2D& B) {
    return determinant(A, B) >= 0;
}

double Vecteur2D::getNorme(const Vecteur2D& A, const Vecteur2D& B) {
    return A.getNorme() - B.getNorme();
}

double Vecteur2D::getNorme() const {
    return sqrt(x * x + y * y);
}

/*
(12, 89)
(x, y)
*/
Vecteur2D::operator string () const {
    ostringstream os;
    os << "(" << x << ", " << y << ")";
    return os.str();
}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D& v) const {
    return Vecteur2D(this->x + v.x, this->y + v.y);
}

const Vecteur2D Vecteur2D::operator * (const double& a) const {
    return Vecteur2D(this->x * a, this->y * a);
}

const Vecteur2D Vecteur2D::operator - () const {
    return Vecteur2D(-this->x, -this->y);
}

const Vecteur2D Vecteur2D::operator - (const Vecteur2D& v) const {
    return *this + -v;
}

const Vecteur2D Vecteur2D::operator ^ (const Vecteur2D& v) const {
    return Vecteur2D(
        x * v.x - y * v.y,
        x * v.y + y * v.x
    );
}

