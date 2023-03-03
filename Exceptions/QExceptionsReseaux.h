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


/*
* @brief Exception lanc�e lorsque la winsock n'a pass r�ussi le WSAStartup. H�rite de la classe QExceptionsReseaux
*/
class QExceptionsStartUp : public QExceptionsReseaux {
public:
	/*
	* @brief Cr�ation d'une exception lorsque l'initialisation de la winsock a �chou�. Le num�ro de cette exception est 0
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsStartUp(const string& msg) : QExceptionsReseaux(0, msg) {};
};

/*
* @brief Exception lanc�e lorsque le socket n'a pas r�ussi a etre initialis�. H�rite de la classe QExceptionsReseaux
*/
class QExceptionsSocketInvalide : public QExceptionsReseaux {
public:
	/*
	* @brief Cr�ation d'une exception lorsque l'initialisation du socket a �chou�. Le num�ro de cette exception est 1
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsSocketInvalide(const string& msg) : QExceptionsReseaux(1, msg) {};
};

/*
* @brief Exception lanc�e lorsque le socket n'a pas r�ussi l'execution de la fonction InetPton. H�rite de la classe QExceptionsReseaux
*/
class QExceptionsInetPton : public QExceptionsReseaux {
public:
	/*
	* @brief Cr�ation d'une exception lorsque l'appel de InetPton n'a pas fonctionn�. Le num�ro de cette exception est 2
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsInetPton(const string& msg) : QExceptionsReseaux(2, msg) {};
};

/*
* @brief Exception lanc�e lorsque le socket n'a pas r�ussi � se connecter au serveur. H�rite de la classe QExceptionsReseaux
*/
class QExceptionsSocketConnection : public QExceptionsReseaux {
public:
	/*
	* @brief Cr�ation d'une exception lorsque la connexion du socket au serveur n'a pas fonctionn�. Le num�ro de cette exception est 3
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsSocketConnection(const string& msg) : QExceptionsReseaux(3, msg) {};
};

/*
* @brief Exception lanc�e lorsque le socket ne s'est pas ferm� correctement. H�rite de la classe QExceptionsReseaux
*/
class QExceptionsFermetureSocket : public QExceptionsReseaux {
public:
	/*
	* @brief Cr�ation d'une exception lorsque la deconection du socket � �chou�. Le num�ro de cette exception est 4
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsFermetureSocket(const string& msg) : QExceptionsReseaux(4, msg) {};
};

/*
* @brief Exception lanc�e lorsque l'�criture dans le socket � �chou�. H�rite de la classe QExceptionsReseaux
*/
class QExceptionsEcritureSocket : public QExceptionsReseaux {
public:
	/*
	* @brief Cr�ation d'une exception lorsque l'�criture dans le socket a �chou�. Le num�ro de cette exception est 5
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsEcritureSocket(const string& msg) : QExceptionsReseaux(5, msg) {};
};

/*
* @brief Exception lanc�e lorsque la l�cture dans le socket � �chou�. H�rite de la classe QExceptionsReseaux
*/
class QExceptionsLectureSocket : public QExceptionsReseaux {
public:
	/*
	* @brief Cr�ation d'une exception lorsque la lecture dans le socket a �chou�.  Le num�ro de cette exception est 5
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsLectureSocket(const string& msg) : QExceptionsReseaux(5, msg) {};
};
