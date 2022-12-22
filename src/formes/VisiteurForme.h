#pragma once

#include "Vecteur2D.h"
#include "Forme.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"

class VisiteurForme {

public:

    virtual Forme visite(const Forme* forme) const = 0;
    virtual Forme visite(const Segment* segment) const = 0;
    virtual Forme visite(const Cercle* cercle) const = 0;
    virtual Forme visite(const Triangle* triangle) const = 0;
    virtual Forme visite(const Polygone* polygone) const = 0;
    virtual Forme visite(const Groupe* groupe) const = 0;

}; // VisiteurForme
