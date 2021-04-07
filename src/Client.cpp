#include "Client.h"

/* 
Client::Client(const int connection, const int socket_file_descriptor) : 
    _connection(connection),  _socket_file_descriptor(socket_file_descriptor) { }
*/
Client::~Client() {
    close(_socket_file_descriptor);
}
MY_SERVER_ERRORS Client::SetServer() {
    const char* ip_address = "192.168.126.129";
    //const char* ip_address = "81.177.136.104";
    
    // Создадим сокет
    sockaddr_in serveraddress;
    _socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(_socket_file_descriptor == -1) {
        std::cout << "Creation of Socket failed!" << std::endl;
        return MY_SERVER_ERRORS::SOCKET_CREATION_FAULT;
    }
    // Установим адрес сервера
    serveraddress.sin_addr.s_addr = inet_addr(ip_address);
    // Зададим номер порта
    serveraddress.sin_port = htons(PORT);
    // Используем IPv4
    serveraddress.sin_family = AF_INET;
    // Установим соединение с сервером
    _connection = connect(_socket_file_descriptor, (struct sockaddr*)&serveraddress, sizeof(serveraddress));
    if(_connection == -1){
        std::cout << "Connection with the server failed!" << std::endl;
        return MY_SERVER_ERRORS::CANT_CONNECT_WITH_SERVER;
    }
    return MY_SERVER_ERRORS::OK;
}

std::string Client::ReadCommand() {
    char message[MESSAGE_LENGTH];
	bzero(message, MESSAGE_LENGTH);
    read(_socket_file_descriptor, message, sizeof(message));
    return std::string(message);
}
ssize_t Client::SendCommand() {
    //char message[MESSAGE_LENGTH];
    std::string message;
    std::cin >> message;
    if (message == "0" ) {
        write(_socket_file_descriptor, message.c_str(), sizeof(message));
        std::cout << "Client Exit." << std::endl;
        return -1;
    }
    ssize_t bytes = write(_socket_file_descriptor, message.c_str(), sizeof(message));
    return bytes;
}