#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;


/*
* @brief Exception concernant toutes les erreurs venant des sauvegardes du projet. H�rite de la classe QExceptions
*/
class QExceptionsSauvegarde : public QExceptions {
protected:
	/*
	* @brief Cr�ation d'une exception sur les sauvegardes
	* @param code : le num�ro de l'exception
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsSauvegarde(const int& code, const string& msg) : QExceptions(code, msg) {}
};

/*
* @brief Exception lanc�e lorsque le nom d'un fichier donn� d�passe les 100 caract�res. H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsNomFichierTropLong : public QExceptionsSauvegarde {
public:
	/*
	* @brief Cr�ation d'une exception lorsque le fichier est trop long. Le num�ro de cette exception est 0
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsNomFichierTropLong(const string& msg) : QExceptionsSauvegarde(0, msg) {};
};

/*
* @brief Exception lanc�e lorsque qu'on demande de lire une seule forme dans un fichier. H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsLectureSimpleImpossible : public QExceptionsSauvegarde {
public:
	/*
	* @brief Cr�ation d'une exception sur la lecture d'une seule forme dans un fichier. Le num�ro de cette exception est 1
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsLectureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(1, msg) {};
};

/*
* @brief Exception lanc�e lorsqu'on demande d'�crire une seule forme dans un fichier. H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsEcritureSimpleImpossible : public QExceptionsSauvegarde {
public:
	/*
	* @brief Cr�ation d'une exception sur l'�criture d'une seule forme dans un fichier. Le num�ro de cette exception est 
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsEcritureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(2, msg) {};
};

/*
* @brief Exception lanc�e lorsque le nom de fichier n'a pas �t� donn�. H�rite de la classe QExceptionsSauvegarde
*/
class QExceptionsFichierNonDefini : public QExceptionsSauvegarde {
public:
	/*
	* @brief Cr�ation d'une exception lorsque le nom du fichier n'existe pas. Le num�ro de cette exception est 3
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsFichierNonDefini(const string& msg) : QExceptionsSauvegarde(3, msg) {};
};