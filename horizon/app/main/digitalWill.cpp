#include "login.h"
#include "layout.h"
#include "textures.h"
#include "validate.h"
#include "dataAccess.h"

// Random number generator.
static std::string serialNumber() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<long long> dis(1000000000, 9999999999);
	return std::to_string(dis(gen));
}

// Opens the window in which the user makes their will.
static void newWill() {
	DataAccess* process = new DataAccess();
	Validate* validator = new Validate();
	User* user = new User();
	Textures* texture = new Textures();
	Stars* star = new Stars();

	std::string willPassword, accountPassword, names, id, address, username, will, email, random = serialNumber();

	Vector2 mousePosition = GetMousePosition();
	const Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	bool showWill = false;

	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, GetScreenWidth());
		star->position.y = (float)GetRandomValue(0, GetScreenHeight());
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}

	// Making a will sequence and logic.
	system("cls");
	std::cout << "Horizon - Your Digital Will Company" << "\n";
	std::cout << "Your Digital Will Making Process:" << "\n";
	std::cout << "Note: If you have not read the instructions in the application about how to make your digital will, please read them and be in the know about the whole process itself before making your digital will with the help of Horizon!";
	std::cout << "\n";
	std::cout << "You must keep your digital will secure!" << "\n";
	std::cout << "You have to think of a password to which only you have access." << "\n";
	std::cout << "Enter your desired password: ";
	std::getline(std::cin, willPassword);
	while (!validator->validateWillPassword(willPassword)) {
		std::cout << "Enter your desired password: ";
		std::getline(std::cin, willPassword);
	}
	std::cout << "\n";
	std::cout << "Enter your first name, surname and last name: ";
	std::getline(std::cin, names);
	std::cout << "\n";
	while (!validator->validateName(names)) {
		std::cout << "Enter your your first name, surname and last name: ";
		std::getline(std::cin, names);
	}
	std::cout << "Enter your personal identification number: ";
	std::getline(std::cin, id);
	std::cout << "\n";
	while (!validator->validateID(id)) {
		std::cout << "Enter your personal identification number: ";
		std::getline(std::cin, id);
	}
	std::cout << "Enter your address: ";
	std::getline(std::cin, address);
	std::cout << "\n";
	while (!validator->validateAddress(address)) {
		std::cout << "Enter your address: ";
		std::getline(std::cin, address);
	}
	std::cout << "Enter your email address: ";
	std::getline(std::cin, email);
	std::cout << "\n";
	while (!validator->validateWillEmail(email)) {
		std::cout << "Enter your email address: ";
		std::getline(std::cin, email);
	}
	std::cout << "Enter your username: ";
	std::getline(std::cin, username);
	while (!validator->doesAccountExist(username)) {
		std::cout << "This account doesn't exist. Please enter your username correctly: ";
		std::getline(std::cin, username);
	}
	std::cout << "Enter the password of your account: ";
	user->getPassword(accountPassword);
	while (!validator->isPasswordCorrect(username, accountPassword)) {
		std::cout << "Incorrect password. Please try again: ";
		user->getPassword(accountPassword);
	}
	if (validator->doesWillExist(username, accountPassword, email)) {
		std::cout << "\n";
		std::cout << "This account has already submitted their will in Horizon's database." << "\n";
	}
	else {
		std::cout << "\n";
		std::cout << "You have entered all of your personal data. Thank you for your cooperation and trusting Horizon! Now you must write your will.";
		std::cout << "\n";
		std::getline(std::cin, will);
		while (!validator->validateWill(will)) {
			std::getline(std::cin, will);
		}
		std::cout << "\n";
		std::cout << "Your will has successfully been submitted! Thank you one more time for trusting Horizon!";
		std::cout << "\n";
		std::cout << "Important! This is the serial number of your digital will: " << random << "." << "\n";
		std::cout << "If you have any questions regarding your digital will, you want to delete it or edit it and etc., send us an email proving your identity and enclosing the code of your will for further assistance." << "\n";
		process->addUserWill(username, accountPassword, email);
		process->addDigitalWill(username, willPassword, names, id, address, will, random, email);
	}

	while (!WindowShouldClose()) {
		mousePosition = GetMousePosition();

		BeginDrawing();
		SetExitKey(KEY_ESCAPE);
		ClearBackground(RAYWHITE);

		DrawTexture(texture->getResizedNewWillBackground(), 0, 0, WHITE);

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

		DrawRectangleLines(300, 85, 1280, 820, BLACK);
		DrawTextEx(customFont, "HORIZON", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("HORIZON", 40) / 2 - 20, (float)GetScreenHeight() / 2 - 470 }, 50, 10, BLACK);
		DrawTextEx(customFont, "Your digital will is in our database. You can see it here.", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Your digital will is in our database. You can see it here.", 20) / 2 - 130, (float)GetScreenHeight() / 2 - 400 }, 40, 1, BLACK);
		DrawTextEx(customFont, "Full name:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Full Name:", 40) / 2 - 470, (float)GetScreenHeight() / 2 - 300 }, 30, 1, BLACK);
		DrawTextEx(customFont, names.c_str(), Vector2{ (float)GetScreenWidth() / 2 - MeasureText(names.c_str(), 40) / 2 - 130, (float)GetScreenHeight() / 2 - 300 }, 30, 1, BLACK);
		DrawTextEx(customFont, "Personal ID:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Personal ID : ", 40) / 2 - 430, (float)GetScreenHeight() / 2 - 200 }, 30, 1, BLACK);
		DrawTextEx(customFont, id.c_str(), Vector2{ (float)GetScreenWidth() / 2 - MeasureText(id.c_str(), 40) / 2 - 230, (float)GetScreenHeight() / 2 - 200 }, 30, 1, BLACK);
		DrawTextEx(customFont, "Address:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Address:", 40) / 2 - 480, (float)GetScreenHeight() / 2 - 100 }, 30, 1, BLACK);
		DrawTextEx(customFont, address.c_str(), Vector2{ (float)GetScreenWidth() / 2 - MeasureText(address.c_str(), 40) / 2 - 110 , (float)GetScreenHeight() / 2 - 100 }, 30, 1, BLACK);
		DrawTextEx(customFont, "Username:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Username:", 40) / 2 - 470, (float)GetScreenHeight() / 2 }, 30, 1, BLACK);
		DrawTextEx(customFont, username.c_str(), Vector2{ (float)GetScreenWidth() / 2 - MeasureText(username.c_str(), 40) / 2 - 247, (float)GetScreenHeight() / 2 }, 30, 1, BLACK);
		DrawTextEx(customFont, "Will: Your will is encrypted! You can take a look at it in the console of the Horizon application!", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Your will is encrypted! You can take a look at it in the console of the Horizon application!", 40) / 2 + 350, (float)GetScreenHeight() / 2 + 100 }, 30, 1, BLACK);
		if (!showWill) {
			system("cls");
			std::cout << "\n";
			std::cout << username << "'s digital will in Horizon's database:" << "\n";
			std::cout << will << "\n";
		}
		showWill = true;

		DrawTextEx(customFont, "Press ESC key to go back.", Vector2{ (float)(GetScreenWidth() / 2) - 920, (float)(GetScreenHeight() / 2) + 420 }, 25, 1, BLACK);

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete process;
	delete validator;
	delete user;
	delete texture;
	delete star;
}

