#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Assets/Animation.h"
#include "Assets/Assets.h"
#include "Engine/Attack.h"
#include "Engine/Collidable.h"
#include "Engine/Utility.h"
#include "Meat.h"

class Knight : public Collidable {

private:

    // enums
    enum class KnightState { STANDING, RUNNING_LEFT, RUNNING_RIGHT, ATTACKING };
    enum class KnightFacing { LEFT, RIGHT, UP, DOWN };

    // ----- variables -------------------------------------------------------------------------------------------------

    // knight state
    int health;
    KnightState knightState;
    KnightFacing knightFacing;

    // sprite variables
    sf::Sprite knight;
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::FloatRect bounds;

    // animation variables
    std::vector<Animation> animations;
    sf::Clock animationClock;

    // movement variables
    float movingSpeed;
    sf::Vector2f velocity;
    sf::FloatRect nextPositionBounds;

    // attack variables
    bool isAttacking;
    sf::Clock attackAnimationClock;
    sf::Vector2f attackPosition;
    sf::FloatRect attackBounds;
    Attack currentAttack;
    Attack previousBeingAttacked;

    // collision variables
    bool isColliding;
    std::vector<Collidable*> collidables; //TODO przerobić na unique pointery

    //TODO TO DELETE
    sf::RectangleShape hitBox;
    sf::RectangleShape nextPositionHitBox;
    sf::RectangleShape attackHitBox;


    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateIsAlive() -> void;
    auto updateAttack() -> void;
    auto updateCollision() -> void;
    auto updateTexture() -> void;

    // update variables
    auto updatePositionVariable() -> void;
    auto updateBoundsVariable() -> void;
    auto updateAttackBoundsVariable() -> void;
    auto updateNextPositionBoundsVariable() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Knight();

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // overrides
    auto updateState() -> void override;
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;

    // getters
    auto getCurrentAttack() -> Attack&;
    auto getPosition() -> sf::Vector2f;

};
