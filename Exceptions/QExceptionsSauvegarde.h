#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* Exception concernant toutes les erreurs venant des sauvegardes du projet
* H�rite de la classe QExceptions
*/
class QExceptionsSauvegarde : public QExceptions {
protected:
	/*
	* Cr�ation d'une exception sur les sauvegardes
	* code : le num�ro de l'exception
	* msg  : le message d'erreur de l'exception
	*/
	QExceptionsSauvegarde(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* Exception lanc�e lorsque le nom d'un fichier donn� d�passe les 100 caract�res
* H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsNomFichierTropLong : public QExceptionsSauvegarde {
public:
	QExceptionsNomFichierTropLong(const string& msg) : QExceptionsSauvegarde(0, msg) {};
};

/*
* Exception lanc�e lorsque qu'on demande de lire une seule forme dans un fichier
* H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsLectureSimpleImpossible : public QExceptionsSauvegarde {
public:
	QExceptionsLectureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(1, msg) {};
};

/*
* Exception lanc�e lorsqu'on demande d'�crire une seule forme dans un fichier
* H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsEcritureSimpleImpossible : public QExceptionsSauvegarde {
public:
	QExceptionsEcritureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(2, msg) {};
};

/*
* Exception lanc�e lorsque le nom de fichier n'a pas �t� donn�
* H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsFichierNonDefini : public QExceptionsSauvegarde {
public:
	QExceptionsFichierNonDefini(const string& msg) : QExceptionsSauvegarde(3, msg) {};
};