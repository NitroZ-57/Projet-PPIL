#pragma once
#include <iostream>

using namespace std;
/*
* Classe d'exception générale pour toutes les excpetions du projet
* code : le numéro de l'exception
* msg  : le message d'erreur de l'exception 
*/
class QExceptions {

private:
	int code;
	string msg;

protected:
	/*
	* Création d'une exception
	* code : le numéro de l'exception (-1 par défaut)
	* msg  : le message d'erreur de l'exception (ERROR par défaut)
	*/
	QExceptions(const int& code = -1, const string& msg = "ERROR") { this->code = code; this->msg = msg; }

public:
	/*
	* Création d'une exception lambda avec un code de -1 et un message d'erreur "ERROR"
	*/
	QExceptions() { code = -1; msg = "ERROR"; }

	/*
	* Obtenir le numéro de l'exception
	*/
	int getCode() const { return code; }

	/*
	* Obtenir le message d'erreur de l'exception
	*/
	string getMessage() const { return msg; }

};