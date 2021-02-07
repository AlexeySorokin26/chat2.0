#include "Server.h"

Server::Server(unsigned int amountOfUsers) : _amountOfUsers(amountOfUsers) { }

void Server::Help() const {
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Help information about our server: \n"
		<< " - > to show how to use our server - type: \"help\"\n"
		<< " - > to exit - input 0 \n"
		<< " - > to add a new user with login - type: \"new user\"\n"
		<< " - > to login into our server - type: \"login\"\n"
		<< " - > to show information about some user - type: \"show info\"\n"
		<< " - > to send message - type: message \n"
		<< " - > to show all users - type: show all \n"
		<< " - > to show messages of user - type: umessage \n"
		<< std::endl;
}

void Server::ShowUser(const int id) {
	if (ValidId(id))
		_users[id].ShowInfo();
	else {
		std::cout << "we don't have such user with id: " << id << std::endl;
	}
}

void Server::ShowAllUsers() {
	for (auto& u : _users)
		u.ShowInfo();
}

void Server::AddUser(const User& newUser) {
	_amountOfUsers++;
	_users.push_back(newUser);
}

bool Server::LoginUser(const std::string password, const std::string login) {
	// first we should check if we have such user with a given login
	// second we should check his/her inputted password
	bool checkerLogin = false;
	bool checkerPassword = false;
	for (auto& u : _users) 
		if (login == u.GetLogin()){
			checkerLogin = true;
			if (password == u.GetPassword()) {
				checkerPassword = true;
			}
			break;
		}
	return (checkerLogin && checkerPassword);
}

void Server::RemoveUserByID(const int id) {
	
	if(ValidId(id))
		_users.erase(_users.begin() + id);
	else {
		std::cout << "we don't have such user with your id: "  << id << std::endl;
	}
}

unsigned int Server::GetAmountOfUser() {
	return _amountOfUsers;
}

void Server::SendMessage(const int fromId, const int ToId, const std::string message) {
	if (ValidId(fromId), ValidId(ToId))
		_users[ToId].AddMessageWithId(std::make_pair(fromId, message));
	else
		std::cout << "we could not send a message!" << std::endl;
}

void Server::ShowUserMessages(const int id) {
	if (ValidId(id)) {
		std::cout << "messages of user with id: " << id << std::endl;
		_users[id].ShowMessages();
	}	
}

bool Server::ValidId(const int id) {
	if (id >= 0 && id <= _amountOfUsers && _amountOfUsers != 0)
		return true;
	return false;
}
