#include "MapTileAnimated.h"

//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

MapTileAnimated::MapTileAnimated() = default;

MapTileAnimated::MapTileAnimated(bool isPassable) {
    this->isPassable = isPassable;
}

MapTileAnimated::~MapTileAnimated() = default;

// ----- public methods ------------------------------------------------------------------------------------------------

auto MapTileAnimated::updateState() -> void {
    updateTexture();
}

