#include "Server.h"

Server::Server(unsigned int amountOfUsers) : _amountOfUsers(amountOfUsers) { }

void Server::Help() const {
	std::cout << "Help information about our server: \n"
		<< "to show how to use our server - input \"help\"\n"
		<< "to exit - input 0; \n"
		<< "to add a new user with login - input \"new user\"\n"
		<< "to login into our server - input \"login\"\n"
		<< "to send message - ; \n"
		<< "to show all users - ; \n"
		<< std::endl;
}

void Server::ShowUser(const int id) {
	if (id <= _amountOfUsers && id > 0)
		_users[id].ShowInfo();
}

void Server::AddUser(User newUser) {
	_amountOfUsers++;
	_users.push_back(newUser);
}

void Server::RemoveUserByID(const int id) {
	
	if(id <= _amountOfUsers && id > 0)
		_users.erase(_users.begin() + id);
	else {
		std::cout << "we don't have such user with your id: "  << id << std::endl;
	}
}

unsigned int Server::GetAmountOfUser() {
	return _amountOfUsers;
}

void Server::SendMessage(const int fromId, const int ToId, const std::string message) {
	_users[ToId].AddMessageWithId(std::make_pair(fromId, message));
}
