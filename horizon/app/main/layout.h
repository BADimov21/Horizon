#pragma once

#include "pch.h"

// Contains the attributes for the rain effect.
class Stars {
public:
    const int maxStars = 5;
    std::vector<Stars> stars;
    Vector2 position = Vector2{ 0, 0 };
    Vector2 size = Vector2{ 0, 0 };
    Color color = WHITE;
    float speed = 0;
};