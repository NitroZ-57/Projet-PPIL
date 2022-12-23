/**
* @file SocketSingleton.h
* */
#ifndef NETWORKING_SOCKETSINGLETON_H
#define NETWORKING_SOCKETSINGLETON_H
#include "../Socket/Socket.h"


class SocketSingleton: public Socket {
protected:
    static SocketSingleton* SINGLETON;
    SocketSingleton(const char* arg_address, const short& arg_port);
public:
    static SocketSingleton* CONNECT(const char* arg_address, const short& arg_port);
    ~SocketSingleton() override = default;
};


#endif //NETWORKING_SOCKETSINGLETON_H
