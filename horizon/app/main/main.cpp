#include <iostream>
#include "raylib.h"
#include "dataAccess.h"

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 975;
    
    DataAccess* data = new DataAccess;
    std::cout << data->doesUsernameExist("username");
    
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