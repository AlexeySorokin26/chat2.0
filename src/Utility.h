#include <iostream>
#include <string>
#include <filesystem>
#if defined(__linux__)
#include <stdio.h>
#else
#include <conio.h>
#endif 



namespace fs = std::filesystem;

bool IsStringNumber(const std::string& s);
std::string WrapPassword();
void demo_perms(const fs::perms p);

