#pragma once
#include "User.h"
#include <iostream>

class Server {
public:
	Server(unsigned int amountOfUsers = 0);
	~Server() = default;
	void Help() const;								// how to use our server
	void ShowUser(const int id);					// print info about user with id
	void ShowAllUsers();
	void AddUser(const User& newUser);				// registration
	bool LoginUser(const std::string password, const std::string login);
	void RemoveUserByID(const int id);		
	unsigned int GetAmountOfUser();
	void SendMessage(const int fromId, const int ToId, const std::string message);
	void ShowUserMessages(const int id);
	bool ValidId(const int id);
private:
	std::vector<User> _users;				// id-User ?maybe better to use a list or deque; 
	unsigned int _amountOfUsers;
};

