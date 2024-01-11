#pragma once

#include "pch.h"

class DataAccess {
public:
    const bool doesAccountExist(const std::string& targetUsername) const;
    const bool isPasswordCorrect(const std::string& targetUsername, const std::string& targetPassword) const;
    void addAccount(const std::string& username, const std::string& password) const;
    void addDigitalWill(const std::string& password, const std::string& names, const std::string& id, const std::string& address, const std::string& username, const std::string& will) const;
};