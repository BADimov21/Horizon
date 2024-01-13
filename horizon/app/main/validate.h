#pragma once

#include "pch.h"

class UserData {
public:
	std::string username = "\0";
	std::string names = "\0";
	std::string id = "\0";
	std::string address = "\0";
	std::string will = "\0";
};

class Validate {
public:
	const bool openWill(const std::string& password, UserData& userData) const;
	const bool doesWillExist(const std::string& username, const std::string& password) const;
	const bool doesAccountExist(const std::string& targetUsername) const;
	const bool isPasswordCorrect(const std::string& targetUsername, const std::string& targetPassword) const;
	const bool validateUsername(const std::string& username) const;
	const bool validatePassword(const std::string& password) const;
	const bool validateID(const std::string& id) const;
	const bool validateName(const std::string& fullName) const;
	const bool validateAddress(const std::string& address) const;
};