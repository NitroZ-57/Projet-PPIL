#pragma once

#include "../Formes/Vecteur2D.h"
#include "../Formes/Forme.h"
#include "../Formes/Cercle.h"
#include "../Formes/Polygone.h"
#include "../Formes/Groupe.h"
#include "../Formes/Segment.h"

class VisiteurDessin {

public:

    virtual bool dessine(const Forme* forme) const = 0;
    virtual bool dessine(const Segment* segment) const = 0;
    virtual bool dessine(const Cercle* cercle) const = 0;
    virtual bool dessine(const Polygone* polygone) const = 0;
    virtual bool dessine(const Groupe* groupe) const = 0;

}; // VisiteurDessin
