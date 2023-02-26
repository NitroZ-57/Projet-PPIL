#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venant des coordonées monde du projet
* Hérite de la classe QExceptions
*/
class QExceptionsCoordMonde : public QExceptions {
protected:
	/*
	* Création d'une exception sur les coordonées mondes
	* code : le numéro de l'exception 
	* msg  : le message d'erreur de l'exception 
	*/
	QExceptionsCoordMonde(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* Exception lancée lorsque le nombre de forme dans un groupe n'est pas correcte
* Hérite de la classe QExceptionsCoordMonde
*/
class QExceptionsNombreFormeIncorrect : public QExceptionsCoordMonde {
public:
	/*
	* Création d'une exception sur le nombre de forme incorrect
	* Le numéro de cette exception est 0
	* msg  : le message d'erreur de l'exception 
	*/
	QExceptionsNombreFormeIncorrect(const string& msg) : QExceptionsCoordMonde(0, msg) {};
};
