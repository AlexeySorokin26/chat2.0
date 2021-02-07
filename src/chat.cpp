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
		std::cout << "Imput your command:" << std::endl;
		getline(std::cin, command);
		if (command == "0")
			break;
		else if (command == "help")
			server.Help();
		else if (command == "new user"){
			User user;
			std::cout << "input your name: ";
			getline(std::cin, user.SetName());
			std::cout << "input your surname: ";
			getline(std::cin, user.SetSurname());
			std::cout << "input your age: ";
			getline(std::cin, user.SetAge());
			std::cout << "input your password: ";
			/* 
			char password[100];
			int i = 0;
			do {
				password[i] = getchar();
				if (password[i] != '\r')
					std::cout << "*";
				i++;
			} while (password[i - 1] != '\0');
			password[i - 1] = '\0';
			*/
			getline(std::cin, user.SetAge());
			server.AddUser(user);
		}
		else if (command == "show info") {
			server.ShowUser();
		}
   }
   
}

