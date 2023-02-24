#include "WinsocketSocket.h"
#include "../Exceptions/QExceptionsReseaux.h"
#include <winsock2.h>
#include <ws2tcpip.h>

WinsocketSocket::WinsocketSocket(const char* servAd, short servPort) {
	s = INVALID_SOCKET;
	int familleAdresses = AF_INET; 
	int typeSocket = SOCK_STREAM; 
	int protocole = IPPROTO_TCP; 

	s = socket(familleAdresses, typeSocket, protocole);
	if (s == INVALID_SOCKET) throw new QExceptionsReseaux(-1, "socket invalide");


	SOCKADDR_IN sockaddress;

	sockaddress.sin_family = AF_INET;
	sockaddress.sin_port = htons(servPort);
	if( inet_pton(AF_INET, servAd, &(sockaddress.sin_addr.s_addr)) != 1) throw new QExceptionsReseaux(-1, "inet_pton erreur");

	

	if( connect(s, (SOCKADDR*)&sockaddress, sizeof(sockaddr)) == SOCKET_ERROR) throw new QExceptionsReseaux(-1, "socket erreur");


}
WinsocketSocket::~WinsocketSocket() {
	if(shutdown(s, SD_BOTH) == SOCKET_ERROR) throw new QExceptionsReseaux(-1, "fermeture lecture ecriture erreur");
	if(closesocket(s)) throw new QExceptionsReseaux(-1, "fermeture socket erreur");
}

void WinsocketSocket::write(const char* msg, int l) const {
	char* st = _strdup(msg);
	st[l++] = '\r';
	if(send(s, st, l, 0) == SOCKET_ERROR ) throw new QExceptionsReseaux(-1, "ecriture erreur");
	delete st;
}
void WinsocketSocket::read(char* msg, const int BUFFSIZE) const {
	if( recv(s, msg, BUFFSIZE - 1, 0) == SOCKET_ERROR) throw new QExceptionsReseaux(-1, "lecture erreur");
}