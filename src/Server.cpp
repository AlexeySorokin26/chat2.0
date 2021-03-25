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
		<< " - > to send message to all users - type: messageAll \n"
		<< " - > to show all users - type: show all \n"
		<< " - > to show messages of user - type: umessage \n"
		<< " - > to loginout from our server - type: logout \n"
		<< std::endl;
}

void Server::ShowOSInfo() const {

#if defined(__linux__)
	utsname us;
	uname(&us);
	std::cout << "OS name: " << utsname.sysname << std::endl;
	std::cout << "Host name: " << utsname.nodename << std::endl;
	std::cout << "OS release: " << utsname.release << std::endl;
	std::cout << "OS version: " << utsname.version << std::endl;
	std::cout << "Machine name: " << utsname.machine << std::endl;
#else
	OSVERSIONINFO osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);
	std::string res = "Windows ";
	if (osvi.dwMajorVersion == 10)
		res += "10";
	else if (osvi.dwMajorVersion == 6) {
		if (osvi.dwMinorVersion == 3)
			res += "8.1";
		else if (osvi.dwMinorVersion == 2)
			res += "8";
		else if (osvi.dwMinorVersion == 1)
			res += "7";
		else
			res += "Vista";
	}
	else if (osvi.dwMajorVersion == 5) {
		if (osvi.dwMinorVersion == 2)
			res += "XP SP2";
		else if (osvi.dwMinorVersion == 1)
			res += "XP";
	}
	std::cout << "OS name: " << res << std::endl;
#endif
}

void Server::ShowUser(const int id) {
	if (ValidId(id))
		_users[id].ShowInfo();
	else 
		std::cout << "we don't have such user with id: " << id << std::endl;
}

void Server::ShowAllUsers() {
	for (auto& u : _users)
		u.ShowInfo();
}

void Server::AddUser(const User& newUser) {
	_amountOfUsers++;
	_users.push_back(newUser);
}

// TODO: id
// probably better use json...
// and somehow add sha
void Server::AddUsersFromFile(const std::string serverDataFile) {
	// first load a file with history: line by line
	// Alexey - login;
	// Messages - his messages
	// format: Alexey |Message1 |Message2 
	// should contain registred users and their messages
	// our user class contains of std::vector<std::pair<int, Message>> _receivedMessages;
	// our server contains of std::vector<User> _users;
	std::ifstream server_file(serverDataFile);

	if (server_file.is_open()) {
		typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
		boost::char_separator<char> sep("|,;");

		std::string line;
		
		while (getline(server_file, line)) {
			User tmpUser;
			tokenizer tokens(line, sep);
			int counter = 0;
			for (auto it = tokens.begin(); it != tokens.end(); ++it) {
				if (counter == 0) {
					tmpUser.SetLogin(*it);
					counter++;
				}
				else if (counter == 1) {
					tmpUser.SetPassword(*it);
					counter++;
				}
				else {
					tmpUser.AddMessageWithId(std::make_pair(0, *it));
					counter++;
				}

			}
			_users.push_back(tmpUser);
			tmpUser.DeleteMessages();
		}
		User::TotalNumberOfUsers() = _users.size(); 
		_amountOfUsers = _users.size();
		server_file.close();
	}
}
// TODO: id 
void Server::AddUsersToFile(const std::string serverDataFile) {
	// we could have data in our file already
	// easier just delete all 
	// and then add all from server obj
	// we have static id that is a problem 
	std::ofstream server_file(serverDataFile, std::ios::trunc);
	if (server_file.is_open()) {
		for (int i = 0; i < _users.size(); ++i) {
			server_file << _users[i].GetLogin() << "|";
			server_file << _users[i].GetPassword() << "|";
			for (int j = 0; j < _users[i].GetMessages().size(); ++j) {
				server_file << _users[i].GetMessages()[j].second.GetMyMessage() << "|";
			}
			server_file << std::endl;
		}
		// before 
		//demo_perms(fs::status(serverDataFile).permissions());
#if defined(__linux__)
		std::filesystem::permissions(serverDataFile, 
			std::filesystem::perms::group_all | std::filesystem::perms::others_all,
			std::filesystem::perm_options::remove);
#else
		std::filesystem::permissions(serverDataFile, 
			fs::perms::owner_write | fs::perms::group_write,
			std::filesystem::perm_options::remove);
#endif
		//demo_perms(fs::status(serverDataFile).permissions());
		// after
		server_file.close();
	}
}

bool Server::PassUser(const std::string password, const std::string login) {
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
	else 
		std::cout << "we don't have such user with your id: "  << id << std::endl;
}

unsigned int Server::GetAmountOfUser() {
	return _amountOfUsers;
}

void Server::SendMyMessage(const int fromId, const int ToId, const std::string message) {
	if (ValidId(fromId) && ValidId(ToId))
		_users[ToId].AddMessageWithId(std::make_pair(fromId, message));
	else
		std::cout << "we could not send a message!" << std::endl;
}

void Server::SendMessageToAll(const int fromId, const std::string message) {
	if (ValidId(fromId)) {
		for (auto& u : _users) 
			if (u.Id() != fromId) // send message to all except yourself
				u.AddMessageWithId(std::make_pair(fromId, message));
	}
	else 
		std::cout << "we could not send a message!" << std::endl;
}

void Server::ShowUserMessages(const int id) {
	if (ValidId(id)) {
		std::cout << "messages of user with id: " << id << std::endl;
		_users[id].ShowMessages();
	}	
	else 
		std::cout << "your id is not valid!" << std::endl;
}

bool Server::ValidId(const int id) {
	if (id >= 0 && id <= _amountOfUsers && _amountOfUsers != 0)
		return true;
	return false;
}

bool Server::Loginned(const int id) {
	if (ValidId(id))  // if we have such id and user loggined
		return _users[id].GetLoggined();
	return false;
}

void Server::LoginUser(const std::string login) {
	// first we should find a user id with such login
	// next should set his _loggined to true
	for (auto& u : _users)
		if (u.GetLogin() == login)
			u.SetLoggined() = true;
}

void Server::Logout(const int id) {
	if (ValidId(id) && _users[id].GetLoggined())
		_users[id].SetLoggined() = false;
	else 
		std::cout << "your id is not valid!" << std::endl;
}

int Server::GetIdByLogin(const std::string login) {
	for (auto& u : _users)
		if (u.GetLogin() == login)
			return u.Id();
	return -1;
}
