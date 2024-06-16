#include "MapTileAnimated.h"

//public:

// ----- constructor ---------------------------------------------------------------------------------------------------

MapTileAnimated::MapTileAnimated(Animation& animation)
    : animation(animation) {}


// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTileAnimated::updateTextures() -> void {
    animation.updateFrame(animationClock);
    animation.applyTexture(tile);
}
