#pragma once

#include <SFML/Graphics.hpp>

#include "MapTile.h"
#include "Animation.h"

class MapTileAnimated : public MapTile {

private:

    // ----- variables -------------------------------------------------------------------------------------------------
    Animation animation;
    sf::Clock animationClock;

public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    MapTileAnimated(Animation& animation);

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateTextures() -> void;

};
