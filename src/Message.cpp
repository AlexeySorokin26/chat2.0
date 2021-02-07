#include "Message.h"

Message::Message(std::string message) : _message(message) {

}

const std::string& Message::GetMessage() const {
	return _message;
}

std::ostream& operator<< (std::ostream& out, const Message& message) {
	std::cout << message.GetMessage() << std::endl;
	return out;
}
