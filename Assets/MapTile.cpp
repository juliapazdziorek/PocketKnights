#include "MapTile.h"

// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

MapTile::MapTile() = default;

MapTile::MapTile(sf::Texture& texture, sf::IntRect intRect)
    : texture(texture) {
    tile.setTexture(texture);
    tile.setTextureRect(intRect);
}


// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto MapTile::render(sf::RenderTarget* window) -> void {
    window->draw(tile);
}


//setters
auto MapTile::setPosition(sf::Vector2f newPosition) -> void {
    position = newPosition;
    tile.setPosition(position);
}

auto MapTile::setScale(sf::Vector2f newScale) -> void {
    scale = newScale;
    tile.setScale(scale);
}
