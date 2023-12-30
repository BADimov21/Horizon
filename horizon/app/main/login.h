#pragma once

#include "pch.h"

class User {
public:
	const void getPassword(std::string& password) const;
	const void existingUser(bool& checkUser, std::string& username, std::string& password) const;
	const void newUser(std::string& username, std::string& password) const;
};

void login();