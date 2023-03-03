#pragma once
#include <iostream>

using namespace std;
/*
* @brief Classe d'exception générale pour toutes les excpetions du projet composé d'un code d'erreur et d'un message d'erreur
*/
class QExceptions {

private:
	int code;
	string msg;

protected:
	/*
	* @brief Création d'une exception
	* @param code : le numéro de l'exception (-1 par défaut)
	* @param msg  : le message d'erreur de l'exception (ERROR par défaut)
	*/
	QExceptions(const int& code = -1, const string& msg = "ERROR") { this->code = code; this->msg = msg; }

public:
	/*
	* @brief Création d'une exception lambda avec un code de -1 et un message d'erreur "ERROR"
	*/
	QExceptions() { code = -1; msg = "ERROR"; }

	int getCode() const { return code; }
	string getMessage() const { return msg; }

};