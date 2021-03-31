#pragma once
#include "User.h"

#if defined(__linux__)
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#endif
 

#define MESSAGE_LENGTH 1024 // Максимальный размер буфера для данных
#define PORT 7777 // Будем использовать этот номер порта

class Client : public User{
public:
    Client(const int connection = -1, const int socket_file_descriptor = -1);
    ~Client();
    MY_SERVER_ERRORS SetServer();
private:
    int _connection;
	int _socket_file_descriptor;
};