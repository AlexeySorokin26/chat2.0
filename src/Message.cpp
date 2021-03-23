#include "Message.h"

Message::Message(string message) : _message(message) {

}

const string& Message::GetMessage() const {
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






