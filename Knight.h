#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Assets/Assets.h"
#include "Assets/Animation.h"

class Knight {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Sprite knight;
    sf::Vector2f position;
    sf::Vector2f scale;
    float movingSpeed;
    sf::Clock animationClock;

    sf::Clock attackClock;
    bool attacking;
    sf::Vector2f attackPosition;

    enum class KnightState { KNIGHT_STANDING, KNIGHT_RUNNING_LEFT, KNIGHT_RUNNING_RIGHT, KNIGHT_ATTACKING };
    KnightState knightState;

    enum class KnightFacing { LEFT, RIGHT, UP, DOWN };
    KnightFacing knightFacing;


    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateAttack() -> void;
    auto updateTexture() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto attack() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Knight();
    ~Knight();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateState() -> void;
    auto render(sf::RenderTarget* window) -> void;

};