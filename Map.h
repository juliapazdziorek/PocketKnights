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

    // ----- variables -------------------------------------------------------------------------------------------------

    // map tiles variables
    float tileSize;
    sf::Vector2f scale;

    // containers
    std::vector<std::unique_ptr<Collidable>> mapBorders;
    std::vector<MapBorder*> mapBordersToRender;
    std::vector<std::unique_ptr<MapTile>> mapTiles;
    std::vector<MapTileAnimated*> mapTilesAnimated;

    // ----- private methods -------------------------------------------------------------------------------------------

    // initialize map objects
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

    // create map objects
    auto createMapBorder(float width, float height, float x, float y) -> void;
    auto createFoam(float x, float y) -> void;
    auto createStaticMapTile(float x, float y, MapTile const& asset) -> void;

    // update textures on the map
    auto updateTextures() -> void;



public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    Map();

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // update state
    auto updateState() -> void;

    // getters

    auto getMapBorders() -> std::vector<std::unique_ptr<Collidable>>&;

};
