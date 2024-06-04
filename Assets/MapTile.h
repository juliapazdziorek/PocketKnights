#pragma once

#include <SFML/Graphics.hpp>

class MapTile {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Sprite tile;
    sf::Texture* texture;
    sf::Vector2f position;
    sf::Vector2f scale;
    bool isPassable;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapTile();
    MapTile(sf::Texture& texture, sf::IntRect intRect, bool isPassable);
    ~MapTile();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto setPosition(sf::Vector2f newPosition) -> void;
    auto setScale(sf::Vector2f newScale) -> void;

    auto render(sf::RenderTarget* window) -> void;

};
