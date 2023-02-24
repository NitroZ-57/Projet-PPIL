#pragma once
#include "VisiteurDessin.h"
#include "../ClientReseaux/WinsocketSocket.h"

class VisiteurDessinJavaAwt : public VisiteurDessin {
private:
    WinsocketSocket* sock;

public:

    VisiteurDessinJavaAwt(const char* addr, short port, Vecteur2D tailleFenetre) { 
        sock = new WinsocketSocket(addr, port); 
        string msg = (string)tailleFenetre;
        const char* cstr = msg.c_str();
        sock->write(cstr, strlen(cstr)); // on envoi les coordonées de la fenetre
    };

    ~VisiteurDessinJavaAwt() { 
        delete sock; 
    }

    virtual bool dessine(const Forme* forme) const;
    virtual bool dessine(const Segment* segment) const;
    virtual bool dessine(const Cercle* cercle) const;
    virtual bool dessine(const Polygone* polygone) const;
    virtual bool dessine(const Groupe* groupe) const;

};