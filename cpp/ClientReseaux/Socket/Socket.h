/**
 * @file Socket.h
 * */
#ifndef NETWORKING_SOCKET_H
#define NETWORKING_SOCKET_H

/************************************************************************************************************//**
 * @author Oleksandr Stetsenko
 * @class Socket
 * @brief CLasse permettant d'initier une connexion TCP/IP à un serveur distant et d'envoyer/reçevoir des données
 ***************************************************************************************************************/
class Socket {
    int _sock_fd; /**< descripteur de fichier qui identifie notre socket */
protected:
    explicit Socket(const char* arg_address, const short& arg_port);
public:
    virtual ~Socket();
    void send_data(const char* message) const;
    void receive_data(char* message) const;
};


#endif //NETWORKING_SOCKET_H
