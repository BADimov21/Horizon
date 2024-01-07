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

    const Texture2D& getResizedReviewWillBackground() const {
        return resizedReviewWillBackground;
    }

    const Texture2D& getResizedNewWillBackground() const {
        return resizedNewWillBackground;
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
    Texture2D resizedReviewWillBackground = { 0 };
    Texture2D resizedNewWillBackground = { 0 };
    Texture2D starTexture = { 0 };
    Texture2D resizedLogo = { 0 };
    Texture2D customCursor = { 0 };

    void loadAllTextures() {
        Image background = LoadImage("../assets/background.png");
        ImageResize(&background, GetScreenWidth(), GetScreenHeight());
        resizedBackground = LoadTextureFromImage(background);
        UnloadImage(background);

        Image reviewWillBackground = LoadImage("../assets/review_Will_background.png");
        ImageResize(&reviewWillBackground, GetScreenWidth(), GetScreenHeight());
        resizedReviewWillBackground = LoadTextureFromImage(reviewWillBackground);
        UnloadImage(reviewWillBackground);

        Image newWillBackground = LoadImage("../assets/new_Will_background.png");
        ImageResize(&newWillBackground, GetScreenWidth(), GetScreenHeight());
        resizedNewWillBackground = LoadTextureFromImage(newWillBackground);
        UnloadImage(newWillBackground);

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

    void unloadAllTextures() const {
        UnloadTexture(resizedBackground);
        UnloadTexture(resizedReviewWillBackground);
        UnloadTexture(resizedNewWillBackground);
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

    void loadAllImages() {
        logo = LoadImage("../assets/logo.png");
        ImageResize(&logo, 175, 150);
    }

    void unloadAllImages() const {
        UnloadImage(logo);
    }
};