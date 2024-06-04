#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Renderable.h"
#include "Assets/Assets.h"
#include "Assets/Animation.h"

class Goblin : Renderable {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Sprite goblin;
    sf::Vector2f scale;
    sf::Vector2f position;
    float movingSpeed;
    sf::Clock animationClock;

    sf::Clock attackClock;
    bool attacking;
    sf::Vector2f attackPosition;

    enum class GoblinState { GOBLIN_STANDING, GOBLIN_RUNNING_LEFT, GOBLIN_RUNNING_RIGHT, GOBLIN_ATTACKING };
    GoblinState goblinState;

    enum class GoblinFacing { LEFT, RIGHT, UP, DOWN };
    GoblinFacing goblinFacing;

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateAttack() -> void;
    auto updateTexture() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto attack() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Goblin();
    ~Goblin();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateState() -> void;
    auto render(sf::RenderTarget* window) -> void override;

};
