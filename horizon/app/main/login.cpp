#include "pch.h"
#include "login.h"
#include "dataAccess.h"

void existingUser(bool checkUser, std::string& username, std::string& password) {
	DataAccess* account = new DataAccess();
	std::getline(std::cin, username);
	while (!checkUser) {
		std::cout << "Please enter your username: ";
		std::getline(std::cin, username);
		if (account->doesAccountExist(username)) {
			std::cout << "USERNAME: " << username << "\n";
			std::cout << "Please enter your password: ";
			std::cout << "\n";

			std::getline(std::cin, password);

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

void newUser(std::string& username, std::string& password) {
	DataAccess* account = new DataAccess();
	bool check = false;

	std::cout << "Thank you for choosing 'Horizon'! Let's start with your registration! " << "\n";

	while (!check) {
		std::cout << "Enter your desired username: ";
		std::cin >> username;

		if (account->doesAccountExist(username)) {
			std::cout << "Account already exists. Please try again with a different username!\n";
		}
		else {
			std::cout << "\n";
			std::cout << "Enter your desired password: ";
			std::cin >> password;

			account->addAccount(username, password);
			std::cout << "Thank you, " << username << "! Make sure to keep your credentials safe!\n";
			check = true;
		}
	}
	delete account;
}

void login() {
    const int screenWidth = 1920;
	const int screenHeight = 975;

    DataAccess* account = new DataAccess();
	std::string username;
	std::string password;

    char choice;
    bool checkUser = false;
	bool validChoice = false;

    std::cout << "Welcome to Horizon!" << "\n";
    std::cout << "Do you have an account (A) or would you like to create one (B)? (A / B)";

	std::cin.get(choice);

	while (!validChoice) {
		switch (choice) {
		case 'A':
			existingUser(checkUser, username, password);
			validChoice = true;
			break;
		case 'B':
			newUser(username, password);
			validChoice = true;
			break;
		default:
			std::cout << "The operation you chose is not available. Please choose from the ones mentioned!\n";
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
}