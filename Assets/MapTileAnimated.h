#pragma once

#include <SFML/Graphics.hpp>

#include "MapTile.h"
#include "Animation.h"

class MapTileAnimated : public MapTile {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Clock animationClock;

    // ----- private methods -------------------------------------------------------------------------------------------
    virtual auto updateTexture() -> void = 0;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapTileAnimated();
    MapTileAnimated(bool isPassable);
    ~MapTileAnimated();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateState() -> void;

};
