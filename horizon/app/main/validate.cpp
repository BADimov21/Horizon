#include "validate.h"

// Checks if the user has an existing will or not.
const bool Validate::doesWillExist(const std::string& username, const std::string& password, const std::string& email) const {
    std::ifstream file("../data/accounts.csv");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string storedUsername, storedPassword, storedEmail, will;

        if (std::getline(iss, storedUsername, ',') &&
            std::getline(iss, storedPassword, ',') &&
            std::getline(iss, storedEmail, ',') &&
            std::getline(iss, will, ',')) {
            if (username == storedUsername && password == storedPassword && email == storedEmail) {
                if (will == "1") {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    return true;
}

// Validates if the username meets the criteria.
const bool Validate::validateUsername(const std::string& username) const {
    if (username.find(' ') != std::string::npos) {
        std::cout << "Username cannot contain spaces." << "\n";
        return false;
    }

    if (username.length() == 1) {
        std::cout << "Username cannot be a single character." << "\n";
        return false;
    }

    if (username.length() < 5) {
        std::cout << "Username must be at least 5 characters long." << "\n";
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

// Checks if the user has an existing account or not.
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
 
// Checks if the inputted password corresponds to the user's username.
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

// Checks if given password is already in the database.
static bool doesPasswordExist(const std::string& password) {
    std::ifstream file("../data/digitalWills.csv");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> columns;

        while (std::getline(iss, line, ',')) {
            columns.push_back(line);
        }

        if (columns.size() >= 2 && columns[1] == password) {
            std::cout << "Password already exists in the database." << "\n";
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Validates if the password key of the user's will meets the criteria and if it already exists in the database.
const bool Validate::validateWillPassword(const std::string& password) const {
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
    const std::string specialSymbols = "@#&$%*!";
    if (password.find_first_of(specialSymbols) == std::string::npos) {
        std::cout << "Your password is too weak. Include some of the enclosed special symbols: '@', '#', '&', '$', '%', '*', '!'." << "\n";
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

    if (doesPasswordExist(password)) {
        std::cout << "Error. Password already exists for a different digital will. Please choose a different password." << "\n";
        return false;
    }

    return true;
}

// Validates if the account password of the user meets the criteria.
const bool Validate::validateAccountPassword(const std::string& password) const {
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
    const std::string specialSymbols = "@#&$%*!";
    if (password.find_first_of(specialSymbols) == std::string::npos) {
        std::cout << "Your password is too weak. Include some of the enclosed special symbols: '@', '#', '&', '$', '%', '*', '!'." << "\n";
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

// Validates if the user's ID meets the criteria.
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

// Validates if the user's first name, surname and last name meet the criteria.
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

    bool hasNumericCharacter = false;
    for (char ch : fullName) {
        if (std::isdigit(ch)) {
            hasNumericCharacter = true;
            break;
        }
    }
    if (hasNumericCharacter) {
        std::cout << "Invalid name. Please only include letters." << std::endl;
        return false;
    }

    return true;
}

// Validates if the user's address meets the criteria.
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

// Contains the data of the user with a specific will.
const bool Validate::openWill(const std::string& password, UserData& userData) const {
    std::ifstream file("../data/digitalWills.csv");
    std::string line;
    bool passwordMatch = false;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> columns;

        while (std::getline(iss, line, ',')) {
            columns.push_back(line);
        }

        if (columns.size() >= 2 && columns[1] == password) {
            passwordMatch = true;

            if (columns.size() >= 6) {
                userData.username = columns[0];
                userData.names = columns[2];
                userData.id = columns[3];
                userData.address = columns[4];
                userData.will = columns[5];
            }
            break;
        }
    }

    file.close();
    return passwordMatch;
}

// Validates if the user's will email meets the criteria.
static bool doesEmailExist(const std::string& email) {
    std::ifstream file("../data/accounts.csv");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> columns;

        while (std::getline(iss, line, ',')) {
            columns.push_back(line);
        }

        if (columns.size() >= 3 && columns[2] == email) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Validates if the user's account email meets the criteria and if it already exists in the database.
const bool Validate::validateAccountEmail(const std::string& email) const {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);
    if (atPos == std::string::npos || atPos == 0 || atPos == email.length() - 1) {
        std::cout << "Your email is invalid." << "\n";
        return false;
    }

    if (dotPos == std::string::npos || dotPos == email.length() - 1) {
        std::cout << "Your email is invalid." << "\n";
        return false;
    }

    if (email.find(' ') != std::string::npos) {
        std::cout << "Your email cannot contain spaces." << "\n";
        return false;
    }

    if (doesEmailExist(email)) {
        std::cout << "Account with this email already exists. Please create an account with a different email or contact our team for assistance." << "\n";
        return false;
    }

    return true;
}

// Validates if the user's will email meets the criteria.
const bool Validate::validateWillEmail(const std::string& email) const {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);
    if (atPos == std::string::npos || atPos == 0 || atPos == email.length() - 1) {
        std::cout << "Your email is invalid." << "\n";
        return false;
    }

    if (dotPos == std::string::npos || dotPos == email.length() - 1) {
        std::cout << "Your email is invalid." << "\n";
        return false;
    }

    if (email.find(' ') != std::string::npos) {
        std::cout << "Your email cannot contain spaces." << "\n";
        return false;
    }

    return true;
}

// Validates if the user's will meets the criteria.
const bool Validate::validateWill(const std::string& will) const {
    if (will.empty()) {
        std::cout << "You must submit your will!" << "\n";
        return false;
    }
    return true;
}