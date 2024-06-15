#pragma once

#include <SFML/Graphics.hpp>

#include "Assets/Animation.h"
#include "Assets/Assets.h"
#include "Engine/Collidable.h"
#include "Knight.h"

class Meat : public Collidable {

private:

    // ----- variables -------------------------------------------------------------------------------------------------

    // sprite variables
    sf::Sprite meat;
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::FloatRect bounds;
    sf::Texture texture;

    // animation variables
    bool spawned;
    sf::Clock spawningClock;
    sf::Clock animationClock;

    //TODO TO DELETE
    sf::RectangleShape hitBox;

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateTexture() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    explicit Meat(sf::Vector2f newPosition);

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // overrides
    auto updateState() -> void override;
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;

};
