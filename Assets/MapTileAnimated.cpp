#include "MapTileAnimated.h"

//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTileAnimated::MapTileAnimated(Animation& animation, bool isPassable)
    : animation(animation) {
    this->isPassable = isPassable;
}

// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTileAnimated::updateTextures() -> void {
    animation.updateFrame(animationClock);
    animation.applyTexture(tile);
}
