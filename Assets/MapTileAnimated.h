#pragma once

#include <SFML/Graphics.hpp>

#include "MapTile.h"
#include "Animation.h"

class MapTileAnimated : public MapTile {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    Animation animation;
    sf::Clock animationClock;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapTileAnimated(Animation animation, bool isPassable);
    ~MapTileAnimated();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateTexture() -> void;

};
