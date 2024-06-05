#pragma once

#include <SFML/Graphics.hpp>

#include "MapTile.h"
#include "Animation.h"

class MapTileAnimated : public MapTile {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Clock animationClock;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapTileAnimated(bool isPassable);
    ~MapTileAnimated();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto getTile() -> sf::Sprite&;
    auto getAnimationClock() -> sf::Clock&;

};
