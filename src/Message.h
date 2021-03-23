#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>

class Message {
public:
	Message(std::string message);
	~Message() = default;
	const std::string& GetMyMessage() const;
	/* 
	friend ifstream& operator >>(std::ifstream& is, Message& obj);
	friend ofstream& operator <<(std::ofstream& os, const Message& obj);
	
	friend istream& operator >>(istream& is, Message& obj);
	friend ostream& operator <<(ostream& os, const Message& message);
	*/
private:
	std::string _message;
};

