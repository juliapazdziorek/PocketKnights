#include "Map.h"

//private:

// ----- private methods -----------------------------------------------------------------------------------------------

auto Map::initializeTiles() -> void {
    initializeFoam();
}

auto Map::initializeFoam() -> void {

    auto foam = std::make_unique<MapTileAnimated>(Assets::getMapTileFoam());
    foam->setPosition(sf::Vector2f(0, 0));
    foam->setScale(scale);
    mapTilesAnimated.push_back(foam.get());
    mapTiles.push_back(std::move(foam));

    auto grass = std::make_unique<MapTile>(Assets::getMapTilesGrass()["MapTileGrass"]);
    grass->setPosition(sf::Vector2f(64, 0));
    grass->setScale(scale);
    mapTiles.push_back(std::move(grass));

}

auto Map::updateTextures() -> void {
    for (auto mapTileAnimated : mapTilesAnimated) {
        Assets::getFoamAnimation().updateFrame(mapTileAnimated->getAnimationClock());
        Assets::getFoamAnimation().applyTexture(mapTileAnimated->getTile());
    }
}


//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Map::Map()
    : tileSize(64), scale(sf::Vector2f(0.5f, 0.5f)) {
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





