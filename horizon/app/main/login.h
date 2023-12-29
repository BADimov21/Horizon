#pragma once

#include "pch.h"

class User {
public:
	const void getPassword(std::string& password) const;
	const void existingUser(bool& checkUser, std::string& username, std::string& password) const;
	const void newUser(std::string& username, std::string& password) const;
};

class Stars {
public:
    Vector2 position;
    Vector2 size;
    Color color;
    float speed;
};

void login();