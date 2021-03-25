#include "Utility.h"

bool IsStringNumber(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::string WrapPassword() {
	char ch;
	std::string pass = "";
#if defined(__linux__)
	getline(std::cin, pass);
#else
	while (true) {
		ch = _getch(); // get elements without printing them
		if (ch == 13)  // enter
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
#endif
	return pass;
}

void demo_perms(const fs::perms p) {
	std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
		<< '\n';
}