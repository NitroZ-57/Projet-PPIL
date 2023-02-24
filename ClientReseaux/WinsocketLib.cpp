#include "WinsocketLib.h"
#include "../Exceptions/QExceptionsReseaux.h"
#include <winsock2.h>
#include <ws2tcpip.h>
WinsocketLib* WinsocketLib::singleton = NULL;

WinsocketLib::~WinsocketLib() {
	if(singleton != NULL)
		WSACleanup();
}

const WinsocketLib* WinsocketLib::DEMARRER() {
	
	WSADATA d;
	
	int err = WSAStartup(MAKEWORD(2, 0), &d);
	if (err)
		throw new QExceptionsReseaux(err, "erreur wsa startup");
	
	singleton = new WinsocketLib();
	return singleton;

}