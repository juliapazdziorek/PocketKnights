#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Engine/Collidable.h"
#include "Assets/Assets.h"
#include "Assets/Animation.h"

class Knight : public Collidable {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Sprite knight;
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::FloatRect bounds;
    float movingSpeed;
    sf::Clock animationClock;

    sf::Vector2f  nextPosition;

    sf::Clock attackClock;
    bool attacking;
    sf::Vector2f attackPosition;

    enum class KnightState { STANDING, RUNNING_LEFT, RUNNING_RIGHT, ATTACKING };
    KnightState knightState;

    enum class KnightFacing { LEFT, RIGHT, UP, DOWN };
    KnightFacing knightFacing;

    //TODO TO DELETE
    sf::RectangleShape hitBox;

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateAttack() -> void;
    auto updateTexture() -> void;
    auto updateBounds() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto attack() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Knight();
    ~Knight() = default;

    // ----- public methods --------------------------------------------------------------------------------------------
    auto onCollisionWith(Collidable& other) -> void override;
    auto updateState() -> void override;
    auto render(sf::RenderTarget* window) -> void;

};