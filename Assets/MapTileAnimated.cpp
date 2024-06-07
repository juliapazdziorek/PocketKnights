#include "MapTileAnimated.h"

//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTileAnimated::MapTileAnimated(Animation& animation, bool isPassable)
    : animation(animation) {
    this->isPassable = isPassable;
}

// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTileAnimated::getTile() -> sf::Sprite& { return tile; }
auto MapTileAnimated::getAnimationClock() -> sf::Clock& { return animationClock; }

auto MapTileAnimated::updateTextures() -> void {
    animation.updateFrame(animationClock);
    animation.applyTexture(tile);
}
