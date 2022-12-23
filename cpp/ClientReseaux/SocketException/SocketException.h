/**
 * @file SocketException.h
 * */
#include<exception>
#include <string>
#include <iostream>

/*************************************************************************************************************//**
 * @author Oleksandr Stetsenko
 * @class SocketException
 * @brief Cette classe sert à être lancée en guise d'exception dans la classe Socket lorsqu'un comportement \
 * indésirable.
 * @inherit exception
 ***************************************************************************************************************/
class SocketException: public std::exception {
    char* _message; /**< le message à afficher */
public:
    explicit SocketException(const char* arg_message);
    ~SocketException() _NOEXCEPT override;
    const char *what() const _NOEXCEPT override;
    explicit operator std::string() const;
    friend std::iostream& operator<<(std::iostream& o, const SocketException& e);
};