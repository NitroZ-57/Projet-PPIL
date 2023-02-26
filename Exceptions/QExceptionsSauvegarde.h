#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venant des sauvegardes du projet
* Hérite de la classe QExceptions
*/
class QExceptionsSauvegarde : public QExceptions {
protected:
	/*
	* Création d'une exception sur les sauvegardes
	* code : le numéro de l'exception
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsSauvegarde(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* Exception lancée lorsque le nom d'un fichier donné dépasse les 100 caractères
* Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsNomFichierTropLong : public QExceptionsSauvegarde {
public:
	QExceptionsNomFichierTropLong(const string& msg) : QExceptionsSauvegarde(0, msg) {};
};

/*
* Exception lancée lorsque qu'on demande de lire une seule forme dans un fichier
* Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsLectureSimpleImpossible : public QExceptionsSauvegarde {
public:
	QExceptionsLectureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(1, msg) {};
};

/*
* Exception lancée lorsqu'on demande d'écrire une seule forme dans un fichier
* Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsEcritureSimpleImpossible : public QExceptionsSauvegarde {
public:
	QExceptionsEcritureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(2, msg) {};
};

/*
* Exception lancée lorsque le nom de fichier n'a pas été donné
* Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsFichierNonDefini : public QExceptionsSauvegarde {
public:
	QExceptionsFichierNonDefini(const string& msg) : QExceptionsSauvegarde(3, msg) {};
};