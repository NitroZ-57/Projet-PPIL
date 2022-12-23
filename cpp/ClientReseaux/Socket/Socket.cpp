/**
 * @file Socket.cpp
 * */
#include "Socket.h"
#include <sys/socket.h> // socket(), connect(), send(), recv(), shutdown()
#include <netinet/in.h> // constants AF_INET, SOCK_STREAM, IPROTO_TCP
#include <arpa/inet.h> // inet_addr()
#include <string> // strncpy(), strncat(), strlen()
#include <unistd.h> // close()
#include <cstdlib> // free()
#include <cerrno> // strerror(), errno
#include "../SocketException/SocketException.h" // Socket specific exceptions

extern errno_t errno; /*< On récupère ici la variable de errno.h **/

/*************************************************************************************************************//**
 * @brief Ce constructeur permet d'initier une connexion TCP/IP avec un serveur.
 *
 * Ce constructeur à une visibilité réduite à protected pour bloquer à l'utilisateur la création de plusieurs
 * sockets ( surtout pour éviter de spamer le serveur de requêttes inutiles ).
 * Le seul moyen d'initialiser un objet de type Socket est de passer la classe SocketSingleton
 * qui implémente le design pattern singleton sur l'unique objet Socket qui peut être crée par le client.
 * @see SocketSingleton.h
 *
 * @param arg_address adresse IP4 du serveur distant auquel on souhaite se connecter.
 * @param arg_port le numéro du port qu'on souhaite utiliser. Attention de ne pas saisir un port déjà utilisé.
 * @return un objet de type Socket.
 * @throws SocketException si les fonctions socket et/ou connect écouent à leur tour.
 ****************************************************************************************************************/
Socket::Socket(const char *arg_address, const short& arg_port) {
    errno = 0;
    _sock_fd = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
    if (_sock_fd == -1)
        throw SocketException(strerror(errno));
    // socket data
    struct sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(arg_address);
    server.sin_port = htons(arg_port);
    // connection
    if (connect(_sock_fd, (struct sockaddr *)&server, sizeof(server)) == -1)
        throw SocketException(strerror(errno));
}

/*************************************************************************************************************//**
 * @brief Méthode permettant d'envoyer les données vers le serveur
 * @param message chaîne de caractère du C classique à envoyer au serveur
 * @param buff_size la longeur de la chaîne de caractère à envoyer au serveur
 * @return void
 ****************************************************************************************************************/
void Socket::send_data(const char *message) const {
    std::string message_to_send(message);
    message_to_send += "\r\n";
    errno = 0;
    if (send(_sock_fd, (const void*)message_to_send.c_str(), message_to_send.length() + 1, 0) < 0) {
        throw SocketException(strerror(errno));
    }
}

/*************************************************************************************************************//**
 * @brief Méthode permettant de recevoir les données du serveur
 * @param message la chaîne de caractères où sera recopié le résultat
 * @param buff_size la longeur de la chaîne de caractères qu'on attend de la part du serveur
 * @return void
 ****************************************************************************************************************/
void Socket::receive_data(char *message) const {
    errno = 0;
    if (recv(_sock_fd, (void *)message, std::strlen(message) + 1, 0) < 0)
        throw SocketException(strerror(errno));
}

/*************************************************************************************************************//**
 * @brief Destructor
 *
 * Le destructeur n'est pas vide dans la mesure où on doit fermer le socket pour signaler la fin
 * de la communication avec le serveur.
 ****************************************************************************************************************/
Socket::~Socket() {
    shutdown(_sock_fd, SHUT_RDWR);
    close(_sock_fd);
}