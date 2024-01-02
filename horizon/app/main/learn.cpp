#include "login.h"
#include "layout.h"
#include "textures.h"

static void digWillDef() {
	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
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

		DrawTextEx(customFont, "Digital Will", Vector2{ (float)(GetScreenWidth() / 2) - 90, (float)(GetScreenHeight() / 2) - 300 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: To a normal will, it contains information about the deceased's last wishes:", Vector2{ (float)(GetScreenWidth() / 2) - 600, (float)(GetScreenHeight() / 2) - 150 }, 35, 1, WHITE);
		DrawTextEx(customFont, "burial arrangements, executors specified, etc. The main difference, however, is that in a ", Vector2{ (float)(GetScreenWidth() / 2) - 630, (float)(GetScreenHeight() / 2) - 100 }, 35, 1, WHITE);
		DrawTextEx(customFont, "digital will, information such as: user names, passwords, emails, keys to cyber wallets, etc., is ", Vector2{ (float)(GetScreenWidth() / 2) - 670, (float)(GetScreenHeight() / 2) - 50 }, 35, 1, WHITE);
		DrawTextEx(customFont, "described. This information is used by the executor(s) to access the bequeathed digital assets. ", Vector2{ (float)(GetScreenWidth() / 2) - 670, (float)(GetScreenHeight() / 2) }, 35, 1, WHITE);

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}

static void digAssetDef() {
	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
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

		DrawTextEx(customFont, "Digital Asset", Vector2{ (float)(GetScreenWidth() / 2) - 120, (float)(GetScreenHeight() / 2) - 300 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: A digitally recorded, immaterial (in most cases) object, with individually", Vector2{ (float)(GetScreenWidth() / 2) - 580, (float)(GetScreenHeight() / 2) - 150 }, 35, 1, WHITE);
		DrawTextEx(customFont, "defined value and the possibility of bequeathing/inheritance. Each digital asset is", Vector2{ (float)(GetScreenWidth() / 2) - 580, (float)(GetScreenHeight() / 2) - 100 }, 35, 1, WHITE);
		DrawTextEx(customFont, "individually regulated, determining whether it can be bequeathed/inherited. ", Vector2{ (float)(GetScreenWidth() / 2) - 550, (float)(GetScreenHeight() / 2) - 50 }, 35, 1, WHITE);

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}

static void blockchainDef() {
	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
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

		DrawTextEx(customFont, "Blockchain", Vector2{ (float)(GetScreenWidth() / 2) - 120, (float)(GetScreenHeight() / 2) - 300 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: Decentralized method for transferring digital assets, enabling easier transfer ", Vector2{ (float)(GetScreenWidth() / 2) - 600, (float)(GetScreenHeight() / 2) - 150 }, 35, 1, WHITE);
		DrawTextEx(customFont, "between individual persons and/or institutions. Due to its decentralized nature, it is preferred  ", Vector2{ (float)(GetScreenWidth() / 2) - 660, (float)(GetScreenHeight() / 2) - 100 }, 35, 1, WHITE);
		DrawTextEx(customFont, "for transferring large sums of money, stocks, and other digital assets.", Vector2{ (float)(GetScreenWidth() / 2) - 530, (float)(GetScreenHeight() / 2) - 50 }, 35, 1, WHITE);

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}

static void liabilityDef() {
	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
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

		DrawTextEx(customFont, "Digital Liability", Vector2{ (float)(GetScreenWidth() / 2) - 120, (float)(GetScreenHeight() / 2) - 300 }, 50, 1, WHITE);
		DrawTextEx(customFont, "Definition: recorded, resulting from past events obligation, settlement of which  ", Vector2{ (float)(GetScreenWidth() / 2) - 580, (float)(GetScreenHeight() / 2) - 150 }, 35, 1, WHITE);
		DrawTextEx(customFont, "involves a loss of resources with economic benefit. The repayment of the debt is enforced by ", Vector2{ (float)(GetScreenWidth() / 2) - 660, (float)(GetScreenHeight() / 2) - 100 }, 35, 1, WHITE);
		DrawTextEx(customFont, "the entity to whom it is owed. Failure to comply may lead to legal action in the matter.", Vector2{ (float)(GetScreenWidth() / 2) - 600, (float)(GetScreenHeight() / 2) - 50 }, 35, 1, WHITE);

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}

void learn() {
	const int screenWidth = 1920;
	const int screenHeight = 975;

	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	const Rectangle digWillButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 260, 270, 100 };
	const Rectangle digAssetButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 90, 270, 100 };
	const Rectangle blockchainButton = { (screenWidth / 2) - 110, (screenHeight / 2) + 80, 270, 100 };
	const Rectangle digLiabilityButton = { (screenWidth / 2) - 110, (screenHeight / 2) + 250, 270, 100 };


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
		DrawTextEx(customFont, "Here are the definitions. Choose the one you would like to learn!", Vector2{ (float)screenWidth / 2 - MeasureText("Here are the definitions. Choose the one you would like to learn!", 20) / 2 - 120, screenHeight / 2 - 350 }, 40, 1, RAYWHITE);
	   
		bool isMouseOverButtonWill = CheckCollisionPointRec(mousePosition, digWillButton);
		DrawRectangleRec(digWillButton, (isMouseOverButtonWill ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "Digital Will", Vector2{ (screenWidth / 2) - 75, (screenHeight / 2) - 235 }, 50, 1, BLACK);

		if (isMouseOverButtonWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			digWillDef();
		}

		bool isMouseOverAsset = CheckCollisionPointRec(mousePosition, digAssetButton);
		DrawRectangleRec(digAssetButton, (isMouseOverAsset ? GREEN : LIME));
		DrawTextEx(customFont, "Digital Asset", Vector2{ (screenWidth / 2) - 95, (screenHeight / 2) - 65 }, 50, 1, BLACK);

		if (isMouseOverAsset && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			digAssetDef();
		}
		
		bool isMouseOverBlockchain = CheckCollisionPointRec(mousePosition, blockchainButton);
		DrawRectangleRec(blockchainButton, (isMouseOverBlockchain ? PINK : RED));
		DrawTextEx(customFont, "Blockchain", Vector2{ (screenWidth / 2) - 80, (screenHeight / 2) + 100 }, 50, 1, BLACK);
		if (isMouseOverBlockchain && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			blockchainDef();
		}

		bool isMouseOverLiability = CheckCollisionPointRec(mousePosition, digLiabilityButton);
		DrawRectangleRec(digLiabilityButton, (isMouseOverLiability ? GOLD : ORANGE));
		DrawTextEx(customFont, "Liability", Vector2{ (screenWidth / 2) - 45, (screenHeight / 2) + 270 }, 50, 1, BLACK);
		if (isMouseOverLiability && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			liabilityDef();
		}

		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}