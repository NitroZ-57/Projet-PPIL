#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* @brief Exception concernant toutes les erreurs venant des coordonées monde du projet. Hérite de la classe QExceptions
*/
class QExceptionsCoordMonde : public QExceptions {
protected:
	/*
	* @brief Création d'une exception sur les coordonées mondes
	* @param code : le numéro de l'exception 
	* @param msg  : le message d'erreur de l'exception 
	*/
	QExceptionsCoordMonde(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* @brief Exception lancée lorsque le nombre de forme dans un groupe n'est pas correcte. Hérite de la classe QExceptionsCoordMonde
*/
class QExceptionsNombreFormeIncorrect : public QExceptionsCoordMonde {
public:
	/*
	* @brief Création d'une exception sur le nombre de forme incorrect. Le numéro de cette exception est 0
	* @param msg  : le message d'erreur de l'exception 
	*/
	QExceptionsNombreFormeIncorrect(const string& msg) : QExceptionsCoordMonde(0, msg) {};
};
