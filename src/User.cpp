#include "User.h"

size_t User::counter_of_users = 0; // id of users will start from 0; 

User::User(std::string login, std::string password, std::string name, std::string surname, std::string age, bool loggined)
	: _login(login), _password(password), _name(name), _surname(surname), _age(age), _loggined(loggined) {
	id = counter_of_users;
	counter_of_users++;
}

size_t User::Id() const {
	return id;
}

size_t& User::TotalNumberOfUsers() {
	return counter_of_users;
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

unsigned int User::AgeToUInt() {
	if (IsStringNumber(_age)) { // if it possible to convert age to int; user could type his/her age as a 2i8 or something 
		return stoi(_age);
	}
	else {
		return TypeYourAgeAgain();
	}
}

unsigned int User::TypeYourAgeAgain() {
	std::cout << "You typed your age wrong. Would you like to set it correctly? Type yes if you want it or no to finish." << std::endl;
	std::string answer; getline(std::cin, answer);
	while(answer == "yes") {
		std::string age;
		getline(std::cin, age);
		if (IsStringNumber(age)) {
			_age = age;
			return stoi(_age);
		}
		std::cout << "You typed your age wrong. Would you like to set it correctly? Type yes if you want it or no to finish." << std::endl;
	}
}


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

void User::DeleteMessages() {
	_receivedMessages.clear();
}

void User::ShowInfo() {
	//std::string tmpName = toupper(_name[0]) + name[]
	// we could work on nice typing of our names: sorOkiN - > Sorokin for example
	// islower isupper tolower toupper
	std::cout << "Name: " << _name << ", Surname: " << _surname << ", Age: " << _age <<
		", Login: " << _login << ", id: " << id << std::endl;
	std::cout << "------------------------------------" << std::endl;
}

void User::ShowMessages() {
	if (_receivedMessages.size() != 0) {
		for(int i = 0; i < _receivedMessages.size(); ++i)
			std::cout << "message from user with id: " << _receivedMessages[i].first << " a message: " << _receivedMessages[i].second.GetMyMessage() << std::endl;
		/* 
		for (const auto& sm : _receivedMessages)
			std::cout << "message from user with id: " << sm.first. << " a message: " << sm.second << std::endl;
		*/
	}
	else
		std::cout << "no message yet\n";
}

std::vector<std::pair<int, Message>> User::GetMessages() {
	return _receivedMessages;
}


