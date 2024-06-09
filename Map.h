#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include "Assets/MapBorder.h"
#include "Assets/MapTile.h"
#include "Assets/MapTileAnimated.h"
#include "Assets/Assets.h"

class Map {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    float tileSize;
    sf::Vector2f scale;
    std::vector<Collidable*> mapBorders;
    std::vector<MapBorder> mapBordersToRender;
    std::vector<std::unique_ptr<MapTile>> mapTiles;
    std::vector<MapTileAnimated*> mapTilesAnimated;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto initializeMapBorders() -> void;

    auto initializeTiles() -> void;
    auto initializeFoam() -> void;
    auto initializeSand() -> void;
    auto initializeShadowsFirstLayer() -> void;
    auto initializeWallsFirstLayer() -> void;
    auto initializeSandDetail() -> void;
    auto initializeWallFlorFirstLayer() -> void;
    auto initializeGrassFirstLayer() -> void;
    auto initializeShadowsSecondLayer() -> void;
    auto initializeGrassDetail() -> void;
    auto initializeWallSecondLayer() -> void;
    auto initializeWallFlorSecondLayer() -> void;
    auto initializeGrassSecondLayer() -> void;
    auto initializeBridges() -> void;

    auto createMapBorder(float width, float height, float x, float y) -> void;
    auto createFoam(float x, float y) -> void;
    auto createStaticMapTile(float x, float y, MapTile const& asset) -> void;

    auto updateTextures() -> void;



public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Map();
    ~Map();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateState() -> void;
    auto render(sf::RenderTarget* window) -> void;

    auto getMapTilesMap() -> std::vector<std::unique_ptr<MapTile>>&;
    auto getMapBorders() -> std::vector<Collidable*>&;

};

