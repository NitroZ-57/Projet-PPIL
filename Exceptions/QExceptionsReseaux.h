#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venantdu r�seau du projet
* H�rite de la classe QExceptions
*/
class QExceptionsReseaux : public QExceptions {
public:
	/*
	* Cr�ation d'une exception sur le r�seaux
	* code : le num�ro de l'exception
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsReseaux(const int& code, const string& msg) : QExceptions(code, msg) {}
};



