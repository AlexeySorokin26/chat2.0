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
	friend std::ifstream& operator >>(std::ifstream& is, Message& obj);
	friend std::ofstream& operator <<(std::ofstream& os, const Message& obj);
	
	friend std::istream& operator >>(std::istream& is, Message& obj);
	friend std::ostream& operator <<(std::ostream& os, const Message& message);
	*/
private:
	std::string _message;
};

