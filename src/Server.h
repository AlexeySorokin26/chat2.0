#pragma once
#include "User.h"
#include <iostream>
#include <boost/tokenizer.hpp>
#include <filesystem>
#include "Utility.h"

#if defined(__linux__)
#include <sys/utsname.h>  //uname
#else
#include <stdio.h>
#include <windows.h>
#endif


class Server {
public:
	Server(unsigned int amountOfUsers = 0);
	~Server() = default;
	void Help() const;																// how to use our server
	void ShowOSInfo() const;
	void ShowUser(const int id);													// print info about user with id
	void ShowAllUsers();
	void AddUser(const User& newUser);												// registration
	void AddUsersFromFile(const std::string serverDataFile);
	void AddUsersToFile(const std::string serverDataFile);
	void RemoveUserByID(const int id);		
	unsigned int GetAmountOfUser();
	void SendMyMessage(const int fromId, const int ToId, const std::string message);
	void SendMessageToAll(const int fromId, const std::string message);
	void ShowUserMessages(const int id);
	bool ValidId(const int id);
	bool PassUser(const std::string password, const std::string login);				// check if user enter his/her password and login correctly if so then enter his/her to the chat
	bool Loginned(const int id);													// check if a user is _loggined
	void LoginUser(const std::string login);										// to set _loggined of user to true;
	void Logout(const int id);
	int GetIdByLogin(const std::string login);
private:
	std::vector<User> _users;														// id-User ?maybe better to use a list or deque; 
	unsigned int _amountOfUsers;
};

