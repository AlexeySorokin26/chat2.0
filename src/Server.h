#pragma once
#include "User.h"
#include <iostream>

class Server {
public:
	Server(unsigned int amountOfUsers = 0);
	~Server() = default;
	void Help() const;
	void ShowUser(const int id);
	void AddUser(User newUser);
	void RemoveUserByID(const int id);
	unsigned int GetAmountOfUser();
	void SendMessage(const int fromId, const int ToId, const std::string message);
private:
	std::vector<User> _users; // id-User ?maybe better to use a list or deque; 
	unsigned int _amountOfUsers;
};

