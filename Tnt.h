#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Assets//Animation.h"
#include "Assets/Assets.h"
#include "Engine/Attack.h"
#include "Engine/Collidable.h"
#include "TntColor.h"

class Tnt : public Collidable {

    // enums
    enum class TntState { OUT, RUNNING, EXPLODING };
    enum class TntFacing { LEFT, RIGHT, UP, DOWN };

    // ----- variables -------------------------------------------------------------------------------------------------

    // tnt state
    TntState tntState;
    TntFacing tntFacing;
    TntColor tntColor;

    // sprite variables
    sf::Sprite tnt;
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::FloatRect bounds;

    // animation variables
    bool spawned;
    sf::Clock spawningClock;
    sf::Clock animationClock;
    sf::Clock timeToExplodeClock;
    std::vector<Animation> animationsBlue;
    std::vector<Animation> animationsRed;

    // movement variables
    float movingSpeed;
    sf::Vector2f velocity;
    sf::FloatRect nextPositionBounds;
    sf::Vector2f chasedPosition;

    // explosion variables
    bool exploding;
    sf::FloatRect explosionBounds;
    sf::Clock timeToStartExplosionClock;

    // collision variables
    bool isColliding;
    std::vector<Collidable*> collidables;

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateMovement() -> void;
    auto updateCollision() -> void;
    auto updateTexture() -> void;

    // updating variables
    auto updatePositionVariable() -> void;
    auto updateBoundsVariable() -> void;
    auto updateNextPositionBoundsVariable() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // movement
    auto chase() -> void;
    auto moveLeft() -> void;
    auto moveRight() -> void;
    auto moveUp() -> void;
    auto moveDown() -> void;

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    explicit Tnt(TntColor color);

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // overrides
    auto updateState() -> void override;
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;

    // getters
    auto getTntColor() -> TntColor;
    auto getPosition() -> sf::Vector2f;

    // setters
    auto setPosition(sf::Vector2f newPosition) -> void;
    auto setChasedPosition(sf::Vector2f newChasedPosition) -> void;

};
