#pragma once

#include <SFML/Graphics.hpp>

class MapTile {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Texture texture;

protected:

    // ----- protected properties --------------------------------------------------------------------------------------
    sf::Sprite tile;
    sf::Vector2f position;
    sf::Vector2f scale;
    bool isPassable;

public:

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
