#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Engine/Collidable.h"
#include "Engine/Attack.h"
#include "Engine/Utility.h"
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

    int health;

    std::vector<Animation> animations;
    sf::Clock animationClock;

    sf::Clock attackAnimationClock;
    bool attacking;
    sf::Vector2f attackPosition;
    sf::FloatRect attackBounds;
    Attack currentAttack;
    Attack previousBeingAttacked;

    std::vector<Collidable*> collidables;

    bool readyToChase;

    enum class GoblinState { STANDING, RUNNING_LEFT, RUNNING_RIGHT, ATTACKING };
    GoblinState goblinState;

    enum class GoblinFacing { LEFT, RIGHT, UP, DOWN };
    GoblinFacing goblinFacing;

    //TODO TO DELETE
    sf::RectangleShape hitBox;
    sf::RectangleShape nextPositionHitBox;


    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateMovement() -> void;
    auto updateAttack() -> void;
    auto updateIsAlive() -> void;
    auto updateTexture() -> void;
    auto updateCollision() -> void;

    auto updatePositionVariable() -> void;
    auto updateBoundsVariable() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto moveToChasingPosition() -> void;
    auto moveLeft() -> void;
    auto moveRight() -> void;
    auto moveUp() -> void;
    auto moveDown() -> void;
    auto attack() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Goblin();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto isCollidingWith(Collidable& other) const -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;
    auto updateState() -> void override;
    auto render(sf::RenderTarget* window) -> void;

    auto getCurrentAttack() -> Attack&;
    auto setPosition(sf::Vector2f position) -> void;

};
