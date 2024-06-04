#include "MapTile.h"

//public

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTile::MapTile() = default;

MapTile::MapTile(sf::Texture& texture, sf::IntRect intRect, bool isPassable)
    : texture(&texture), isPassable(isPassable) {
    this->tile.setTexture(texture);
    this->tile.setTextureRect(intRect);
}


MapTile::~MapTile() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTile::setPosition(sf::Vector2f newPosition) -> void {
    this->position = newPosition;
}

auto MapTile::setScale(sf::Vector2f newScale) -> void {
    this->scale = newScale;
}

auto MapTile::render(sf::RenderTarget* window) -> void {
    window->draw(this->tile);
}


