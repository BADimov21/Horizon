#include <iostream>
#include <fstream>
#include <sstream>
#include "dataAccess.h"

bool DataAccess::doesUsernameExist(const std::string& targetUsername) {
	std::ifstream file("../data/accounts.csv");
	std::string line;

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string storedUsername;

		if (std::getline(iss, storedUsername, ',')) {
			if (storedUsername == targetUsername) {
				std::cout << "Username found: " << storedUsername << std::endl;
				return true;
			}
		}
	}

	return false;
}

void DataAccess::addAccount(const std::string& username, const std::string& password) {
    std::ofstream file("../data/accounts.csv", std::ios_base::app);
    file << username << ',' << password << "\n";
}