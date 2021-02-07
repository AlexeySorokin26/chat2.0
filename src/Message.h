#pragma once
#include <string>

class Message {
public:
	Message(std::string message);
	~Message() = default;
	const std::string& GetMessage() const;
private:
	std::string _message;
};

