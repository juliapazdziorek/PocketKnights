#pragma once

#include <SFML/Graphics.hpp>

//: public Collidable
class MapTile  {

private:

    // ----- variables -------------------------------------------------------------------------------------------------
    sf::Texture texture;


protected:

    // ----- protected variables ---------------------------------------------------------------------------------------
    sf::Sprite tile;
    sf::Vector2f position;
    sf::Vector2f scale;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapTile();
    MapTile(sf::Texture& texture, sf::IntRect intRect);
    virtual ~MapTile() = default;

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    virtual auto render(sf::RenderTarget* window) -> void;

    // setters
    auto setPosition(sf::Vector2f newPosition) -> void;
    auto setScale(sf::Vector2f newScale) -> void;

};
