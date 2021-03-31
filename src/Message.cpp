#include "Message.h"

Message::Message(std::string message) : _message(message) {

}

const std::string& Message::GetMyMessage() const {
		return _message;
}
/*
std::ifstream& operator>>(std::ifstream& is, Message& obj) {
	is >> obj._message;
	return is;
}

std::ofstream& operator<<(std::ofstream& os, const Message& obj) {
	os << obj << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, Message& obj) {
	is >> obj._message;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Message& message) {
	os << message._message << std::endl;
	return os;
}
*/






