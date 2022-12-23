/**
 * @file SocketSingleton.cpp
 * */
#include "SocketSingleton.h"

/*************************************************************************************************************//**
 * @brief On initialise le champ statique en dehors du fichier d'en-tête pour éviter des inclusions miltiples
 ****************************************************************************************************************/
SocketSingleton* SocketSingleton::SINGLETON = nullptr;

/*************************************************************************************************************//**
 * @brief Constructeur protected de notre singleton
 ****************************************************************************************************************/
SocketSingleton::SocketSingleton(const char *arg_address, const short &arg_port): Socket(arg_address, arg_port) {}

/*************************************************************************************************************//**
 * @brief Renvoir l'unique instance autorisée à être instanciée par le client
 * d'un objet de type SocketSingleton.
 *
 * SocketSingleton hérite de Socket, par conséquent elle hérite aussi toutes ces méthodes privées dont
 * les plus utiles send_data() et receive_data().
 * @see Socket.h
 *
 * @param arg_address l'adresse IPV4 du serveur distant
 * @param arg_port le port choisi pour se connecter
 * @return l'unique instance de cette classe autoriée à créer
 *
 ****************************************************************************************************************/
SocketSingleton *SocketSingleton::CONNECT(const char *arg_address, const short &arg_port) {
    return SocketSingleton::SINGLETON == nullptr ? new SocketSingleton(arg_address, arg_port) : SocketSingleton::SINGLETON;
}