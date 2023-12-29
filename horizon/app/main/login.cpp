#include "pch.h"
#include "login.h"
#include "dataAccess.h"

void User::getPassword(std::string& password) {
	password.clear();
	char ch;
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (!password.empty()) {
				std::cout << "\b \b";
				password.pop_back();
			}
		}
		else {
			password += ch;
			std::cout << "*";
		}
	}
	std::cout << '\n';
}

void User::existingUser(bool& checkUser, std::string& username, std::string& password) {
	DataAccess* account = new DataAccess();
	std::getline(std::cin, username);

	while (!checkUser) {
		std::cout << "Please enter your username: ";
		std::getline(std::cin, username);

		if (account->doesAccountExist(username)) {
			std::cout << "USERNAME: " << username << "\n";
			std::cout << "Please enter your password: " << "\n";
			getPassword(password);

			if (account->isPasswordCorrect(username, password)) {
				std::cout << "Welcome, " << username << "!" << "\n";
				checkUser = true;
			}
			else {
				std::cout << "Wrong password! Please try again!" << "\n";
				std::cout << "\n";
			}
		}
		else {
			std::cout << "This user does not exist. Please try again or create a new account!" << "\n";
			std::cout << "\n";
		}
	}
	delete account;
}


void User::newUser(std::string& username, std::string& password) {
	DataAccess* account = new DataAccess();
	bool check = false;

	std::cout << "Thank you for choosing 'Horizon'! Let's start with your registration! " << "\n";

	while (!check) {
		std::cout << "Enter your desired username: ";
		std::cin >> username;

		if (account->doesAccountExist(username)) {
			std::cout << "Account already exists. Please try again with a different username!" << "\n";
		}
		else {
			std::cout << "\n";
			std::cout << "Enter your desired password: ";
			getPassword(password);

			account->addAccount(username, password);
			std::cout << "Thank you, " << username << "! Make sure to keep your credentials safe!" << "\n";
			std::cout << "\n";
			check = true;
		}
	}
	delete account;
}

void login() {
    const int screenWidth = 1920;
	const int screenHeight = 975;

    DataAccess* account = new DataAccess();
	User* user = new User();

	std::string username;
	std::string password;

	bool checkUser = false;
	bool validChoice = false;
    char choice;

    std::cout << "Welcome to Horizon!" << "\n";
	std::cout << "Tomorrow is not certain, do it now!" << "\n";
	std::cout << "With the service of our company - 'Horizon'!" << "\n";
    std::cout << "Do you have an account (A) or would you like to create one (B)? (A / B)" << "\n";
	std::cin.get(choice);

	while (!validChoice) {
		switch (choice) {
		case 'A':
			user->existingUser(checkUser, username, password);
			validChoice = true;
			break;

		case 'B':
			user->newUser(username, password);
			validChoice = true;
			break;

		default:
			std::cout << "The operation you chose is not available. Please choose from the ones mentioned!" << "\n";
			std::cout << "\n";
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cin.get(choice);
			break;
		}
	}

    InitWindow(screenWidth, screenHeight, "Horizon");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

	delete account;
	delete user;
}