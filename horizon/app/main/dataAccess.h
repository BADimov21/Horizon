#pragma once

#include "pch.h"

// Contains the methods which access the database.
class DataAccess {
public:
    // Adds an account to the database "accounts".
    void addAccount(const std::string& username, const std::string& password, const std::string& email) const;
    // Adds a digital will to database "digitalWills".
    void addDigitalWill(const std::string& username, const std::string& password, const std::string& names, const std::string& id, const std::string& address, const std::string& will, const std::string& serialNumber, const std::string& email) const;
    // Adds an indication to check whether a user already has a will in the database or not.
    void addUserWill(const std::string& username, const std::string& password, const std::string& email) const;
};