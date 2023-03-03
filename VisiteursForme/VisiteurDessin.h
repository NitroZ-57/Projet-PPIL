#pragma once

#include "../Formes/Vecteur2D.h"
#include "../Formes/Forme.h"
#include "../Formes/Cercle.h"
#include "../Formes/Polygone.h"
#include "../Formes/Groupe.h"
#include "../Formes/Segment.h"

/*
* @brief Classe de visiteur sur le dessin pour permettre de dessiner de différente manière possible. A dériver pour choisir l'interface avec laquelle afficher les formes
*/
class VisiteurDessin {

public:
    /*
    * @brief Méthode permettant de dessiner une forme lambda 
    * @param forme : la Forme à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Forme* forme) const = 0;

    /*
    * @brief Méthode abstraite permettant de dessiner un segment 
    * @param segment : le Segment à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Segment* segment) const = 0;

    /*
    * @brief Méthode permettant de dessiner un cercle 
    * @param cercle : le Cercle à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Cercle* cercle) const = 0;

    /*
    * @brief Méthode permettant de dessiner un polygone
    * @param polygone :le Polygone à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Polygone* polygone) const = 0;

    /*
    * @brief Méthode permettant de dessiner un groupe 
    * @param groupe : le Groupe à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Groupe* groupe) const = 0;

    /*
    * @brief Méthode permettant de dessiner un ensemble de formes
    * @param vector<Forme*> : l'ensemble de Forme à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const vector<Forme*>& formes) const = 0;

}; // VisiteurDessin
