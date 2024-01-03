#include "login.h"
#include "layout.h"
#include "textures.h"
#include "dataAccess.h"

void User::getPassword(std::string& password) const {
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

void User::existingUser(bool& checkUser, std::string& username, std::string& password) const {
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


void User::newUser(std::string& username, std::string& password) const {
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

void User::issues() {
	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	const Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, GetScreenWidth());
		star->position.y = (float)GetRandomValue(0, GetScreenHeight());
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}

	while (!WindowShouldClose()) {
		mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTexture(texture->getResizedBackground(), 0, 0, WHITE);

		for (size_t i = 0; i < star->stars.size(); i++) {
			star->stars[i].position.y += star->stars[i].speed;

			if (star->stars[i].position.y > GetScreenHeight()) {
				star->stars[i].position.y = 0;
				star->stars[i].position.x = (float)GetRandomValue(0, GetScreenWidth());
				star->stars[i].size.y = (float)GetRandomValue(10, 20);
				star->stars[i].size.x = (float)GetRandomValue(10, 20);
			}
			DrawTextureEx(texture->getStarTexture(), star->stars[i].position, 0, -0.1f, WHITE);
		}

		DrawTextEx(customFont, "Press ESC key to go back.", Vector2{ (float)(GetScreenWidth() / 2) - 900, (float)(GetScreenHeight() / 2) + 400 }, 25, 1, WHITE);

		DrawTextEx(customFont, "Issues with the application", Vector2{ (float)(GetScreenWidth() / 2) - 220, (float)(GetScreenHeight() / 2) - 300 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Encountering any issues? Reach out to our dedicated support team for assistance!", Vector2{ (float)(GetScreenWidth() / 2) - 580, (float)(GetScreenHeight() / 2) - 150 }, 35, 1, WHITE);
		DrawTextEx(customFont, "You can email our Scrum Trainer at FHPopova21@codingburgas.bg or submit your concerns directly on our GitHub repository at", Vector2{ (float)(GetScreenWidth() / 2) - 880, (float)(GetScreenHeight() / 2) - 100 }, 35, 1, WHITE);
		DrawTextEx(customFont, "at https://github.com/BADimov21/Horizon, in our 'Discussions' tab. We're here to help ensure a smooth experience for you! ", Vector2{ (float)(GetScreenWidth() / 2) - 850, (float)(GetScreenHeight() / 2) - 50 }, 35, 1, WHITE);

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}
}

static bool checkCollisionPointRec(const Vector2 point, const Rectangle rec) {
	return (point.x >= rec.x && point.x <= (rec.x + rec.width) &&
		point.y >= rec.y && point.y <= (rec.y + rec.height));
}

static bool checkTextClick(const char* text, Font font, int fontSize, float posX, float posY, Color textColor, Color highlightColor) {
	float textWidth = MeasureTextEx(font, text, (float)fontSize, 0).x;
	const Vector2 textPosition = { posX, posY };
	const Rectangle textBounds = { textPosition.x, textPosition.y, textWidth, (float)fontSize };
	bool mouseOver = CheckCollisionPointRec(GetMousePosition(), textBounds);
	DrawTextEx(font, text, textPosition, static_cast<float>(fontSize), 0, mouseOver ? highlightColor : textColor);
	return mouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void login() {
	const int screenWidth = 1920;
	const int screenHeight = 975;

	DataAccess* account = new DataAccess();
	User* user = new User();
	Stars* star = new Stars();

	std::string username;
	std::string password;

	const Rectangle willButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 150, 270, 100 };
	const Rectangle learnButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 20, 270, 100 };
	const Rectangle exitButton = { (screenWidth / 2) - 110, (screenHeight / 2) + 110, 270, 100 };

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

	HideCursor();

	Textures* texture = new Textures();
	Images* image = new Images();

	SetWindowIcon(image->getLogo());

	const Font customFont = LoadFont("../assets/fonts/roboto.ttf");

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

		DrawTextEx(customFont, ("Welcome back, " + username + "!").c_str(), Vector2{ 100, 100 }, 50, 1, RAYWHITE);
		DrawTextEx(customFont, "Your Dashboard", Vector2{ 105, 150 }, 40, 1, RAYWHITE);

		DrawTextEx(customFont, "HORIZON", Vector2{ (float)screenWidth / 2 - MeasureText("HORIZON", 40) / 2 - 10, screenHeight / 2 - 300 }, 50, 10, RAYWHITE);
		DrawTextEx(customFont, "Tomorrow is not certain, do it now!", Vector2{ (float)screenWidth / 2 - MeasureText("Tomorrow is not certain, do it now!", 20) / 2 - 70, screenHeight / 2 - 250 }, 40, 1, RAYWHITE);
		DrawTextEx(customFont, "Encountering any issues?", Vector2{ (float)screenWidth - 400, (float)screenHeight / 2 - 375 }, 30, 1, WHITE);
		if (checkTextClick("Click here.", customFont, 30, screenWidth - 300, screenHeight / 2 - 340, RAYWHITE, GREEN)) {
			user->issues();
		}

		Vector2 mousePosition = GetMousePosition();
		bool isMouseOverButtonWill = checkCollisionPointRec(mousePosition, willButton);

		DrawRectangleRec(willButton, (isMouseOverButtonWill ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "Digital Will", Vector2{ (screenWidth / 2) - 75, (screenHeight / 2) - 130 }, 50, 1, BLACK);

		if (isMouseOverButtonWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			;
		}

		bool isMouseOverButtonLearn = checkCollisionPointRec(mousePosition, learnButton);

		DrawRectangleRec(learnButton, (isMouseOverButtonLearn ? GREEN : LIME));
		DrawTextEx(customFont, "Learn", Vector2{ (screenWidth / 2) - 25, (screenHeight / 2) }, 50, 1, BLACK);

		if (isMouseOverButtonLearn && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			learn();
		}

		bool isMouseOverButtonExit = checkCollisionPointRec(mousePosition, exitButton);

		DrawRectangleRec(exitButton, (isMouseOverButtonExit ? PINK : RED));
		DrawTextEx(customFont, "Exit", Vector2{ (screenWidth / 2) - 5, (screenHeight / 2) + 130 }, 50, 1, BLACK);

		if (isMouseOverButtonExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			exit = true;
		}

		DrawText("Created by Horizon | 2024 All rights reserved.", screenWidth / 2 - MeasureText("Created by Horizon | 2024 All rights reserved.", 20) / 2, screenHeight - 50, 20, RAYWHITE);

		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	CloseWindow();

	delete account;
	delete user;
	delete star;
	delete texture;
	delete image;
}