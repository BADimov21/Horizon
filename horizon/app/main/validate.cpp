#include "validate.h"

const bool Validate::validateUsername(const std::string& username) const {
    if (username.length() == 1) {
        std::cout << "Username cannot be a single character." << "\n";
        return false;
    }

    if (username.length() < 5) {
        std::cout << "Username must be at least 5 characters long." << "\n";
        return false;
    }

    if (username.find(' ') != std::string::npos) {
        std::cout << "Username cannot contain spaces." << "\n";
        return false;
    }

    bool onlyNumbers = true;
    for (char ch : username) {
        if (!std::isdigit(ch)) {
            onlyNumbers = false;
            break;
        }
    }
    if (onlyNumbers) {
        std::cout << "Username cannot consist only of numbers." << "\n";
        return false;
    }

    return true;
}

const bool Validate::doesAccountExist(const std::string& targetUsername) const {
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

const bool Validate::isPasswordCorrect(const std::string& targetUsername, const std::string& targetPassword) const {
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

const bool Validate::validatePassword(const std::string& password) const {
    if (password.length() < 8) {
        std::cout << "Password must be at least 8 characters long." << "\n";
        return false;
    }
    if (password.find(' ') != std::string::npos) {
        std::cout << "Password cannot contain spaces." << "\n";
        return false;
    }
    if (std::all_of(password.begin(), password.end(), ::isdigit)) {
        std::cout << "Password cannot consist only of numbers." << "\n";
        return false;
    }
    if (std::all_of(password.begin(), password.end(), ::isalpha)) {
        std::cout << "Password cannot consist only of letters." << "\n";
        return false;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;

    for (char ch : password) {
        if (std::isupper(ch)) {
            hasUppercase = true;
        }
        else if (std::islower(ch)) {
            hasLowercase = true;
        }
        else if (std::isdigit(ch)) {
            hasDigit = true;
        }
    }

    if (!hasUppercase || !hasLowercase || !hasDigit) {
        std::cout << "Password must have at least one uppercase letter, one lowercase letter, and one digit." << "\n";
        return false;
    }

    return true;
}

const bool Validate::validateID(const std::string& id) const {
    for (char ch : id) {
        if (!std::isdigit(ch)) {
            std::cout << "Invalid ID. Please make sure it contains only numeric characters." << std::endl;
            return false;
        }
    }

    if (id.length() != 10) {
        std::cout << "Invalid ID. Please make sure it has exactly 10 characters." << std::endl;
        return false;
    }

    if (id.find(' ') != std::string::npos) {
        std::cout << "Your personal identification number cannot contain spaces." << "\n";
        return false;
    }

    return true;
}

const bool Validate::validateName(const std::string& fullName) const {
    std::istringstream iss(fullName);
    std::string firstName, surname, lastName;

    iss >> firstName >> surname >> lastName;

    size_t spaceCount = std::count(fullName.begin(), fullName.end(), ' ');

    if (spaceCount < 2) {
        std::cout << "You must enter your first name, surname and last name." << std::endl;
        return false;
    }

    if (firstName.length() < 2 || surname.length() < 2 || lastName.length() < 2) {
        std::cout << "Too few characters. Be sure you have entered your names correctly!" << std::endl;
        return false;
    }

    return true;
}

const bool Validate::validateAddress(const std::string& address) const {
	if (address.empty()) {
		std::cout << "Invalid address. Please enter a non-empty address." << std::endl;
		return false;
	}

    size_t spaceCount = std::count(address.begin(), address.end(), ' ');

    if (spaceCount < 2) {
        std::cout << "Invalid address. You must enter your full address." << std::endl;
        return false;
    }

	bool hasNumericCharacter = false;
	for (char ch : address) {
		if (std::isdigit(ch)) {
			hasNumericCharacter = true;
			break;
		}
	}
	if (!hasNumericCharacter) {
		std::cout << "Invalid address. Please include at least one numeric character." << std::endl;
		return false;
	}

	return true;
}

