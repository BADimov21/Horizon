#include "dataAccess.h"

const bool DataAccess::doesAccountExist(const std::string& targetUsername) const {
	std::ifstream file("../data/accounts.csv");
	std::string line;

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string storedUsername;

		if (std::getline(iss, storedUsername, ',')) {
			if (storedUsername == targetUsername) {
				return true;
			}
		}
	}
	return false;
}

const bool DataAccess::isPasswordCorrect(const std::string& targetUsername, const std::string& targetPassword) const {
    std::ifstream file("../data/accounts.csv");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword;

        if (std::getline(iss, storedUsername, ',') && std::getline(iss, storedPassword, ',')) {
            if (storedUsername == targetUsername && storedPassword == targetPassword) {
                return true;
            }
        }
    }
    return false;
}

void DataAccess::addAccount(const std::string& username, const std::string& password) const {
    std::ofstream file("../data/accounts.csv", std::ios_base::app);
    file << username << ',' << password << "\n";
}

void DataAccess::addDigitalWill(const std::string& password, const std::string& names, const std::string& id, const std::string& address, const std::string& username, const std::string& will) const {
    std::ofstream file("../data/digitalWills.csv", std::ios_base::app);
    file << password << ',' << names << ',' << id << ',' << address << ',' << username << ',' << will << "\n";
}