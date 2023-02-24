#pragma once
#include <iostream>
#include "QExceptions.h"

using namespace std;



class QExceptionsReseaux : public QExceptions {
public:
	QExceptionsReseaux(const int& code, const string& msg) : QExceptions(code, msg) {}
};



