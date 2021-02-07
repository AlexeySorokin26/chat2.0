#pragma once
#include <string>
#include <iostream>
#include <ostream>

class Message {
public:
	Message(std::string message);
	~Message() = default;
	const std::string& GetMessage() const;
	friend std::ostream& operator<< (std::ostream& out, const Message& message);
private:
	std::string _message;
};