// Opens the will which the user has made for review.
static void reviewWill() {
	Validate* validator = new Validate();
	UserData* data = new UserData();
	Textures* texture = new Textures();
	Stars* star = new Stars();
	UserData user;

	Vector2 mousePosition = GetMousePosition();
	const Rectangle textBox = { (float)GetScreenWidth() / 2 - 290, (float)GetScreenHeight() / 2 - 300, 600, 50 };
	const Font customFont = LoadFont("../assets/fonts/roboto.ttf");

	char password[30] = "\0";
	int letterCount = 0;
	int framesCounter = 0;
	bool mouseOnText = false;
	bool displayInfo = false;
	bool passwordBox = true;
	bool showWill = false;

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

		// Password input logic.
		if (CheckCollisionPointRec(mousePosition, textBox)) {
			mouseOnText = true;
		}
		else {
			mouseOnText = false;
		}

		if (mouseOnText) {
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			int key = GetCharPressed();

			while (key > 0) {
				if ((key >= 32) && (key <= 125) && (letterCount < 30)) {
					password[letterCount] = (char)key;
					password[letterCount + 1] = '\0';
					letterCount++;
				}
				key = GetCharPressed();
			}

			if (IsKeyPressed(KEY_BACKSPACE)) {
				letterCount--;
				if (letterCount < 0) {
					letterCount = 0;
				}
				password[letterCount] = '\0';
			}
		}
		else {
			SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		}
		if (mouseOnText) {
			framesCounter++;
		}
		else {
			framesCounter = 0;
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

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
		if (passwordBox) {
			DrawTextEx(customFont, "Enter your digital will's password here:", Vector2{ (float)(GetScreenWidth() / 2) - 340, (float)(GetScreenHeight() / 2) - 400 }, 50, 1, BLACK);
			DrawRectangleRec(textBox, RAYWHITE);

			if (mouseOnText) {
				DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
			}
			else {
				DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);
			}

			DrawTextEx(customFont, password, Vector2{ (float)textBox.x + 5, (float)textBox.y + 8 }, 40, 1, MAROON);
		}
		if (IsKeyPressed(KEY_ENTER)) {
			if (validator->openWill(password, user)) {
				displayInfo = true;
				passwordBox = false;
			}
		}
		if (displayInfo) {
			DrawRectangleLines(300, 85, 1280, 760, BLACK);
			DrawTextEx(customFont, "HORIZON", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("HORIZON", 40) / 2 - 20, (float)GetScreenHeight() / 2 - 470 }, 50, 10, BLACK);
			DrawTextEx(customFont, "Your digital will is in our database. You can see it here.", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Your digital will is in our database. You can see it here.", 20) / 2 - 130, (float)GetScreenHeight() / 2 - 400 }, 40, 1, BLACK);
			DrawTextEx(customFont, "Full name:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Full Name:", 40) / 2 - 470, (float)GetScreenHeight() / 2 - 300 }, 30, 1, BLACK);
			DrawTextEx(customFont, user.names.c_str(), Vector2{ (float)GetScreenWidth() / 2 - MeasureText(user.names.c_str(), 40) / 2 - 130, (float)GetScreenHeight() / 2 - 300 }, 30, 1, BLACK);
			DrawTextEx(customFont, "Personal ID:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Personal ID : ", 40) / 2 - 430, (float)GetScreenHeight() / 2 - 200 }, 30, 1, BLACK);
			DrawTextEx(customFont, user.id.c_str(), Vector2{(float)GetScreenWidth() / 2 - MeasureText(user.id.c_str(), 40) / 2 - 230, (float)GetScreenHeight() / 2 - 200}, 30, 1, BLACK);
			DrawTextEx(customFont, "Address:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Address:", 40) / 2 - 480, (float)GetScreenHeight() / 2 - 100 }, 30, 1, BLACK);
			DrawTextEx(customFont, user.address.c_str(), Vector2{(float)GetScreenWidth() / 2 - MeasureText(user.address.c_str(), 40) / 2 - 110 , (float)GetScreenHeight() / 2 - 100}, 30, 1, BLACK);
			DrawTextEx(customFont, "Username:", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Username:", 40) / 2 - 470, (float)GetScreenHeight() / 2 }, 30, 1, BLACK);
			DrawTextEx(customFont, user.username.c_str(), Vector2{ (float)GetScreenWidth() / 2 - MeasureText(user.username.c_str(), 40) / 2 - 247, (float)GetScreenHeight() / 2 }, 30, 1, BLACK);
			DrawTextEx(customFont, "Will: Your will is encrypted! You can take a look at it in the console of the Horizon application!", Vector2{ (float)GetScreenWidth() / 2 - MeasureText("Your will is encrypted! You can take a look at it in the console of the Horizon application!", 40) / 2 + 350, (float)GetScreenHeight() / 2 + 100 }, 30, 1, BLACK);
			if (!showWill) {
				system("cls");
				std::cout << "\n";
				std::cout << user.username << "'s digital will in Horizon's database:" << "\n";
				std::cout << user.will << "\n";
			}
			showWill = true;
		}

		DrawTextEx(customFont, "Press ESC key to go back.", Vector2{ (float)(GetScreenWidth() / 2) - 900, (float)(GetScreenHeight() / 2) + 400 }, 25, 1, BLACK);

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete validator;
	delete texture;
	delete star;
}

