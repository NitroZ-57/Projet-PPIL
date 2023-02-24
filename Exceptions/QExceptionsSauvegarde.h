#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;



class QExceptionsSauvegarde : public QExceptions {
protected:
	QExceptionsSauvegarde(const int& code, const string& msg) : QExceptions(code, msg) {}
};


class QExceptionsNomFichierTropLong : public QExceptionsSauvegarde {
public:
	QExceptionsNomFichierTropLong(const string& msg) : QExceptionsSauvegarde(0, msg) {};
};

class QExceptionsLectureSimpleImpossible : public QExceptionsSauvegarde {
public:
	QExceptionsLectureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(1, msg) {};
};

class QExceptionsEcritureSimpleImpossible : public QExceptionsSauvegarde {
public:
	QExceptionsEcritureSimpleImpossible(const string& msg) : QExceptionsSauvegarde(2, msg) {};
};

class QExceptionsFichierNonDefini : public QExceptionsSauvegarde {
public:
	QExceptionsFichierNonDefini(const string& msg) : QExceptionsSauvegarde(3, msg) {};
};