#pragma once
#include "VisiteurDessin.h"
#include "../ClientReseaux/WinsocketSocket.h"

/*
* @brief Classe qui hérite du visiteur de dessin pour permettre de dessiner avec Awt, une librairie java. Cette classe utilise également des sockets pour communiquer avec le coté Java
*/
class VisiteurDessinJavaAwt : public VisiteurDessin {
private:

    WinsocketSocket* sock;

public:

    /*
    * @brief Création d'un visiteur de dessin en utilisant Awt en Java
    * @param addr : l'adresse à laquelle se connecter
    * @param port : le port sur lequel se connecter 
    * @param tailleFenetre :  la taille de la fenetre à forcer avec en x la hauteur et en y la largeur de la fenetre
    */
    VisiteurDessinJavaAwt(const char* addr, short port, Vecteur2D tailleFenetre) { 
        sock = new WinsocketSocket(addr, port); 
        string msg = (string)tailleFenetre;
        const char* cstr = msg.c_str();
        sock->write(cstr, strlen(cstr)); // on envoi les coordonées de la fenetre
    };

    ~VisiteurDessinJavaAwt() { 
        delete sock; 
    }

    /*
    * @brief Méthode permettant de dessiner une forme lambda avec Awt
    * @param forme : la Forme à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Forme* forme) const;

    /*
    * @brief Méthode permettant de dessiner un segment avec Awt
    * @param segment : le Segment à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Segment* segment) const;

    /*
    * @brief Méthode permettant de dessiner un cercle avec Awt
    * @param cercle : le Cercle à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Cercle* cercle) const;

    /*
    * @brief Méthode permettant de dessiner un polygone avec Awt
    * @param polygone :le Polygone à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Polygone* polygone) const;

    /*
    * @brief Méthode permettant de dessiner un groupe avec Awt
    * @param groupe : le Groupe à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const Groupe* groupe) const;

    /*
    * @brief Méthode permettant de dessiner un ensemble de formes avec Awt
    * @param vector<Forme*> : l'ensemble de Forme à dessiner
    * @return vrai si le dessin à réussi, faux sinon
    */
    virtual bool dessine(const vector<Forme*>& formes) const;

    /*
    * @brief Méthode permettant de dire au serveur que l'envoi est fini
    * @return vrai si l'envoi à réussi, faux sinon
    */
    virtual bool finDessin() const;

};