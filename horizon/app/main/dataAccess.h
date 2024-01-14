#pragma once

#include "pch.h"

class DataAccess {
public:
    void addAccount(const std::string& username, const std::string& password) const;
    void addDigitalWill(const std::string& username, const std::string& password, const std::string& names, const std::string& id, const std::string& address, const std::string& will, const std::string& serialNumber) const;
    void addUserWill(const std::string& username, const std::string& password) const;
};