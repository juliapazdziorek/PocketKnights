#include "MapTile.h"

//public

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTile::MapTile(sf::Texture& texture, sf::IntRect intRect)
    : texture(texture) {
    this->tile.setTexture(texture);
    this->tile.setTextureRect(intRect);
}


MapTile::~MapTile() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTile::setPosition(float x, float y) -> void {
    this->position = sf::Vector2f(x, y);
}

auto MapTile::render(sf::RenderTarget* window) -> void {
    window->draw(this->tile);
}


