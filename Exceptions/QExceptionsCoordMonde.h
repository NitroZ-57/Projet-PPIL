#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* @brief Exception concernant toutes les erreurs venant des coordon�es monde du projet. H�rite de la classe QExceptions
*/
class QExceptionsCoordMonde : public QExceptions {
protected:
	/*
	* @brief Cr�ation d'une exception sur les coordon�es mondes
	* @param code : le num�ro de l'exception 
	* @param msg  : le message d'erreur de l'exception 
	*/
	QExceptionsCoordMonde(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* @brief Exception lanc�e lorsque le nombre de forme dans un groupe n'est pas correcte. H�rite de la classe QExceptionsCoordMonde
*/
class QExceptionsNombreFormeIncorrect : public QExceptionsCoordMonde {
public:
	/*
	* @brief Cr�ation d'une exception sur le nombre de forme incorrect. Le num�ro de cette exception est 0
	* @param msg  : le message d'erreur de l'exception 
	*/
	QExceptionsNombreFormeIncorrect(const string& msg) : QExceptionsCoordMonde(0, msg) {};
};
