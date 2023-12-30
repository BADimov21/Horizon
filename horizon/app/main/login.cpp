#include "login.h"
#include "textures.h"
#include "dataAccess.h"

const void User::getPassword(std::string& password) const {
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

const void User::existingUser(bool& checkUser, std::string& username, std::string& password) const {
	DataAccess* account = new DataAccess();
	std::getline(std::cin, username);

	while (!checkUser) {
		std::cout << "Please enter your username: ";
		std::getline(std::cin, username);

		if (account->doesAccountExist(username)) {
			std::cout << "Hello, " << username << "!" << "\n";
			std::cout << "Please enter your password: ";
			getPassword(password);

			if (account->isPasswordCorrect(username, password)) {
				std::cout << "Welcome back, " << username << "!" << "\n";
				std::cout << "\n";
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


const void User::newUser(std::string& username, std::string& password) const {
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

static bool checkCollisionPointRec(Vector2 point, Rectangle rec) {
	return (point.x >= rec.x && point.x <= (rec.x + rec.width) &&
		point.y >= rec.y && point.y <= (rec.y + rec.height));
}

void login() {
    const int screenWidth = 1920;
	const int screenHeight = 975;

	Rectangle willButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 150, 270, 100 };
	Rectangle learnButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 20, 270, 100 };
	Rectangle exitButton = { (screenWidth / 2) - 110, (screenHeight / 2) + 110, 270, 100 };

    DataAccess* account = new DataAccess();
	User* user = new User();
	Stars* star = new Stars();

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

	Textures* texture = new Textures();

	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, screenWidth);
		star->position.y = (float)GetRandomValue(0, screenHeight);
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}

	bool exit = WindowShouldClose();

    while (!exit) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

		DrawTexture(texture->getResizedBackground(), 0, 0, WHITE);

		for (size_t i = 0; i < star->stars.size(); i++) {
			star->stars[i].position.y += star->stars[i].speed;

			if (star->stars[i].position.y > screenHeight) {
				star->stars[i].position.y = 0;
				star->stars[i].position.x = (float)GetRandomValue(0, screenWidth);
				star->stars[i].size.y = (float)GetRandomValue(10, 20);
				star->stars[i].size.x = (float)GetRandomValue(10, 20);
			}
			DrawTextureEx(texture->getStarTexture(), star->stars[i].position, 0, -0.1f, WHITE);
		}

		DrawText(("Welcome back, " + username + "!").c_str(), 100, 100, 40, RAYWHITE);
		DrawText("Your Dashboard", 100, 150, 30, RAYWHITE);

		DrawText("HORIZON", screenWidth / 2 - MeasureText("HORIZON", 40) / 2 - 10, screenHeight / 2 - 300, 50, BLACK);
		DrawText("Tomorrow is not certain, do it now!", screenWidth / 2 - MeasureText("Tomorrow is not certain, do it now!", 20) / 2 - 70, screenHeight / 2 - 250, 30, DARKGRAY);

		Vector2 mousePosition = GetMousePosition();
		bool isMouseOverButtonWill = checkCollisionPointRec(mousePosition, willButton);

		DrawRectangleRec(willButton, (isMouseOverButtonWill ? SKYBLUE : BLUE));
		DrawText("Digital Will", (screenWidth / 2) - 100, (screenHeight / 2) - 130, 50, BLACK);

		if (isMouseOverButtonWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			;
		}

		bool isMouseOverButtonLearn = checkCollisionPointRec(mousePosition, learnButton);

		DrawRectangleRec(learnButton, (isMouseOverButtonLearn ? LIME : GREEN));
		DrawText("Learn", (screenWidth / 2) - 50, (screenHeight / 2), 50, BLACK);

		if (isMouseOverButtonLearn && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			;
		}

		bool isMouseOverButtonExit = checkCollisionPointRec(mousePosition, exitButton);

		DrawRectangleRec(exitButton, (isMouseOverButtonExit ? PINK : RED));
		DrawText("Exit", (screenWidth / 2) - 20, (screenHeight / 2) + 130, 50, BLACK);

		if (isMouseOverButtonExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			exit = true;
		}

		DrawText("Created by Horizon | 2024 All rights reserved.", screenWidth / 2 - MeasureText("Created by Horizon | 2024 All rights reserved.", 20) / 2, screenHeight - 50, 20, RAYWHITE);

		DrawTexture(texture->getResizedLogo(), screenWidth - 190, screenHeight - 170, WHITE);

        EndDrawing();
    }

    CloseWindow();

	delete account;
	delete user;
	delete star;
	delete texture;
}