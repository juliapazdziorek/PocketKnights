#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Assets/Animation.h"
#include "Assets/Assets.h"
#include "Engine/Attack.h"
#include "Engine/Collidable.h"
#include "Engine/Explosion.h"
#include "Engine/Utility.h"
#include "Mushroom.h"
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

    // health bar variables
    sf::RectangleShape healthBar;
    sf::RectangleShape healthInBar;

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

    // mushrooms variables
    bool onMushrooms;
    sf::Clock mushroomClock;

    // collision variables
    bool isColliding;
    std::vector<Collidable*> collidables;


    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateHealthBar() -> void;
    auto updateIsAlive() -> void;
    auto updateAttack() -> void;
    auto updateMushrooms() -> void;
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

    // ----- constructor -----------------------------------------------------------------------------------------------
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
