#include "login.h"
#include "layout.h"
#include "textures.h"


void digWillDef()
{
	SetExitKey(KEY_ESCAPE);
	BeginDrawing();

	ClearBackground(BLACK);
	EndDrawing();
}

void learn()
{
	Vector2 mousePosition = { -100.0f, -100.0f };
	const int screenWidth = 1920;
	const int screenHeight = 975;
	SetExitKey(KEY_ESCAPE);

	Textures* texture = new Textures();

	Font customFont = LoadFont("../assets/fonts/roboto.ttf");

	Rectangle digWillButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 210, 270, 100 };


	while (!WindowShouldClose())
	{
		mousePosition = GetMousePosition();
		bool isMouseOverButtonWill = CheckCollisionPointRec(mousePosition, digWillButton);

		BeginDrawing();
		DrawRectangleRec(digWillButton, (isMouseOverButtonWill ? SKYBLUE : BLUE));
		DrawTextEx(customFont, "Digital Will", Vector2{ (screenWidth / 2) - 75, (screenHeight / 2) - 180 }, 50, 1, BLACK);

		if (isMouseOverButtonWill && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			digWillDef();
		}

		DrawTexture(texture->getResizedLogo(), screenWidth - 180, screenHeight - 180, WHITE);
		DrawTexture(texture->getCustomCursor(), GetMouseX(), GetMouseY(), WHITE);




		ClearBackground(WHITE);
		EndDrawing();
	}
}