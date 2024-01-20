#pragma once

#include "pch.h"

// Contains the attributes for the data of the user.
class UserData {
public:
	std::string username = "\0";
	std::string names = "\0";
	std::string id = "\0";
	std::string address = "\0";
	std::string will = "\0";
};

// Contains the methods which validate the data of the user.
class Validate {
public:
	// Contains the data of the user with a specific will.
	const bool openWill(const std::string& password, UserData& userData) const;
	// Checks if the user has an existing will or not.
	const bool doesWillExist(const std::string& username, const std::string& password, const std::string& email) const;
    // Checks if the user has an existing account or not.
	const bool doesAccountExist(const std::string& targetUsername) const;
	// Checks if the inputted password corresponds to the user's username.
	const bool isPasswordCorrect(const std::string& targetUsername, const std::string& targetPassword) const;
	// Validates if the username meets the criteria.
	const bool validateUsername(const std::string& username) const;
	// Validates if the password key of the user's will meets the criteria and if it already exists in the database.
	const bool validateWillPassword(const std::string& password) const;
	// Validates if the account password of the user meets the criteria.
	const bool validateAccountPassword(const std::string& password) const;
	// Validates if the user's ID meets the criteria.
	const bool validateID(const std::string& id) const;
	// Validates if the user's first name, surname and last name meet the criteria.
	const bool validateName(const std::string& fullName) const;
	// Validates if the user's address meets the criteria.
	const bool validateAddress(const std::string& address) const;
	// Validates if the user's will email meets the criteria.
	const bool validateWillEmail(const std::string& email) const;
	// Validates if the user's account email meets the criteria and if it already exists in the database.
	const bool validateAccountEmail(const std::string& email) const;
	// Validates if the user's will meets the criteria.
	const bool validateWill(const std::string& will) const;
};