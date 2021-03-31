#include "Client.h"

Client::Client(const int connection, const int socket_file_descriptor) : 
    _connection(connection),  _socket_file_descriptor(socket_file_descriptor) { }

Client::~Client() {

}
MY_SERVER_ERRORS Client::SetServer() {
    const char* ip_address = "192.168.126.129";
    // Создадим сокет
    sockaddr_in serveraddress;
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
        std::cout << "Connection with the server failed.!" << std::endl;
        return MY_SERVER_ERRORS::CANT_CONNECT_WITH_SERVER;
    }
    return MY_SERVER_ERRORS::OK;
}