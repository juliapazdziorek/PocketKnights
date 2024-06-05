#pragma once

#include <SFML/Graphics.hpp>

class MapTile {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Texture* texture;

public:

    // ----- public properties -----------------------------------------------------------------------------------------
    sf::Sprite tile;
    bool isPassable;
    sf::Vector2f position;
    sf::Vector2f scale;
    //should be protected :(

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapTile();
    MapTile(sf::Texture& texture, sf::IntRect intRect, bool isPassable);
    virtual ~MapTile();

    // ----- public methods --------------------------------------------------------------------------------------------

   //setters
    auto setPosition(sf::Vector2f newPosition) -> void;
    auto setScale(sf::Vector2f newScale) -> void;

    virtual auto render(sf::RenderTarget* window) -> void;

};
