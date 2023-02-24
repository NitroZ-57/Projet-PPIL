#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;



class QExceptionsVisiteur : public QExceptions {
protected:
	QExceptionsVisiteur(const int& code, const string& msg) : QExceptions(code, msg) {}
};

