/**
 * @file SocketException.cpp
 * */
#include "SocketException.h"
#include <cstdlib>
#include<string>

SocketException::SocketException(const char *arg_message): _message(const_cast<char *>(arg_message)) {}

SocketException::~SocketException() noexcept {
    if (!_message)
        free(_message);
}

const char *SocketException::what() const noexcept {
    return _message;
}

SocketException::operator std::string() const {
    return {_message};
}

std::iostream& operator<<(std::iostream &o, const SocketException &e) {
    o << (std::string)e;
    return o;
}
