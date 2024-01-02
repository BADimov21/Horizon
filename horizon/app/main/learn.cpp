#include "login.h"
#include "layout.h"
#include "textures.h"


static void digWillDef()
{
	Vector2 mousePosition = { -100.0f, -100.0f };
	const int screenWidth = 1920;
	const int screenHeight = 975;
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	Textures* texture = new Textures();
	Stars* star = new Stars();
	SetExitKey(KEY_ESCAPE);


	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, screenWidth);
		star->position.y = (float)GetRandomValue(0, screenHeight);
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}
	while (!WindowShouldClose())
	{
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

		DrawTextEx(customFont, "press ESC to go back", Vector2{ (screenWidth / 2) - 900, (screenHeight / 2) + 400 }, 25, 1, WHITE);

		DrawTextEx(customFont, "Digital Will", Vector2{ (screenWidth / 2) - 120, (screenHeight / 2) - 400 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: to a normal will, it contains information about the deceased's last wishes:", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 250 }, 35, 1, WHITE);
		DrawTextEx(customFont, "burial arrangements, executors specified, etc. The main difference, however, is that in a ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 200 }, 35, 1, WHITE);
		DrawTextEx(customFont, "digital will, information such as: user names, passwords, emails, keys to cyber wallets, etc., is ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 150 }, 35, 1, WHITE);
		DrawTextEx(customFont, "described. This information is used by the executor(s) to access the bequeathed digital assets. ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 100 }, 35, 1, WHITE);
		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);
		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		ClearBackground(WHITE);
		EndDrawing();

	}
	
}
static void digAssetDef()
{
	Vector2 mousePosition = { -100.0f, -100.0f };
	const int screenWidth = 1920;
	const int screenHeight = 975;
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	Textures* texture = new Textures();
	Stars* star = new Stars();
	SetExitKey(KEY_ESCAPE);


	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, screenWidth);
		star->position.y = (float)GetRandomValue(0, screenHeight);
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}
	while (!WindowShouldClose())
	{
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

		DrawTextEx(customFont, "press ESC to go back", Vector2{ (screenWidth / 2) - 900, (screenHeight / 2) + 400 }, 25, 1, WHITE);

		DrawTextEx(customFont, "Digital Asset", Vector2{ (screenWidth / 2) - 120, (screenHeight / 2) - 400 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: a digitally recorded, immaterial (in most cases) object, with individually", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 250 }, 35, 1, WHITE);
		DrawTextEx(customFont, "defined value and the possibility of bequeathing/inheritance. Each digital asset is", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 200 }, 35, 1, WHITE);
		DrawTextEx(customFont, "individually regulated, determining whether it can be bequeathed/inherited. ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 150 }, 35, 1, WHITE);
		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);
		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		ClearBackground(WHITE);
		EndDrawing();

	}
}
static void blockchainDef()
{
	Vector2 mousePosition = { -100.0f, -100.0f };
	const int screenWidth = 1920;
	const int screenHeight = 975;
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	Textures* texture = new Textures();
	Stars* star = new Stars();
	SetExitKey(KEY_ESCAPE);


	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, screenWidth);
		star->position.y = (float)GetRandomValue(0, screenHeight);
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}
	while (!WindowShouldClose())
	{
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
		DrawTextEx(customFont, "press ESC to go back", Vector2{ (screenWidth / 2) - 900, (screenHeight / 2) + 400 }, 25, 1, WHITE);
		DrawTextEx(customFont, "Blockchain", Vector2{ (screenWidth / 2) - 120, (screenHeight / 2) - 400 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: decentralized method for transferring digital assets, enabling easier transfer ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 250 }, 35, 1, WHITE);
		DrawTextEx(customFont, "between individual persons and/or institutions. Due to its decentralized nature, it is preferred  ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 200 }, 35, 1, WHITE);
		DrawTextEx(customFont, "for transferring large sums of money, stocks, and other digital assets.", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 150 }, 35, 1, WHITE);

		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);
		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		ClearBackground(WHITE);
		EndDrawing();

	}
}
static void liabilityDef()
{
	Vector2 mousePosition = { -100.0f, -100.0f };
	const int screenWidth = 1920;
	const int screenHeight = 975;
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	Textures* texture = new Textures();
	Stars* star = new Stars();
	SetExitKey(KEY_ESCAPE);


	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, screenWidth);
		star->position.y = (float)GetRandomValue(0, screenHeight);
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}
	while (!WindowShouldClose())
	{
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
		DrawTextEx(customFont, "press ESC to go back", Vector2{ (screenWidth / 2) - 900, (screenHeight / 2) + 400 }, 25, 1, WHITE);
		DrawTextEx(customFont, "Digital Liability", Vector2{ (screenWidth / 2) - 120, (screenHeight / 2) - 400 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: recorded, resulting from past events obligation, settlement of which  ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 250 }, 35, 1, WHITE);
		DrawTextEx(customFont, "involves a loss of resources with economic benefit. The repayment of the debt is enforced by ", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 200 }, 35, 1, WHITE);
		DrawTextEx(customFont, "the entity to whom it is owed. Failure to comply may lead to legal action in the matter.", Vector2{ (screenWidth / 2) - 800, (screenHeight / 2) - 150 }, 35, 1, WHITE);

		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);
		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		ClearBackground(WHITE);
		EndDrawing();

	}
}

