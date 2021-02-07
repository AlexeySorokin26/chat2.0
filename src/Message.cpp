#include "Message.h"

Message::Message(std::string message) : _message(message) {

}

const std::string& Message::GetMessage() const {
	return _message;
}
