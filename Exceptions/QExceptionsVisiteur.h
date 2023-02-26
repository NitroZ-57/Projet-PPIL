#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venant des vistiteurs du projet
* H�rite de la classe QExceptions
*/
class QExceptionsVisiteur : public QExceptions {
protected:
	/*
	* Cr�ation d'une exception sur les visiteurs
	* code : le num�ro de l'exception
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsVisiteur(const int& code, const string& msg) : QExceptions(code, msg) {}
};

