#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Assets/Animation.h"
#include "Assets/Assets.h"
#include "Engine/Attack.h"
#include "Engine/Collidable.h"
#include "Engine/Utility.h"
#include "Knight.h"

class Goblin : public Collidable {

private:

    // enums
    enum class GoblinState { STANDING, RUNNING_LEFT, RUNNING_RIGHT, ATTACKING };
    enum class GoblinFacing { LEFT, RIGHT, UP, DOWN };

    // ----- variables ------------------------------------------------------------------------------------------------

    // goblin state
    int health;
    GoblinState goblinState;
    GoblinFacing goblinFacing;

    // sprite variables
    sf::Sprite goblin;
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::FloatRect bounds;

    // animation variables
    std::vector<Animation> animations;
    sf::Clock animationClock;

    // movement variables
    float movingSpeed;
    bool readyToChase;
    sf::Vector2f velocity;
    sf::FloatRect nextPositionBounds;
    sf::Vector2f chasedPosition;

    // attack variables
    bool isAttacking;
    sf::Clock attackAnimationClock;
    sf::Vector2f attackPosition;
    sf::FloatRect attackBounds;
    Attack currentAttack;
    Attack previousBeingAttacked;

    // collision variables
    bool isColliding;
    std::vector<Collidable*> collidables;

    //TODO to delete
    /*sf::RectangleShape hitBox;
    sf::RectangleShape nextPositionHitBox;
    sf::RectangleShape attackHitBox;*/


    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateIsAlive() -> void;
    auto updateAttack() -> void;
    auto updateMovement() -> void;
    auto updateCollision() -> void;
    auto updateTexture() -> void;

    // updating variables
    auto updatePositionVariable() -> void;
    auto updateBoundsVariable() -> void;
    auto updateNextPositionBoundsVariable() -> void;
    auto updateAttackBoundsVariable() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // movement
    auto moveToChasingPosition() -> void;
    auto chase() -> void;
    auto moveLeft() -> void;
    auto moveRight() -> void;
    auto moveUp() -> void;
    auto moveDown() -> void;

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    Goblin();

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // overrides
    auto updateState() -> void override;
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;

    // getters
    auto getCurrentAttack() -> Attack&;
    auto getPosition() -> sf::Vector2f&;

    // setters
    auto setPosition(sf::Vector2f newPosition) -> void;
    auto setChasedPosition(sf::Vector2f newChasedPosition) -> void;

};
