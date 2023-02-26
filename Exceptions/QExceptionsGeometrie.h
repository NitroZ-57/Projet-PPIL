#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venant de la g�om�trie du projet
* H�rite de la classe QExceptions
*/
class QExceptionsGeometrie : public QExceptions{
protected:
	/*
	* Cr�ation d'une exception sur la g�om�trie
	* code : le num�ro de l'exception 
	* msg  : le message d'erreur de l'exception 
	*/
	QExceptionsGeometrie(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* Exception lanc�e lorsque un indice est en dehors de la port�e du conteneur
* H�rite de la classe QExceptionsGeometrie
*/
class QExceptionsIndiceHorsPortee : public QExceptionsGeometrie{
public:
	/*
	* Cr�ation d'une exception sur l'indice en dehors de la port�e du conteneur
	* Le num�ro de cette exception est 0
	* msg  : le message d'erreur de l'exception 
	*/
	QExceptionsIndiceHorsPortee(const string& msg) : QExceptionsGeometrie(0, msg){};
};

/*
* Exception lanc�e lorsque une couleur non existante � �t� donn�e
* H�rite de la classe QExceptionsGeometrie
*/
class QExceptionsCouleurInexistance : public QExceptionsGeometrie {
public:
	/*
	* Cr�ation d'une exception sur une couleur donn�e inexistante
	* Le num�ro de cette exception est 1
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsCouleurInexistance(const string& msg) : QExceptionsGeometrie(1, msg) {};
};

/*
* Exception lanc�e lorsque une Forme va �tre ajout�e � un groupe alors qu'elle est d�j� dans un groupe
* H�rite de la classe QExceptionsGeometrie
*/
class QExceptionsEstDejaDansUnGroupe : public QExceptionsGeometrie {
public:
	QExceptionsEstDejaDansUnGroupe(const string& msg) : QExceptionsGeometrie(2, msg) {};
};

/*
* Exception lanc�e lorsque le nombre de points est sinsuffisant pour cr�er un polygone
* H�rite de la classe QExceptionsGeometrie
*/
class QExceptionsNombrePointsInsuffisant : public QExceptionsGeometrie {
public:
	QExceptionsNombrePointsInsuffisant(const string& msg) : QExceptionsGeometrie(3, msg) {};
};

/*
* Exception lanc�e lorsque le polygone cr�� n'est pas convexe
* H�rite de la classe QExceptionsGeometrie
*/
class QExceptionsFormeNonConnexe : public QExceptionsGeometrie {
public:
	QExceptionsFormeNonConnexe(const string& msg) : QExceptionsGeometrie(4, msg) {};
};

/*
* Exception lanc�e lorsque un groupe vide est utilis� 
* H�rite de la classe QExceptionsGeometrie
*/
class QExceptionsGroupeVide : public QExceptionsGeometrie {
public:
	QExceptionsGroupeVide(const string& msg) : QExceptionsGeometrie(5, msg) {};
};