void learn()
{
	Vector2 mousePosition = { -100.0f, -100.0f };
	const int screenWidth = 1920;
	const int screenHeight = 975;
	SetExitKey(KEY_ESCAPE);

	Textures* texture = new Textures();
	Stars* star = new Stars();

	Font customFont = LoadFont("../assets/fonts/roboto.ttf");

	Rectangle digWillButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 260, 270, 100 };
	Rectangle digAssetButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 90, 270, 100 };
	Rectangle blockchainButton = { (screenWidth / 2) - 110, (screenHeight / 2) +80, 270, 100 };
	Rectangle digLiabilityButton = { (screenWidth / 2) - 110, (screenHeight / 2) + 250, 270, 100 };


	for (size_t i = 0; i < star->maxStars; i++) {
		star->position.x = (float)GetRandomValue(0, screenWidth);
		star->position.y = (float)GetRandomValue(0, screenHeight);
		star->color = WHITE;
		star->speed = static_cast<float>(GetRandomValue(20, 30) * 0.1);
		star->stars.push_back(*star);
	}

	while (!WindowShouldClose())
	{
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

		DrawTextEx(customFont, "press ESC to go back", Vector2{ (screenWidth / 2) - 900, (screenHeight / 2) + 400 }, 25, 1, WHITE);

		DrawTextEx(customFont, "HORIZON", Vector2{ (float)screenWidth / 2 - MeasureText("HORIZON", 40) / 2 - 10, screenHeight / 2 - 400 }, 50, 10, RAYWHITE);
		DrawTextEx(customFont, "Here are the definitions. Chose these you want to learn!", Vector2{ (float)screenWidth / 2 - MeasureText("Here are the definitions. Chose these you want to learn!", 20) / 2 - 70, screenHeight / 2 - 350 }, 40, 1, RAYWHITE);

		DrawTextEx(customFont, "press ESC to go back", Vector2{ (screenWidth / 2) - 900, (screenHeight / 2) +400 }, 25, 1, WHITE);

		bool isMouseOverButtonWill = CheckCollisionPointRec(mousePosition, digWillButton);
		DrawRectangleRec(digWillButton, (isMouseOverButtonWill ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "Digital Will", Vector2{ (screenWidth / 2) - 75, (screenHeight / 2) - 235 }, 50, 1, BLACK);

		if (isMouseOverButtonWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			digWillDef();
		}

		bool isMouseOverAsset = CheckCollisionPointRec(mousePosition, digAssetButton);
		DrawRectangleRec(digAssetButton, (isMouseOverAsset ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "Digital Asset", Vector2{ (screenWidth / 2) - 95, (screenHeight / 2) - 65 }, 50, 1, BLACK);

		if (isMouseOverAsset && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			digAssetDef();
		}
		
		bool isMouseOverBlockchain = CheckCollisionPointRec(mousePosition, blockchainButton);
		DrawRectangleRec(blockchainButton, (isMouseOverBlockchain ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "Blockchain", Vector2{ (screenWidth / 2) - 85, (screenHeight / 2) + 100 }, 50, 1, BLACK);
		if (isMouseOverBlockchain && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			blockchainDef();
		}

		bool isMouseOverLiability = CheckCollisionPointRec(mousePosition, digLiabilityButton);
		DrawRectangleRec(digLiabilityButton, (isMouseOverLiability ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "Liability", Vector2{ (screenWidth / 2) - 55, (screenHeight / 2) + 270 }, 50, 1, BLACK);
		if (isMouseOverLiability && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			liabilityDef();
		}





		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);
		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);




		ClearBackground(WHITE);
		EndDrawing();
	}
}