#pragma once
#include "VisiteurDessin.h"
#include "../ClientReseaux/WinsocketSocket.h"

/*
* @brief Classe qui h�rite du visiteur de dessin pour permettre de dessiner avec Awt, une librairie java. Cette classe utilise �galement des sockets pour communiquer avec le cot� Java
*/
class VisiteurDessinJavaAwt : public VisiteurDessin {
private:

    WinsocketSocket* sock;

public:

    /*
    * @brief Cr�ation d'un visiteur de dessin en utilisant Awt en Java
    * @param addr : l'adresse � laquelle se connecter
    * @param port : le port sur lequel se connecter 
    * @param tailleFenetre :  la taille de la fenetre � forcer avec en x la hauteur et en y la largeur de la fenetre
    */
    VisiteurDessinJavaAwt(const char* addr, short port, Vecteur2D tailleFenetre) { 
        sock = new WinsocketSocket(addr, port); 
        string msg = (string)tailleFenetre;
        const char* cstr = msg.c_str();
        sock->write(cstr, strlen(cstr)); // on envoi les coordon�es de la fenetre
    };

    ~VisiteurDessinJavaAwt() { 
        delete sock; 
    }

    /*
    * @brief M�thode permettant de dessiner une forme lambda avec Awt
    * @param forme : la Forme � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Forme* forme) const;

    /*
    * @brief M�thode permettant de dessiner un segment avec Awt
    * @param segment : le Segment � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Segment* segment) const;

    /*
    * @brief M�thode permettant de dessiner un cercle avec Awt
    * @param cercle : le Cercle � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Cercle* cercle) const;

    /*
    * @brief M�thode permettant de dessiner un polygone avec Awt
    * @param polygone :le Polygone � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Polygone* polygone) const;

    /*
    * @brief M�thode permettant de dessiner un groupe avec Awt
    * @param groupe : le Groupe � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const Groupe* groupe) const;

    /*
    * @brief M�thode permettant de dessiner un ensemble de formes avec Awt
    * @param vector<Forme*> : l'ensemble de Forme � dessiner
    * @return vrai si le dessin � r�ussi, faux sinon
    */
    virtual bool dessine(const vector<Forme*>& formes) const;

    /*
    * @brief M�thode permettant de dire au serveur que l'envoi est fini
    * @return vrai si l'envoi � r�ussi, faux sinon
    */
    virtual bool finDessin() const;

};