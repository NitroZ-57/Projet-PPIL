#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* @brief Exception concernant toutes les erreurs venant des vistiteurs du projet. Hérite de la classe QExceptions
*/
class QExceptionsVisiteur : public QExceptions {
protected:
	/*
	* @brief Création d'une exception sur les visiteurs
	* @param code : le numéro de l'exception
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsVisiteur(const int& code, const string& msg) : QExceptions(code, msg) {}
};

