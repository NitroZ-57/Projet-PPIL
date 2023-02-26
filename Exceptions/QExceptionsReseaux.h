#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venantdu réseau du projet
* Hérite de la classe QExceptions
*/
class QExceptionsReseaux : public QExceptions {
public:
	/*
	* Création d'une exception sur le réseaux
	* code : le numéro de l'exception
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsReseaux(const int& code, const string& msg) : QExceptions(code, msg) {}
};



