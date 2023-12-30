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
    const int maxStars = 5;
    std::vector<Stars> stars;
    Vector2 position = Vector2{ 0, 0 };
    Vector2 size = Vector2{ 0, 0 };
    Color color = WHITE;
    float speed = 0;
};

void login();