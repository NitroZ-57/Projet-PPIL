#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;



class QExceptionsCoordMonde : public QExceptions {
protected:
	QExceptionsCoordMonde(const int& code, const string& msg) : QExceptions(code, msg) {}
};


class QExceptionsNombreFormeIncorrect : public QExceptionsCoordMonde {
public:
	QExceptionsNombreFormeIncorrect(const string& msg) : QExceptionsCoordMonde(0, msg) {};
};
