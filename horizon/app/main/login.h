#pragma once

#include "pch.h"

// Contains the methods described in the login.cpp file.
class User {
public:
	// Stores a password input and it outputs "*" on the screen, in order to hide it.
	void getPassword(std::string& password) const;
	// Checks if an account already exists.
	void existingUser(bool& checkUser, std::string& username, std::string& password) const;
	// Stores and sends the data of a new user to the database.
	void newUser(std::string& username, std::string& password, std::string& email) const;
	// Shows what the user could do if there is something wrong with the application.
	void issues();
};

// Gives you an opportunity to create a new account or log in with an existing one.
void login();
// Shows the definitions linked with digital will making.
void learn();
// Gives you an opportunity to create a new will or to review an existing one. 
void digitalWill();