#include "dataAccess.h"

void DataAccess::addAccount(const std::string& username, const std::string& password) const {
    std::ofstream file("../data/accounts.csv", std::ios_base::app);
    file << username << ',' << password << "\n";
    file.close();
}

void DataAccess::addDigitalWill(const std::string& username, const std::string& password, const std::string& names, const std::string& id, const std::string& address, const std::string& will, const std::string& serialNumber) const {
    std::ofstream file("../data/digitalWills.csv", std::ios_base::app);
    file << username << ',' << password << ',' << names << ',' << id << ',' << address << ',' << will << ',' << serialNumber << "\n";
    file.close();
}

static bool userExists(const std::string& username, const std::string& password, std::vector<std::string>& lines) {
    for (const auto& line : lines) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword;
        if (std::getline(iss, storedUsername, ',') &&
            std::getline(iss, storedPassword, ',') &&
            storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}

void DataAccess::addUserWill(const std::string& username, const std::string& password) const {
    std::fstream file("../data/accounts.csv", std::ios::in | std::ios::out);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    if (userExists(username, password, lines)) {
        for (auto& line : lines) {
            std::istringstream iss(line);
            std::string storedUsername, storedPassword;
            if (std::getline(iss, storedUsername, ',') &&
                std::getline(iss, storedPassword, ',') &&
                storedUsername == username && storedPassword == password) {
                line = storedUsername + ',' + storedPassword + ',' + "1";
            }
        }
        file.close();
        file.open("../data/accounts.csv", std::ios::out | std::ios::trunc);
        for (const auto& modifiedLine : lines) {
            file << modifiedLine << '\n';
        }

        std::cout << "Your will has been added to your account: " << username << "\n";
    }
    else {
        std::cout << "User not found. Will has not been added." << "\n";
    }
    file.close();
}