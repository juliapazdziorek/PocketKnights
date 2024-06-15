#pragma once

#include "Assets/Animation.h"
#include "Assets/Assets.h"
#include "Engine/Attack.h"
#include "Engine/Collidable.h"


class Sheep : public Collidable {

    // private:

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
    std::vector<Animation> animations;
    sf::Clock animationClock;
    bool countBounceTime;
    int bounceTime;
    sf::Clock bounceClock;


    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateAnimation() -> void;
    auto updateTexture() -> void;

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

};

