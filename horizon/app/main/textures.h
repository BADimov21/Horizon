#pragma once

#include "pch.h"

// Contains the attributes and methods for the textures of the application.
class Textures {
public:
	// Constructor which loads all textures.
	Textures() {
		loadAllTextures();
	}

	// Destructor which unloads all textures.
	~Textures() {
		unloadAllTextures();
	}

	// Getter which returns the resized background.
	const Texture2D& getResizedBackground() const {
		return resizedBackground;
	}
	// Getter which returns the resized example will.
	const Texture2D& getResizedExWill() const {
		return exWill;
	}

	// Getter which returns the resized new will background.
	const Texture2D& getResizedNewWillBackground() const {
		return resizedNewWillBackground;
	}

	// Getter which returns the star texture.
	const Texture2D& getStarTexture() const {
		return starTexture;
	}

	// Getter which returns the resized logo background.
	const Texture2D& getResizedLogo() const {
		return resizedLogo;
	}

	// Getter which returns the custom cursor.
	const Texture2D& getCustomCursor() const {
		return customCursor;
	}

private:
	Texture2D resizedBackground = { 0 };
	Texture2D resizedNewWillBackground = { 0 };
	Texture2D starTexture = { 0 };
	Texture2D resizedLogo = { 0 };
	Texture2D customCursor = { 0 };
	Texture2D exWill = { 0 };

	// Loads all textures.
	void loadAllTextures() {
		Image background = LoadImage("../assets/background.png");
		ImageResize(&background, GetScreenWidth(), GetScreenHeight());
		resizedBackground = LoadTextureFromImage(background);
		UnloadImage(background);

		Image newWillBackground = LoadImage("../assets/new_will.png");
		ImageResize(&newWillBackground, GetScreenWidth(), GetScreenHeight());
		resizedNewWillBackground = LoadTextureFromImage(newWillBackground);
		UnloadImage(newWillBackground);

		Image exWillBg = LoadImage("../assets/example_will.png");
		ImageResize(&exWillBg, 800, 700);
		exWill = LoadTextureFromImage(exWillBg);
		UnloadImage(exWillBg);

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

	// Unloads all textures.
	void unloadAllTextures() const {
		UnloadTexture(resizedBackground);
		UnloadTexture(resizedNewWillBackground);
		UnloadTexture(starTexture);
		UnloadTexture(resizedLogo);
		UnloadTexture(customCursor);
	}
};

// Contains the attributes and methods for the images of the application.
class Images {
public:
    // Constructor which loads all images.
	Images() {
		loadAllImages();
	}

	// Destructor which unloads all images.
	~Images() {
		unloadAllImages();
	}

	// Getter which returns the logo.
	const Image& getLogo() const {
		return logo;
	}

private:
	Image logo = { 0 };

	// Loads all images.
	void loadAllImages() {
		logo = LoadImage("../assets/logo.png");
		ImageResize(&logo, 175, 150);
	}

	// Unloads all images.
	void unloadAllImages() const {
		UnloadImage(logo);
	}
};