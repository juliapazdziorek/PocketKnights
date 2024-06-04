#pragma once

#include <SFML/Graphics.hpp>

#include "Assets.h"

class MapTile {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Sprite tile;
    sf::Texture texture;
    sf::Vector2f position;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapTile(sf::Texture& texture, sf::IntRect intRect);
    ~MapTile();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto setPosition(float x, float y) -> void;
    auto render(sf::RenderTarget* window) -> void;

};
