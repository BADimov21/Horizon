#include "login.h"
#include "layout.h"
#include "textures.h"

static void newWill() {
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

		DrawTextEx(customFont, "Press ESC key to go back.", Vector2{ (float)(GetScreenWidth() / 2) - 900, (float)(GetScreenHeight() / 2) + 400 }, 25, 1, WHITE);


		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}

static void reviewWill() {
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

		DrawTexture(texture->getResizedReviewWillBackground(), 0, 0, WHITE);

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

		DrawTexture(texture->getResizedLogo(), GetScreenWidth() - 180, GetScreenHeight() - 180, WHITE);

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}

void digitalWill() {
	const int screenWidth = 1120;
	const int screenHeight = 675;

	Textures* texture = new Textures();
	Stars* star = new Stars();

	Vector2 mousePosition = GetMousePosition();
	const Font customFont = LoadFont("../assets/fonts/roboto.ttf");
	SetExitKey(KEY_ESCAPE);

	const Rectangle digWillButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 260, 270, 100 };
	const Rectangle digReviewWillButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 100, 270, 100 };
	const Rectangle digLogoButton = { GetScreenWidth() - 180, GetScreenHeight() - 150, 270, 100 };

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
		DrawTextEx(customFont, "Take charge: Create a new Will or revisit and refine", Vector2{ (float)screenWidth / 2 - MeasureText("Take charge: Create a new Will or revisit and refine!", 20) / 2 - 120, screenHeight / 2 - 350 }, 40, 1, RAYWHITE);
		DrawTextEx(customFont, "an existing one—securing your legacy with care, right here!", Vector2{ (float)screenWidth / 2 - MeasureText("an existing one—securing your legacy with care, right here!", 20) / 2 - 120, screenHeight / 2 - 320 }, 40, 1, RAYWHITE);

		bool isMouseOverButtonNewWill = CheckCollisionPointRec(mousePosition, digWillButton);
		DrawRectangleRec(digWillButton, (isMouseOverButtonNewWill ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "New Will", Vector2{ (screenWidth / 2) - 60, (screenHeight / 2) - 235 }, 50, 1, BLACK);

		if (isMouseOverButtonNewWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			newWill();
		}

		bool isMouseOverReviewWill = CheckCollisionPointRec(mousePosition, digReviewWillButton);
		DrawRectangleRec(digReviewWillButton, (isMouseOverReviewWill ? GOLD : ORANGE));
		DrawTextEx(customFont, "Review Will", Vector2{ (screenWidth / 2) - 85, (screenHeight / 2) - 75}, 50, 1, BLACK);
		if (isMouseOverReviewWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			reviewWill();
		}

		bool isMouseOverLogo = CheckCollisionPointRec(mousePosition, digLogoButton);
		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);
		if (isMouseOverLogo && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			login();
		}

		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);

		EndDrawing();
	}

	delete texture;
	delete star;
}