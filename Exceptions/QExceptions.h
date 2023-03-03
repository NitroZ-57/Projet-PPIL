#pragma once
#include <iostream>

using namespace std;
/*
* @brief Classe d'exception g�n�rale pour toutes les excpetions du projet compos� d'un code d'erreur et d'un message d'erreur
*/
class QExceptions {

private:
	int code;
	string msg;

protected:
	/*
	* @brief Cr�ation d'une exception
	* @param code : le num�ro de l'exception (-1 par d�faut)
	* @param msg  : le message d'erreur de l'exception (ERROR par d�faut)
	*/
	QExceptions(const int& code = -1, const string& msg = "ERROR") { this->code = code; this->msg = msg; }

public:
	/*
	* @brief Cr�ation d'une exception lambda avec un code de -1 et un message d'erreur "ERROR"
	*/
	QExceptions() { code = -1; msg = "ERROR"; }

	int getCode() const { return code; }
	string getMessage() const { return msg; }

};