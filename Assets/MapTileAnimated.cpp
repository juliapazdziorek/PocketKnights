#include "MapTileAnimated.h"

//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTileAnimated::MapTileAnimated(bool isPassable) {
    this->isPassable = isPassable;
}

MapTileAnimated::~MapTileAnimated() = default;

// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTileAnimated::getTile() -> sf::Sprite& { return tile; }
auto MapTileAnimated::getAnimationClock() -> sf::Clock& { return animationClock; }

