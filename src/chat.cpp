#include <iostream>
#include "User.h"
#include "Message.h"
#include "Server.h"


int main()
{
	Server server;
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

			std::cout << "input your password: ";
			getline(std::cin, user.SetPassword());

			server.AddUser(user);
		}
		else if (command == "show info") {
			std::cout << "which id should we show? input your id:";
			std::string id;
			getline(std::cin, id);
			server.ShowUser(stoi(id));
		}
		else if (command == "login") {
			User user;
			
			std::cout << "input your login:";
			getline(std::cin, user.SetLogin());

			std::cout << "input you password:";
			getline(std::cin, user.SetPassword());

			if (server.LoginUser(user.GetPassword(), user.GetLogin())) {
				server.LogginUser(user.GetLogin());
				std::cout << "successful login!" << std::endl;
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
			std::cout << "inpud an id of user to show:" << std::endl;
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

