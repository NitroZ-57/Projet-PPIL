#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>


class WinsocketSocket
{
private:
	SOCKET s;



public:
	WinsocketSocket(const char* servAd, short servPort);
	~WinsocketSocket();

	void write(const char* msg, int l) const;
	void read(char* msg, const int BUFFSIZE) const;
};

