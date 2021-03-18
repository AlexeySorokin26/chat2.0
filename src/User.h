#pragma once
#include "Message.h"
#include "Utility.h"
#include <string>
#include <vector>
#include <utility>
#include <iostream>

class User {
private:
	std::vector<std::pair<int, Message>> _receivedMessages; // vector of messages; each message is a pair of a sender id and his/her text 
	std::string _login;
	std::string _password;
	std::string _name;
	std::string _surname;
	std::string _age;
	bool _loggined;  // if a user is loggined 
	int id;
	static int counter_of_users;
public:
	User(std::string login="nologin", std::string password="nopassword", std::string name="noname", std::string surname="noname", std::string age="0", bool loggined=false);
	~User() = default;
	int Id() const;
	static int& TotalNumberOfUsers();

	const std::string& GetName() const;
	std::string& SetName(const std::string otherName="noname");

	const std::string& GetSurname() const;
	std::string& SetSurname(const std::string otherSurname="nosurname");

	const std::string GetAge() const;
	std::string& SetAge(const std::string otherAge="0");
	unsigned int AgeToUInt(); // will return age as int; as well check if it possible; 
	unsigned int TypeYourAgeAgain(); // and ask to set a normal number;

	//std::string& SetPassword(const char* password);
	std::string& SetPassword(const std::string password="");
	const std::string GetPassword() const;

	std::string& SetLogin(const std::string login="nologin");
	const std::string& GetLogin() const;

	bool& SetLoggined(const bool loggined=false); //
	const bool& GetLoggined() const;

	void AddMessageWithId(const std::pair<int, Message> messageWithId);
	void DeleteMessages();
	void ShowInfo();
	void ShowMessages();
}; 

