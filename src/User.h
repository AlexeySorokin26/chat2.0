#pragma once
#include "Message.h"
#include <string>
#include <vector>
#include <utility>
#include <iostream>

class User {
private:
	std::vector<std::pair<int, Message>> _receivedMessages; // vector of messages; each message is a pair of a sender id and his/her text 
	std::string _password;
	std::string _name;
	std::string _surname;
	std::string _age;
	static int id;
public:
	User(std::string password = "nopassword", std::string name = "noname", std::string surname = "noname", std::string = "0");
	~User() = default;
	const int Id() const;
	static int TotalNumberOfUsers();
	const std::string& GetName() const;
	std::string& SetName(const std::string otherName="noname");
	const std::string& GetSurname() const;
	std::string& SetSurname(const std::string otherSurname = "nosurname");
	const std::string GetAge() const;
	std::string& SetAge(const std::string otherAge = "0");
	std::string& SetPassword(const char* password);
	void AddMessageWithId(const std::pair<int, Message> messageWithId);
	void ShowInfo();
}; 

