#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* @brief Exception concernant toutes les erreurs venant des sauvegardes du projet. Hérite de la classe QExceptions
*/
class QExceptionsSauvegarde : public QExceptions {
protected:
	/*
	* @brief Création d'une exception sur les sauvegardes
	* @param code : le numéro de l'exception
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsSauvegarde(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* @brief Exception lancée lorsque le nom d'un fichier donné dépasse les 100 caractères. Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsNomFichierTropLong : public QExceptionsSauvegarde {
public:
	/*
	* @brief Création d'une exception lorsque le fichier est trop long. Le numéro de cette exception est 0
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsNomFichierTropLong(const string& msg) : QExceptionsSauvegarde(0, msg) {};
};

/*
* @brief Exception lancée lorsque qu'on demande de lire une seule forme dans un fichier. Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsLectureSimpleImpossible : public QExceptionsSauvegarde {
public:
	/*
	* @brief Création d'une exception sur la lecture d'une seule forme dans un fichier. Le numéro de cette exception est 1
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsLectureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(1, msg) {};
};

/*
* @brief Exception lancée lorsqu'on demande d'écrire une seule forme dans un fichier. Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsEcritureSimpleImpossible : public QExceptionsSauvegarde {
public:
	/*
	* @brief Création d'une exception sur l'écriture d'une seule forme dans un fichier. Le numéro de cette exception est 
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsEcritureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(2, msg) {};
};

/*
* @brief Exception lancée lorsque le nom de fichier n'a pas été donné. Hérite de la classe QExceptionsSauvegarde
*/
class QExceptionsFichierNonDefini : public QExceptionsSauvegarde {
public:
	/*
	* @brief Création d'une exception lorsque le nom du fichier n'existe pas. Le numéro de cette exception est 3
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsFichierNonDefini(const string& msg) : QExceptionsSauvegarde(3, msg) {};
};