// Gives you an opportunity to create a new will or to review an existing one. 
void digitalWill() {
	const int screenWidth = 1920;
	const int screenHeight = 975;

	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	const Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	const Rectangle digWillButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 260, 270, 100 };
	const Rectangle digReviewWillButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 100, 270, 100 };

	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, screenWidth);
		star->position.y = (float)GetRandomValue(0, screenHeight);
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

			if (star->stars[i].position.y > screenHeight) {
				star->stars[i].position.y = 0;
				star->stars[i].position.x = (float)GetRandomValue(0, screenWidth);
				star->stars[i].size.y = (float)GetRandomValue(10, 20);
				star->stars[i].size.x = (float)GetRandomValue(10, 20);
			}
			DrawTextureEx(texture->getStarTexture(), star->stars[i].position, 0, -0.1f, WHITE);
		}

		DrawTextEx(customFont, "Press ESC key to go back.", Vector2{ (screenWidth / 2) - 900, (screenHeight / 2) + 400 }, 25, 1, WHITE);
		DrawTextEx(customFont, "HORIZON", Vector2{ (float)screenWidth / 2 - MeasureText("HORIZON", 40) / 2 - 10, screenHeight / 2 - 400 }, 50, 10, RAYWHITE);
		DrawTextEx(customFont, "Take charge: Create a new will or revisit and refine", Vector2{ (float)screenWidth / 2 - MeasureText("Take charge: Create a new will or revisit and refine!", 20) / 2 - 120, screenHeight / 2 - 350 }, 40, 1, RAYWHITE);
		DrawTextEx(customFont, "an existing one securing your legacy with care, right here!", Vector2{ (float)screenWidth / 2 - MeasureText("an existing one—securing your legacy with care, right here!", 20) / 2 - 120, screenHeight / 2 - 320 }, 40, 1, RAYWHITE);

		bool isMouseOverButtonNewWill = CheckCollisionPointRec(mousePosition, digWillButton);
		DrawRectangleRec(digWillButton, (isMouseOverButtonNewWill ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "New Will", Vector2{ (screenWidth / 2) - 60, (screenHeight / 2) - 235 }, 50, 1, BLACK);

		// Buttons logic.
		if (isMouseOverButtonNewWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			MinimizeWindow();
			newWill();
		}

		bool isMouseOverReviewWill = CheckCollisionPointRec(mousePosition, digReviewWillButton);
		DrawRectangleRec(digReviewWillButton, (isMouseOverReviewWill ? GOLD : ORANGE));
		DrawTextEx(customFont, "Review Will", Vector2{ (screenWidth / 2) - 85, (screenHeight / 2) - 75 }, 50, 1, BLACK);
		if (isMouseOverReviewWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			reviewWill();
		}

		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}