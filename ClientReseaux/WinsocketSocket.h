#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>

/*
* @brief Classe permettant de cr�er un socket de winsocket et d'envoyer ou recevoir dans ce socket
*/
class WinsocketSocket
{
private:
	SOCKET s;



public:
	/*
	* @brief Creation et connexion d'un socket
	* @param servAd : l'adresse du serveur sous forme de chaine de carct�re
	* @param servPort : le port du serveur sur lequel se connecter
	*/
	WinsocketSocket(const char* servAd, short servPort);
	~WinsocketSocket();

	/*
	* @brief Ecrit un message dans le socket
	* @param msg : le message � �crire
	* @param l : la taille du message � �crire
	*/
	void write(const char* msg, int l) const;

	/*
	* @brief lit un message de taille BUFFSIZE au maximum dans le socket
	* @param msg : un pointeur sur une chaine de caract�re o� �crire le message
	* @param BUFFSIZE : la taille du buffer pour lire
	*/
	void read(char* msg, const int BUFFSIZE) const;
};

