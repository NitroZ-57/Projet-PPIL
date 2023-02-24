#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;



class QExceptionsGeometrie : public QExceptions{
protected:
	QExceptionsGeometrie(const int& code, const string& msg) : QExceptions(code, msg) {}
};


class QExceptionsIndiceHorsPortee : public QExceptionsGeometrie{
public:
	QExceptionsIndiceHorsPortee(const string& msg) : QExceptionsGeometrie(0, msg){};
};

class QExceptionsCouleurInexistance : public QExceptionsGeometrie {
public:
	QExceptionsCouleurInexistance(const string& msg) : QExceptionsGeometrie(1, msg) {};
};

class QExceptionsEstDejaDansUnGroupe : public QExceptionsGeometrie {
public:
	QExceptionsEstDejaDansUnGroupe(const string& msg) : QExceptionsGeometrie(2, msg) {};
};

class QExceptionsNombrePointsInsuffisant : public QExceptionsGeometrie {
public:
	QExceptionsNombrePointsInsuffisant(const string& msg) : QExceptionsGeometrie(3, msg) {};
};

class QExceptionsFormeNonConnexe : public QExceptionsGeometrie {
public:
	QExceptionsFormeNonConnexe(const string& msg) : QExceptionsGeometrie(4, msg) {};
};

class QExceptionsGroupeVide : public QExceptionsGeometrie {
public:
	QExceptionsGroupeVide(const string& msg) : QExceptionsGeometrie(5, msg) {};
};