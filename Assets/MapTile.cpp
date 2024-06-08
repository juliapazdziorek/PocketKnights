#include "MapTile.h"

//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTile::MapTile() = default;

MapTile::MapTile(sf::Texture& texture, sf::IntRect intRect, bool isPassable)
    : texture(texture), isPassable(isPassable) {
    this->tile.setTexture(texture);
    this->tile.setTextureRect(intRect);
}


MapTile::~MapTile() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

//setters
auto MapTile::setPosition(sf::Vector2f newPosition) -> void {
    this->position = newPosition;
    this->tile.setPosition(position);
}

auto MapTile::setScale(sf::Vector2f newScale) -> void {
    this->scale = newScale;
    tile.setScale(scale);
}

auto MapTile::render(sf::RenderTarget* window) -> void {
    window->draw(this->tile);
}


