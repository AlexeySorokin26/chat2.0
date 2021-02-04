#pragma once
#include <string>

class User {
private:
	std::string _name;
	std::string _surname;
	unsigned int _age;
public:
	User(std::string name, std::string surname, unsigned int age) 
		: _name(name), _age(age), _surname(surname) { }
	~User() = default;
};

