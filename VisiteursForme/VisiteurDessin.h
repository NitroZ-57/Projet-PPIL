#pragma once

#include "../Formes/Vecteur2D.h"
#include "../Formes/Forme.h"
#include "../Formes/Cercle.h"
#include "../Formes/Polygone.h"
#include "../Formes/Groupe.h"
#include "../Formes/Segment.h"

/*
* @brief Classe de visiteur sur le dessin pour permettre de dessiner de diff�rente mani�re possible. A d�river pour choisir l'interface avec laquelle afficher les formes
*/
class VisiteurDessin {

public:
    /*
    * @brief M�thode permettant de dessiner une forme lambda 
    * @param forme : la Forme � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Forme* forme) const = 0;

    /*
    * @brief M�thode abstraite permettant de dessiner un segment 
    * @param segment : le Segment � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Segment* segment) const = 0;

    /*
    * @brief M�thode permettant de dessiner un cercle 
    * @param cercle : le Cercle � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Cercle* cercle) const = 0;

    /*
    * @brief M�thode permettant de dessiner un polygone
    * @param polygone :le Polygone � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Polygone* polygone) const = 0;

    /*
    * @brief M�thode permettant de dessiner un groupe 
    * @param groupe : le Groupe � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Groupe* groupe) const = 0;

    /*
    * @brief M�thode permettant de dessiner un ensemble de formes
    * @param vector<Forme*> : l'ensemble de Forme � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const vector<Forme*>& formes) const = 0;

}; // VisiteurDessin
