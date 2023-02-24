#include <sstream>
#include "Groupe.h"
#include "../VisiteursForme/VisiteurDessin.h"
#include "../Exceptions/QExceptionsGeometrie.h"
#include "../CoordMonde/CoordMonde.h"


Groupe::Groupe(const int& couleur) : Forme(couleur, Vecteur2D(0, 0))
{
}

Groupe& Groupe::ajouter(Forme* forme)
{
    forme->estAjouteGroupe();
    formes.push_back(forme);
    return *this;
}

Forme* Groupe::get(int index) const
{
    if (index < 0 || index > formes.size())
        throw new QExceptionsIndiceHorsPortee("Get impossible, indice en dehors de la portee");
    return formes[index];

}

Forme* Groupe::retirer(int index)
{
    if (index < 0 || index > formes.size())
        throw new QExceptionsIndiceHorsPortee("Retirer impossible, indice en dehors de la portee");
    vector<Forme*>::const_iterator it = formes.begin();
    it += index;
    formes.erase(it);
    get(index)->estRetireGroupe();
    return get(index);
}

Vecteur2D Groupe::getRectangleBG() const {
    if (formes.size() == 0)
        throw new QExceptionsGroupeVide("Rectange BG impossible groupe vide");
    Vecteur2D min = formes[0]->getRectangleBG();
    for (vector<Forme*>::const_iterator it = formes.begin() + 1; it != formes.end(); it++) {
        Vecteur2D v = (*it)->getRectangleBG();
        if (v.x < min.x)
            min.x = v.x;
        if (v.y < min.y)
            min.y = v.y;
    }
    return min;
}
Vecteur2D Groupe::getRectangleHD() const {
    if (formes.size() == 0)
        throw new QExceptionsGroupeVide("Rectange HD impossible groupe vide");
    Vecteur2D max = formes[0]->getRectangleHD();
    for (vector<Forme*>::const_iterator it = formes.begin() + 1; it != formes.end(); it++) {
        Vecteur2D v = (*it)->getRectangleHD();
        if (v.x > max.x)
            max.x = v.x;
        if (v.y > max.y)
            max.y = v.y;
    }
    return max;
}

Forme* Groupe::getTransformation(const CoordMonde& c) const {
    Groupe *g = new Groupe(getIntCouleur());
    for (vector<Forme*>::const_iterator it = formes.begin(); it != formes.end(); it++) {
        g->ajouter((*it)->getTransformation(c));
    }
    return (Forme*)g;
}

void Groupe::homothetie(const Vecteur2D& o, const double& k) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->homothetie(o, k);
    }
}
void Groupe::translation(const Vecteur2D& v) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->translation(v);
    }
}
void Groupe::rotation(const Vecteur2D& o, const double& a) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->rotation(o, a);
    }
}


vector<char*> Groupe::parseurGroupe(const char* chaine) {
    char* deb = _strdup(chaine);
    vector<char*> v;
    int i = 0;
    int ouvert = 0;
    int debutChaine = 0;
    char* temp;

    while (deb[i] != '\0') {
        if (deb[i] == '[') {
            ouvert++;
        }
        else if (deb[i] == ']') {
            if (ouvert == 1) {

                temp = deb + debutChaine;
                
                deb[i + 2] = '\0';
                v.push_back(_strdup(temp));

                deb[i + 2] = ' ';
                debutChaine = i+3;
                i+=3;
            }
            
             ouvert--;
            
        }
        i++;


    }
    delete deb;
    return v;

}

double Groupe::getAire() const {
    double aire = 0;
    for (int i = 0; i < formes.size(); i++) {
        aire += formes[i]->getAire();
    }
    return aire;
}

/*
groupe[couleur; forme; forme; forme; ]; 
*/
Groupe::operator string() const
{
    ostringstream o;
    o << "groupe[" << getCouleur() << "; ";
    for (vector<Forme*>::const_iterator it = formes.begin(); it != formes.end(); it++) {
        o << (string)(** it);
    }
    o << "]; ";
    return o.str();
}

const Groupe& Groupe::operator += (Forme*& v) {
    this->ajouter(v);
    return *this;
}

bool Groupe::accepte(const VisiteurDessin* visiteurDessin)
{
    return visiteurDessin->dessine(this);
}
