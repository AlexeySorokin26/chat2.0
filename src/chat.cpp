#include <iostream>
#include "User.h"
#include "Message.h"
#include "Server.h"
#include <conio.h>


int main()
{
	// first load a file with history: line by line
	// Alexey - login;
	// Messages - his messages
	// format: Alexey |Message1 |Message2 
	// should contain registred users and their messages
	// our user class contains of std::vector<std::pair<int, Message>> _receivedMessages;
	// our server contains of std::vector<User> _users;	
	fstream server_file = fstream("server_file.txt", ios::in | ios::out);
	if (!server_file)
		// if we dont have such file then with trunc it will be created
		server_file = fstream("sever_info.txt", ios::in | ios::out | ios::trunc);

	Server server;

	if (server_file.is_open()) {
		std::vector<User> registredUsers;
		std::string line;
		while (getline(server_file, line)) {
			User tmpUser;
			tmpUser.SetLogin(line);
			registredUsers.push_back(tmpUser);
		}
	}
	else {

	}

	
	std::string command = ""; 
	server.Help(); // show how to use our server

	while (true) {
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Imput your command:" << std::endl;
		getline(std::cin, command);
		if (command == "0") {
			break;
		}	
		else if (command == "help") {
			server.Help();
		}
		else if (command == "new user"){
			User user;
			std::cout << "input your login: ";
			getline(std::cin, user.SetLogin());

			std::cout << "input your name: ";
			getline(std::cin, user.SetName());

			std::cout << "input your surname: ";
			getline(std::cin, user.SetSurname());

			std::cout << "input your age: ";
			getline(std::cin, user.SetAge());

			/* 
			std::cout << "input your password: ";
			getline(std::cin, user.SetPassword());
			*/
			char ch;
			std::string pass = "";
			std::cout << "input your pass: ";
			while (true) {
				ch = _getch(); // get elements without printing them
				if (ch == 13) // enter
					break;
				else if (ch == 8) { // backspace or delete previous element
					// need to move a cursor back 
					std::cout << (char)8 << ' ' << (char)8;
					// it is a console trick; if we put 8 of char than it's like a backspace
					// and delete one element (we use just ' ') from our pass and from a console 
					// and move back one more time
					if (!pass.empty())
						pass.erase(pass.size() - 1); // keep a string size of pass.size() - 1; other delete
				}
				else {
					std::cout << "*";
					pass = pass + ch;
				}
			}
			user.SetPassword(pass);
			server.AddUser(user);
			std::cout << std::endl;
		}
		else if (command == "show info") {
			std::cout << "which id should we show? input your id:";
			std::string id;
			getline(std::cin, id);
			server.ShowUser(stoi(id));
		}
		else if (command == "login") {
			//User user;
			
			std::string login;
			std::cout << "input your login:";
			getline(std::cin, login);

			std::string password;
			std::cout << "input you password:";
			getline(std::cin, password);

			if (server.PassUser(password, login)) {
				server.LoginUser(login);
				std::cout << "successful login!" << std::endl;
				std::cout << "all your messages:" << std::endl;
				server.ShowUserMessages(server.GetIdByLogin(login));
			}
			else {
				std::cout << "your data is not correct - > cannot login you" << std::endl;
			}
		}
		else if (command == "message") {
			std::cout << "input your id: "; 
			std::string fromId; 
			getline(std::cin, fromId);
			std::cout << "input a reciever id:";
			std::string toId;
			getline(std::cin, toId);
			std::cout << "input your message: ";
			std::string message;
			getline(std::cin, message);
			if (server.Loginned(stoi(fromId)))
				server.SendMessage(stoi(fromId), stoi(toId), message);
			else
				std::cout << "your should login first!" << std::endl;
		}
		else if (command == "show all") {
			server.ShowAllUsers();
		}
		else if (command == "umessage") {
			std::cout << "input an id of user to show:" << std::endl;
			std::string id; getline(std::cin, id);
			server.ShowUserMessages(stoi(id));
		}
		else if (command == "messageAll") {
			std::cout << "input your id: ";
			std::string fromId;
			getline(std::cin, fromId);
			std::cout << "input your message: ";
			std::string message;
			getline(std::cin, message);
			server.SendMessageToAll(stoi(fromId), message);
		}
		else if (command == "logout") {
			std::cout << "input your id: ";
			std::string id;
			getline(std::cin, id);
			server.Logout(stoi(id));
		}
   }
   
}

