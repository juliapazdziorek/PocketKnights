#pragma once

#include <SFML/Graphics.hpp>

#include "Assets/Assets.h"
#include "Engine/Collidable.h"
#include "Knight.h"

class Mushroom : public Collidable {

private:

    // ----- variables -------------------------------------------------------------------------------------------------

    // sprite variables
    sf::Sprite mushroom;
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::FloatRect bounds;

    // ----- private methods -------------------------------------------------------------------------------------------

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    explicit Mushroom(sf::Vector2f newPosition);

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // overrides
    auto updateState() -> void override;
    auto isCollidingWith(Collidable& other) -> bool override;
    auto onCollisionWith(Collidable& other) -> void override;

    // getters
    auto getPosition() -> sf::Vector2f;

};


