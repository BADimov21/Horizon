#include "dataAccess.h"

// Adds an account to the database "accounts".
void DataAccess::addAccount(const std::string& username, const std::string& password, const std::string& email) const {
    std::ofstream file("../data/accounts.csv", std::ios_base::app);
    file << username << ',' << password << ',' << email << "\n";
    file.close();
}

// Adds a digital will to database "digitalWills".
void DataAccess::addDigitalWill(const std::string& username, const std::string& password, const std::string& names, const std::string& id, const std::string& address, const std::string& will, const std::string& serialNumber, const std::string& email) const {
    std::ofstream file("../data/digitalWills.csv", std::ios_base::app);
    file << username << ',' << password << ',' << names << ',' << id << ',' << address << ',' << will << ',' << serialNumber << ',' << email << "\n";
    file.close();
}

// Checks if a given user already exists.
static bool userExists(const std::string& username, const std::string& password, const std::string& email, const std::vector<std::string>& lines) {
    for (const auto& line : lines) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword, storedEmail;
        if (std::getline(iss, storedUsername, ',') &&
            std::getline(iss, storedPassword, ',') &&
            std::getline(iss, storedEmail, ',') &&
            storedUsername == username && storedPassword == password && storedEmail == email) {
            return true;
        }
    }
    return false;
}

// Adds an indication to check whether a user already has a will in the database or not.
void DataAccess::addUserWill(const std::string& username, const std::string& password, const std::string& email) const {
    std::fstream file("../data/accounts.csv", std::ios::in | std::ios::out);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    if (userExists(username, password, email, lines)) {
        file.clear();

        for (auto& line : lines) {
            std::istringstream iss(line);
            std::string storedUsername, storedPassword, storedEmail;
            if (std::getline(iss, storedUsername, ',') &&
                std::getline(iss, storedPassword, ',') &&
                std::getline(iss, storedEmail, ',') &&
                storedUsername == username && storedPassword == password && storedEmail == email) {
                line = storedUsername + ',' + storedPassword + ',' + storedEmail + ',' + "1";
                break;
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