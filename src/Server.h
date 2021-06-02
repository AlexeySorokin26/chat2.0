#pragma once
#include "mysql/mysql.h"
#include "User.h"
#include <iostream>
#include <boost/tokenizer.hpp>
#include <filesystem>
#include "Utility.h"
#include <string.h>
#if defined(__linux__)
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/utsname.h>  //uname
#define MESSAGE_LENGTH 1024 // Максимальный размер буфера для данных
#define PORT 7777 // Будем использовать этот номер порта
#else
#include <stdio.h>
#include <windows.h>
#endif

class Server {
public:
	Server(unsigned int amountOfUsers = 0, const int connection = -1);
	~Server();
	MY_SERVER_ERRORS SetServer();
	std::string ReadCommand();
	ssize_t SendCommand();
	void Help() const;																// how to use our server
	void ShowOSInfo() const;
	void ShowUser(const int id);													// print info about user with id
	void ShowAllUsers();
	void AddUser(const User& newUser);												// registration
	void AddUsersFromFile(const std::string& serverDataFile);

	void AddUsersFromMySQL();
	void AddUsersToMySQL();
	std::vector<User> GetUsers();

	void AddUsersToFile(const std::string& serverDataFile);
	void RemoveUserByID(const size_t id);
	unsigned int GetAmountOfUser();
	void SendMyMessage(const size_t fromId, const size_t ToId, const std::string& message);
	void SendMessageToAll(const size_t fromId, const std::string& message);
	void ShowUserMessages(const size_t id);
	bool ValidId(const size_t id);
	bool PassUser(const std::string& password, const std::string& login);				// check if user enter his/her password and login correctly if so then enter his/her to the chat
	bool Loginned(const size_t id);													// check if a user is _loggined
	void LoginUser(const std::string& login);										// to set _loggined of user to true;
	void Logout(const size_t id);
	int GetIdByLogin(const std::string& login);
private:

	MYSQL mysql;

	std::vector<User> _users;														// id-User ?maybe better to use a list or deque; 
	unsigned int _amountOfUsers;
	int _connection;
	int _socket_file_descriptor;

	void GetDescriptor(MYSQL &mysql);
	void GetConnection(MYSQL &mysql);
	void readAllFromBD(MYSQL &mysql);
};

