#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* @brief Exception concernant toutes les erreurs venant de la géométrie du projet. Hérite de la classe QExceptions
*/
class QExceptionsGeometrie : public QExceptions{
protected:
	/*
	* @brief Création d'une exception sur la géométrie
	* @param code : le numéro de l'exception 
	* @param msg  : le message d'erreur de l'exception 
	*/
	QExceptionsGeometrie(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* @brief Exception lancée lorsque un indice est en dehors de la portée du conteneur. Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsIndiceHorsPortee : public QExceptionsGeometrie{
public:
	/*
	* @brief Création d'une exception sur l'indice en dehors de la portée du conteneur. Le numéro de cette exception est 0
	* @param msg  : le message d'erreur de l'exception 
	*/
	QExceptionsIndiceHorsPortee(const string& msg) : QExceptionsGeometrie(0, msg){};
};

/*
* @brief Exception lancée lorsque une couleur non existante à été donnée. Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsCouleurInexistance : public QExceptionsGeometrie {
public:
	/*
	* @brief Création d'une exception sur une couleur donnée inexistante. Le numéro de cette exception est 1
	* @parma msg  : le message d'erreur de l'exception
	*/
	QExceptionsCouleurInexistance(const string& msg) : QExceptionsGeometrie(1, msg) {};
};

/*
* @brief Exception lancée lorsque une Forme va être ajoutée à un groupe alors qu'elle est déjà dans un groupe. Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsEstDejaDansUnGroupe : public QExceptionsGeometrie {
public:
	/*
	* @brief Création d'une exception lorsque la forme va être ajoutée à un groupe alors qu'elle appartient déjà à un groupe. Le numéro de cette exception est 2
	* @parma msg  : le message d'erreur de l'exception
	*/
	QExceptionsEstDejaDansUnGroupe(const string& msg) : QExceptionsGeometrie(2, msg) {};
};

/*
* @brief Exception lancée lorsque le nombre de points est insuffisant pour créer un polygone. Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsNombrePointsInsuffisant : public QExceptionsGeometrie {
public:
	/*
	* @brief Création d'une exception lorsque le nombre de points est insuffisant pour créer un polygone. Le numéro de cette exception est 3
	* @parma msg  : le message d'erreur de l'exception
	*/
	QExceptionsNombrePointsInsuffisant(const string& msg) : QExceptionsGeometrie(3, msg) {};
};

/*
* @brief Exception lancée lorsque le polygone créé n'est pas convexe. Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsFormeNonConnexe : public QExceptionsGeometrie {
public:
	/*
	* @brief Création d'une exception lorsque le polygone n'est pas convexe. Le numéro de cette exception est 4
	* @parma msg  : le message d'erreur de l'exception
*/
	QExceptionsFormeNonConnexe(const string& msg) : QExceptionsGeometrie(4, msg) {};
};

/*
* @brief Exception lancée lorsque un groupe vide est utilisé. Hérite de la classe QExceptionsGeometrie
*/
class QExceptionsGroupeVide : public QExceptionsGeometrie {
public:
	/*
	* @brief Création d'une exception lorsque un groupe vide a été utilisé. Le numéro de cette exception est 5
	* @parma msg  : le message d'erreur de l'exception
	*/
	QExceptionsGroupeVide(const string& msg) : QExceptionsGeometrie(5, msg) {};
};