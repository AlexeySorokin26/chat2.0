#include "User.h"

int User::id = -1; // id of users will start from 1; 

User::User(std::string password, std::string name, std::string surname, std::string age)
	: _name(name), _age(age), _surname(surname), _password(password) {
	id++;
}

const int User::Id() const {
	return id;
}

int User::TotalNumberOfUsers() {
	return id;
}

const std::string& User::GetName() const {
	return _name;
}

std::string& User::SetName(const std::string otherName) {
	_name = otherName;
	return _name;
}

const std::string& User::GetSurname() const {
	return _surname;
}

std::string& User::SetSurname(std::string otherSurname) {
	_surname = otherSurname;
	return _surname;
}

const std::string User::GetAge() const {
	return _age;
}

std::string& User::SetAge(std::string otherAge) {
	_age = otherAge;
	return _age;
}

std::string& User::SetPassword(const char* password) {
	int i = 0;
	while (password[i]!= '\0')
		_password[i++] = *(password + i);
}

void User::AddMessageWithId(std::pair<int, Message> messageWithId) {
	_receivedMessages.push_back(messageWithId);
}

void User::ShowInfo() {
	std::cout << "Name:" << _name << ", Surname: " << _surname << ", Age: " << _age << std::endl;
}


