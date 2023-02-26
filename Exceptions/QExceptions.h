#pragma once
#include <iostream>

using namespace std;
/*
* Classe d'exception g�n�rale pour toutes les excpetions du projet
* code : le num�ro de l'exception
* msg  : le message d'erreur de l'exception 
*/
class QExceptions {

private:
	int code;
	string msg;

protected:
	/*
	* Cr�ation d'une exception
	* code : le num�ro de l'exception (-1 par d�faut)
	* msg  : le message d'erreur de l'exception (ERROR par d�faut)
	*/
	QExceptions(const int& code = -1, const string& msg = "ERROR") { this->code = code; this->msg = msg; }

public:
	/*
	* Cr�ation d'une exception lambda avec un code de -1 et un message d'erreur "ERROR"
	*/
	QExceptions() { code = -1; msg = "ERROR"; }

	/*
	* Obtenir le num�ro de l'exception
	*/
	int getCode() const { return code; }

	/*
	* Obtenir le message d'erreur de l'exception
	*/
	string getMessage() const { return msg; }

};