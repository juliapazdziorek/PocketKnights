#include "MapTileAnimated.h"

//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTileAnimated::MapTileAnimated(Animation animation, bool isPassable)
    :  animation(animation) {
    this->isPassable = isPassable;
}

MapTileAnimated::~MapTileAnimated() = default;

// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTileAnimated::updateTexture() -> void {
    animation.updateFrame(animationClock);
    animation.applyTexture(tile);
}

auto MapTileAnimated::getTile() -> sf::Sprite& { return tile; }
auto MapTileAnimated::getAnimationClock() -> sf::Clock& { return animationClock; }

