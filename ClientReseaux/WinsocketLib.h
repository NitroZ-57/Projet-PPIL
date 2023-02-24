#pragma once

#pragma comment(lib, "ws2_32.lib")

class WinsocketLib
{
private:
	
	static WinsocketLib* singleton;
	WinsocketLib() {}

public:

	virtual ~WinsocketLib();
	static const WinsocketLib* DEMARRER();

};

