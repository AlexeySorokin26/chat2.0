#pragma once

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

enum MY_SERVER_ERRORS {
    OK = 1,
    SOCKET_CREATION_FAULT = -1,
    SOCKET_BINDING_FAULT = -2,
    LISTEN_FAULT = -3,
    CANT_ACCEPT_DATA_FROM_CLIENT = -4,
    CANT_CONNECT_WITH_SERVER = -5
};
