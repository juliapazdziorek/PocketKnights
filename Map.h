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
    float tileSize;
    sf::Vector2f scale;
    std::vector<std::unique_ptr<MapTile>> mapTiles;
    std::vector<MapTileAnimated*> mapTilesAnimated;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto initializeTiles() -> void;

    auto initializeFoam() -> void;
    auto initializeSand() -> void;
    auto initializeWallsFirstLayer() -> void;
    auto initializeSandDetail() -> void;
    auto initializeGrassFirstLayer() -> void;
//    auto initializeWallSecondLayer
//    auto initializeGrassDetail
//    auto initializeGrassSecondLayer
//    auto initializeBridges

    //TODO Shadows
    //TODO wall layer under grass

    auto createFoam(float x, float y) -> void;
    auto createStaticMapTile(float x, float y, MapTile& asset) -> void;

    auto updateTextures() -> void;



public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Map();
    ~Map();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateState() -> void;
    auto render(sf::RenderTarget* window) -> void;

};

