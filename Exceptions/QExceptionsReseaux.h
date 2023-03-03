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


/*
* @brief Exception lancée lorsque la winsock n'a pass réussi le WSAStartup. Hérite de la classe QExceptionsReseaux
*/
class QExceptionsStartUp : public QExceptionsReseaux {
public:
	/*
	* @brief Création d'une exception lorsque l'initialisation de la winsock a échoué. Le numéro de cette exception est 0
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsStartUp(const string& msg) : QExceptionsReseaux(0, msg) {};
};

/*
* @brief Exception lancée lorsque le socket n'a pas réussi a etre initialisé. Hérite de la classe QExceptionsReseaux
*/
class QExceptionsSocketInvalide : public QExceptionsReseaux {
public:
	/*
	* @brief Création d'une exception lorsque l'initialisation du socket a échoué. Le numéro de cette exception est 1
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsSocketInvalide(const string& msg) : QExceptionsReseaux(1, msg) {};
};

/*
* @brief Exception lancée lorsque le socket n'a pas réussi l'execution de la fonction InetPton. Hérite de la classe QExceptionsReseaux
*/
class QExceptionsInetPton : public QExceptionsReseaux {
public:
	/*
	* @brief Création d'une exception lorsque l'appel de InetPton n'a pas fonctionné. Le numéro de cette exception est 2
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsInetPton(const string& msg) : QExceptionsReseaux(2, msg) {};
};

/*
* @brief Exception lancée lorsque le socket n'a pas réussi à se connecter au serveur. Hérite de la classe QExceptionsReseaux
*/
class QExceptionsSocketConnection : public QExceptionsReseaux {
public:
	/*
	* @brief Création d'une exception lorsque la connexion du socket au serveur n'a pas fonctionné. Le numéro de cette exception est 3
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsSocketConnection(const string& msg) : QExceptionsReseaux(3, msg) {};
};

/*
* @brief Exception lancée lorsque le socket ne s'est pas fermé correctement. Hérite de la classe QExceptionsReseaux
*/
class QExceptionsFermetureSocket : public QExceptionsReseaux {
public:
	/*
	* @brief Création d'une exception lorsque la deconection du socket à échoué. Le numéro de cette exception est 4
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsFermetureSocket(const string& msg) : QExceptionsReseaux(4, msg) {};
};

/*
* @brief Exception lancée lorsque l'écriture dans le socket à échoué. Hérite de la classe QExceptionsReseaux
*/
class QExceptionsEcritureSocket : public QExceptionsReseaux {
public:
	/*
	* @brief Création d'une exception lorsque l'écriture dans le socket a échoué. Le numéro de cette exception est 5
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsEcritureSocket(const string& msg) : QExceptionsReseaux(5, msg) {};
};

/*
* @brief Exception lancée lorsque la lécture dans le socket à échoué. Hérite de la classe QExceptionsReseaux
*/
class QExceptionsLectureSocket : public QExceptionsReseaux {
public:
	/*
	* @brief Création d'une exception lorsque la lecture dans le socket a échoué.  Le numéro de cette exception est 5
	* @param msg  : le message d'erreur de l'exception
	*/
	QExceptionsLectureSocket(const string& msg) : QExceptionsReseaux(5, msg) {};
};
