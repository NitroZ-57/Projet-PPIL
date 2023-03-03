#pragma once

#pragma comment(lib, "ws2_32.lib")

/*
* @brief Classe permettant de lancer la librairie winsock. Classe singleton
*/
class WinsocketLib
{
private:

	static WinsocketLib* singleton;
	WinsocketLib() {}

public:

	virtual ~WinsocketLib();

	/*
	* @brief Lancement de la librairie winscok
	*/
	static const WinsocketLib* DEMARRER();

};

