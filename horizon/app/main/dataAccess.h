#pragma once

#include <string>

class DataAccess {
public:
    bool doesUsernameExist(const std::string& targetUsername);
    void addAccount(const std::string& username, const std::string& password);
};
