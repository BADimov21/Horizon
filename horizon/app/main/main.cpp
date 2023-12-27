#include "raylib.h"

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 975;

    InitWindow(screenWidth, screenHeight, "Horizon");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}