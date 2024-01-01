#pragma once

#include "pch.h"

class Textures {
public:
    Textures() {
        loadAllTextures();
    }

    ~Textures() {
        unloadAllTextures();
    }

    const Texture2D& getResizedBackground() const {
        return resizedBackground;
    }

    const Texture2D& getStarTexture() const {
        return starTexture;
    }

    const Texture2D& getResizedLogo() const {
        return resizedLogo;
    }

    const Texture2D& getCustomCursor() const {
        return customCursor;
    }

private:
    Texture2D resizedBackground = { 0 };
    Texture2D starTexture = { 0 };
    Texture2D resizedLogo = { 0 };
    Texture2D customCursor = { 0 };

    const void loadAllTextures() {
        Image background = LoadImage("../assets/background.png");
        ImageResize(&background, GetScreenWidth(), GetScreenHeight());
        resizedBackground = LoadTextureFromImage(background);
        UnloadImage(background);

        Image star = LoadImage("../assets/bright_star.png");
        starTexture = LoadTextureFromImage(star);
        UnloadImage(star);

        Image logo = LoadImage("../assets/logo.png");
        ImageResize(&logo, 150, 150);
        resizedLogo = LoadTextureFromImage(logo);
        UnloadImage(logo);

        Image customCursorImage = LoadImage("../assets/cursor.png");
        ImageResize(&customCursorImage, 40, 40);
        customCursor = LoadTextureFromImage(customCursorImage);
        UnloadImage(customCursorImage);
    }

    const void unloadAllTextures() const {
        UnloadTexture(resizedBackground);
        UnloadTexture(starTexture);
        UnloadTexture(resizedLogo);
        UnloadTexture(customCursor);
    }
};

class Images {
public:
    Images() {
        loadAllImages();
    }

    ~Images() {
        unloadAllImages();
    }

    const Image& getLogo() const {
        return logo;
    }

private:
    Image logo = { 0 };

    const void loadAllImages() {
        logo = LoadImage("../assets/logo.png");
        ImageResize(&logo, 175, 150);
    }

    const void unloadAllImages() const {
        UnloadImage(logo);
    }
};