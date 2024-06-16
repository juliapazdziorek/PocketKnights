#pragma once

#include "Assets/Animation.h"
#include "Assets/Assets.h"
#include "Engine/Attack.h"
#include "Engine/Collidable.h"
#include "Engine/Utility.h"


class Sheep : public Collidable {

private:

    // enums
    enum class SheepState { STANDING, BOUNCING };

    // ----- variables -------------------------------------------------------------------------------------------------

    // sheep state
    SheepState sheepState;

    // sprite variables
    sf::Sprite sheep;
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::FloatRect bounds;

    // animation variables
    float timeToBounce;
    bool isBouncing;
    std::vector<Animation> animations;
    sf::Clock animationClock;
    sf::Clock bouncingAnimationClock;
    sf::Clock timeToBounceClock;

    //TODO to delete
    /*sf::RectangleShape hitBox;*/

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateBouncing() -> void;
    auto updateTexture() -> void;

    // updating variables
    auto updateBoundsVariable() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    Sheep();

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // overrides
    auto updateState() -> void override;
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;

    // getters
    auto getPosition() -> sf::Vector2f;

    //setters
    auto setPosition(sf::Vector2f newPosition) -> void;

};
