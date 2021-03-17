#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

class Message {
public:
	Message(string message);
	~Message() = default;
	const std::string& GetMessage() const;

	friend ifstream& operator >>(std::ifstream& is, Message& obj);
	friend ofstream& operator <<(std::ofstream& os, const Message& obj);
	
	friend istream& operator >>(istream& is, Message& obj);
	friend ostream& operator <<(ostream& os, const Message& message);
	
private:
	string _message;
};

