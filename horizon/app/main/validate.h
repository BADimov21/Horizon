#pragma once

#include "pch.h"

class Validate {
public:
	const bool doesAccountExist(const std::string& targetUsername) const;
	const bool isPasswordCorrect(const std::string& targetUsername, const std::string& targetPassword) const;
	const bool validateUsername(const std::string& username) const;
	const bool validatePassword(const std::string& password) const;
	const bool validateID(const std::string& id) const;
	const bool validateName(const std::string& fullName) const;
	const bool validateAddress(const std::string& address) const;
};