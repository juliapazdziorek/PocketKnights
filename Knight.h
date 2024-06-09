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
    sf::FloatRect nextPositionBounds;
    sf::Vector2f velocity;
    float movingSpeed;
    bool isColliding;

    sf::Clock animationClock;

    sf::Clock attackClock;
    bool attacking;
    sf::Vector2f attackPosition;

    enum class KnightState { STANDING, RUNNING_LEFT, RUNNING_RIGHT, ATTACKING };
    KnightState knightState;

    enum class KnightFacing { LEFT, RIGHT, UP, DOWN };
    KnightFacing knightFacing;

    std::vector<Collidable*> collidables;

    //TODO TO DELETE
    sf::RectangleShape hitBox;
    sf::RectangleShape nextPositionHitBox;

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateAttack() -> void;
    auto updateTexture() -> void;
    auto updateCollision() -> void;
    auto updatePosition() -> void;
    auto updateBounds() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto attack() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Knight();
    ~Knight() = default;

    // ----- public methods --------------------------------------------------------------------------------------------
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;
    auto updateState() -> void override;
    auto render(sf::RenderTarget* window) -> void;

};