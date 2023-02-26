#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venant des vistiteurs du projet
* Hérite de la classe QExceptions
*/
class QExceptionsVisiteur : public QExceptions {
protected:
	/*
	* Création d'une exception sur les visiteurs
	* code : le numéro de l'exception
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsVisiteur(const int& code, const string& msg) : QExceptions(code, msg) {}
};

