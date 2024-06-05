#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include "Assets/MapTile.h"
#include "Assets/MapTileAnimated.h"
#include "Assets/Assets.h"

class Map {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    int tileSize;
    sf::Vector2f scale;
    std::vector<std::unique_ptr<MapTile>> mapTiles;
    std::vector<MapTileAnimated*> mapTilesAnimated;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto initializeTiles() -> void;
    auto initializeFoam() -> void;
    auto updateTextures() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Map();
    ~Map();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateState() -> void;
    auto render(sf::RenderTarget* window) -> void;

};

