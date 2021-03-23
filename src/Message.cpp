#include "Message.h"

Message::Message(std::string message) : _message(message) {

}

const std::string& Message::GetMyMessage() const {
		return _message;
}


/* 
ifstream& operator>>(ifstream& is, Message& obj) {
	is >> obj._message;
	return is;
}

ofstream& operator<<(ofstream& os, const Message& obj) {
	os << obj << std::endl;
	return os;
}

istream& operator >> (istream& is, Message& obj) {
	is >> obj._message;
	return is;
}

ostream& operator<<(ostream& os, const Message& message) {
	os << message._message << std::endl;
	return os;
}
*/






