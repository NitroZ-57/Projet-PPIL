#pragma once
#include <iostream>

using namespace std;


class QExceptions {

private:
	int code;
	string msg;

protected:
	QExceptions(const int& code = -1, const string& msg = "ERROR") { this->code = code; this->msg = msg; }

public:
	QExceptions() { code = -1; msg = "ERROR"; }
	int getCode() const { return code; }
	string getMessage() const { return msg; }

};