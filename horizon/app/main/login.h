#pragma once

#include "pch.h"

class User {
public:
	void getPassword(std::string& password);
	void existingUser(bool& checkUser, std::string& username, std::string& password);
	void newUser(std::string& username, std::string& password);
};

void login();