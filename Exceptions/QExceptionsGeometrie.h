#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venant de la géométrie du projet
* Hérite de la classe QExceptions
*/
class QExceptionsGeometrie : public QExceptions{
protected:
	/*
	* Création d'une exception sur la géométrie
	* code : le numéro de l'exception 
	* msg  : le message d'erreur de l'exception 
	*/
	QExceptionsGeometrie(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* Exception lancée lorsque un indice est en dehors de la portée du conteneur
* Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsIndiceHorsPortee : public QExceptionsGeometrie{
public:
	/*
	* Création d'une exception sur l'indice en dehors de la portée du conteneur
	* Le numéro de cette exception est 0
	* msg  : le message d'erreur de l'exception 
	*/
	QExceptionsIndiceHorsPortee(const string& msg) : QExceptionsGeometrie(0, msg){};
};

/*
* Exception lancée lorsque une couleur non existante à été donnée
* Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsCouleurInexistance : public QExceptionsGeometrie {
public:
	/*
	* Création d'une exception sur une couleur donnée inexistante
	* Le numéro de cette exception est 1
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsCouleurInexistance(const string& msg) : QExceptionsGeometrie(1, msg) {};
};

/*
* Exception lancée lorsque une Forme va être ajoutée à un groupe alors qu'elle est déjà dans un groupe
* Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsEstDejaDansUnGroupe : public QExceptionsGeometrie {
public:
	QExceptionsEstDejaDansUnGroupe(const string& msg) : QExceptionsGeometrie(2, msg) {};
};

/*
* Exception lancée lorsque le nombre de points est sinsuffisant pour créer un polygone
* Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsNombrePointsInsuffisant : public QExceptionsGeometrie {
public:
	QExceptionsNombrePointsInsuffisant(const string& msg) : QExceptionsGeometrie(3, msg) {};
};

/*
* Exception lancée lorsque le polygone créé n'est pas convexe
* Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsFormeNonConnexe : public QExceptionsGeometrie {
public:
	QExceptionsFormeNonConnexe(const string& msg) : QExceptionsGeometrie(4, msg) {};
};

/*
* Exception lancée lorsque un groupe vide est utilisé 
* Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsGroupeVide : public QExceptionsGeometrie {
public:
	QExceptionsGroupeVide(const string& msg) : QExceptionsGeometrie(5, msg) {};
};