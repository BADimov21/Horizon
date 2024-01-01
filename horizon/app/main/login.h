#pragma once

#include "pch.h"

class User {
public:
	void getPassword(std::string& password) const;
	void existingUser(bool& checkUser, std::string& username, std::string& password) const;
	void newUser(std::string& username, std::string& password) const;
};

void login();