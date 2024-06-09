#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Engine/Collidable.h"
#include "Assets/Assets.h"
#include "Assets/Animation.h"

class Goblin : public Collidable {

private:

    // ----- variables ------------------------------------------------------------------------------------------------
    sf::Sprite goblin;
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

    std::vector<Collidable*> collidables;

    enum class GoblinState { STANDING, RUNNING_LEFT, RUNNING_RIGHT, ATTACKING };
    GoblinState goblinState;

    enum class GoblinFacing { LEFT, RIGHT, UP, DOWN };
    GoblinFacing goblinFacing;

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
    Goblin();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;
    auto updateState() -> void override;
    auto render(sf::RenderTarget* window) -> void;

};
