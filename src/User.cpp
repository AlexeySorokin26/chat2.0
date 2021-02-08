#include "User.h"

int User::id = -1; // id of users will start from 1; 

User::User(std::string login, std::string password, std::string name, std::string surname, std::string age, bool loggined)
	: _login(login), _password(password), _name(name), _surname(surname), _age(age), _loggined(loggined) {
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

/*
std::string& User::SetPassword(const char* password) {

	 int i = 0;
	while (password[i]!= '\0')
		_password[i++] = *(password + i);
	
}
*/
std::string& User::SetPassword(const std::string password) {
	_password = password;
	return _password;
}


const std::string User::GetPassword() const {
	return _password;
}

std::string& User::SetLogin(const std::string login) {
	_login = login;
	return _login;
}

const std::string& User::GetLogin() const {
	return _login;
}

bool& User::SetLoggined(const bool loggined) {
	_loggined = loggined;
	return _loggined;
}

const bool& User::GetLoggined() const {
	return _loggined;
}

void User::AddMessageWithId(std::pair<int, Message> messageWithId) {
	_receivedMessages.push_back(messageWithId);
}

void User::ShowInfo() {
	//std::string tmpName = toupper(_name[0]) + name[]
	// we could work on nice typing of our names: sorOkiN - > Sorokin for example
	// islower isupper tolower toupper
	std::cout << "Name:" << _name << ", Surname: " << _surname << ", Age: " << _age <<
		", Login:" << _login << std::endl;
	std::cout << "------------------------------------" << std::endl;
}

void User::ShowMessages() {
	for (auto& sm : _receivedMessages) 
		std::cout << "message from user with id: " << sm.first << " a message: " << sm.second << std::endl;
}


