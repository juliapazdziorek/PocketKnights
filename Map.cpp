#include "Map.h"

//private:

// ----- private methods -----------------------------------------------------------------------------------------------

auto Map::initializeTiles() -> void {
    initializeFoam();
}

auto Map::initializeFoam() -> void {
    createFoam(-1, 11);
    createFoam(0, 10);
    createFoam(0, 9);
    createFoam(0, 8);
    createFoam(0, 7);
    createFoam(0, 6);

    createFoam(2, 5);
    createFoam(3, 6);
    createFoam(3, 7);
    createFoam(3, 8);
    createFoam(3, 8);
    createFoam(4, 9);
    createFoam(5, 9);
    createFoam(6, 9);
    createFoam(7, 10);
    createFoam(8, 10);
    createFoam(9, 11);
    createFoam(10, 12);
    createFoam(11, 13);
    createFoam(12, 14);
    createFoam(12, 15);
    createFoam(13, 16);
    createFoam(14, 16);
    createFoam(15, 15);
    createFoam(16, 15);
    createFoam(17, 14);
    createFoam(17, 13);
    createFoam(17, 12);
    createFoam(17, 11);
    createFoam(17, 10);
    createFoam(18, 9);
    createFoam(18, 8);
    createFoam(19, 7);
    createFoam(19, 6);

    createFoam(4, 15);
    createFoam(4, 16);
    createFoam(5, 17);
    createFoam(6, 17);
    createFoam(7, 17);
    createFoam(8, 17);
    createFoam(9, 16);
    createFoam(9, 15);
    createFoam(8, 14);

    createFoam(21, 13);
    createFoam(22, 14);
    createFoam(22, 15);
    createFoam(23, 16);
    createFoam(24, 16);

    createFoam(9, 1);
    createFoam(10, 2);
    createFoam(10, 3);
    createFoam(11, 4);
    createFoam(12, 4);
    createFoam(13, 3);
    createFoam(13, 2);
    createFoam(13, 1);
    createFoam(14, 0);

}

auto Map::createFoam(float x, float y) -> void {
    auto foam = std::make_unique<MapTileAnimated>(Assets::getMapTileFoam());
    foam->setPosition(sf::Vector2f(x * tileSize, y * tileSize));
    foam->setScale(scale);
    mapTilesAnimated.push_back(foam.get());
    mapTiles.push_back(std::move(foam));
}

/*auto grass = std::make_unique<MapTile>(Assets::getMapTilesGrass()["MapTileGrass"]);
    grass->setPosition(sf::Vector2f(589, 79));
    grass->setScale(scale);
    mapTiles.push_back(std::move(grass));*/

auto Map::updateTextures() -> void {
    for (auto mapTileAnimated : mapTilesAnimated) {
        Assets::getAnimationFoam().updateFrame(mapTileAnimated->getAnimationClock());
        Assets::getAnimationFoam().applyTexture(mapTileAnimated->getTile());
    }
}


//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Map::Map()
    : tileSize(32), scale(sf::Vector2f(0.5f, 0.5f)) {
    initializeTiles();
}

Map::~Map() {

}



// ----- public methods --------------------------------------------------------------------------------------------

auto Map::updateState() -> void {
    updateTextures();
}

auto Map::render(sf::RenderTarget *window) -> void {
    for (auto& mapTile : mapTiles) {
        mapTile -> render(window);
    }
}

