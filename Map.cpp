#include "Map.h"

//private:

// ----- private methods -----------------------------------------------------------------------------------------------

auto Map::initializeTiles() -> void {
    //initializeFoam();
    initializeSand();
    initializeWallsFirstLayer();
    initializeSandDetail();
    initializeGrassFirstLayer();
}

auto Map::initializeFoam() -> void {
    createFoam(-1, 11);
    createFoam(0, 10);
    createFoam(0, 9);
    createFoam(0, 8);
    createFoam(0, 7);
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

auto Map::initializeSand() -> void {
    createStaticMapTile(0, 12, Assets::getMapTilesSand()["MapTileSandCornerRightDown"]);
    createStaticMapTile(1, 11, Assets::getMapTilesSand()["MapTileSandCornerRightDown"]);
    createStaticMapTile(1, 10, Assets::getMapTilesSand()["MapTileSandBorderRight"]);
    createStaticMapTile(4, 9, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(5, 9, Assets::getMapTilesSand()["MapTileSandMiddle"]);
    createStaticMapTile(5, 10, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(6, 10, Assets::getMapTilesSand()["MapTileSandBorderDown"]);
    createStaticMapTile(7, 10, Assets::getMapTilesSand()["MapTileSandBorderDown"]);
    createStaticMapTile(10, 12, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(11, 13, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(12, 14, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(13, 16, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(9, 18, Assets::getMapTilesSand()["MapTileSandCornerRightDown"]);
    createStaticMapTile(23, 16, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(24, 17, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(25, 17, Assets::getMapTilesSand()["MapTileSandBorderDown"]);

}

auto Map::initializeWallsFirstLayer() -> void {
    createStaticMapTile(0, 11, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(1, 9, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(3, 6, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(4, 8, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(5, 8, Assets::getMapTilesStairs()["MapTileStairs"]);
    createStaticMapTile(6, 9, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(7, 9, Assets::getMapTilesStairs()["MapTileStairs"]);
    createStaticMapTile(8, 11, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(9, 11, Assets::getMapTilesWall()["MapTileWallWallMiddle"]);
    createStaticMapTile(10, 11, Assets::getMapTilesWall()["MapTileWallWallMiddle"]);
    createStaticMapTile(11, 12, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(12, 13, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(13, 15, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(14, 17, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(15, 17, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(16, 16, Assets::getMapTilesWall()["MapTileWallWallMiddle"]);
    createStaticMapTile(17, 16, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(18, 15, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(19, 10, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(20, 8, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(22, 14, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(23, 15, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(24, 16, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(25, 16, Assets::getMapTilesWall()["MapTileWallWallMiddle"]);
    createStaticMapTile(5, 17, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(6, 18, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(7, 18, Assets::getMapTilesWall()["MapTileWallWallMiddle"]);
    createStaticMapTile(8, 18, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(9, 17, Assets::getMapTilesWall()["MapTileWallWallMiddle"]);
    createStaticMapTile(10, 17, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(10, 2, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(11, 4, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(12, 5, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(13, 5, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(14, 4, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(15, 1, Assets::getMapTilesWall()["MapTileWallWallRight"]);

}

auto Map::initializeSandDetail() -> void {
    createStaticMapTile(0, 11, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(1, 9, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(4, 8, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(6, 9, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(10, 11, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(11, 12, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(12, 13, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(13, 15, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(9, 17, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(23, 15, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(24, 16, Assets::getMapTilesSand()["MapTileSandWall"]);
    createStaticMapTile(25, 16, Assets::getMapTilesSand()["MapTileSandWall"]);

}

auto Map::initializeGrassFirstLayer() -> void {
    createStaticMapTile(0, 6, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(0, 7, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(0, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(0, 9, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(0, 10, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(1, 7, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(1, 8, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(4, 7, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(5, 7, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(6, 6, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(6, 7, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(6, 8, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(7, 5, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(7, 6, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(7, 7, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(7, 8, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(8, 4, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(8, 5, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(8, 6, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(8, 7, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(8, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(8, 9, Assets::getMapTilesGrass()["MapTileGrassBorderLeft"]);
    createStaticMapTile(8, 10, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(9, 6, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(9, 7, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(9, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(9, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(9, 10, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(10, 7, Assets::getMapTilesGrass()["MapTileGrassBorderUp"]);
    createStaticMapTile(10, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(10, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(10, 10, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(11, 7, Assets::getMapTilesGrass()["MapTileGrassBorderUp"]);
    createStaticMapTile(11, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(11, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(11, 10, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(11, 11, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(12, 7, Assets::getMapTilesGrass()["MapTileGrassBorderUp"]);
    createStaticMapTile(12, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(12, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(12, 10, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(12, 11, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(12, 12, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(13, 7, Assets::getMapTilesGrass()["MapTileGrassBorderUp"]);
    createStaticMapTile(13, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 10, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 11, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 13, Assets::getMapTilesGrass()["MapTileGrassBorderLeft"]);
    createStaticMapTile(13, 14, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(14, 7, Assets::getMapTilesGrass()["MapTileGrassBorderUp"]);
    createStaticMapTile(14, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 10, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 11, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 13, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 15, Assets::getMapTilesGrass()["MapTileGrassBorderLeft"]);
    createStaticMapTile(14, 16, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(15, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 10, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 11, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 13, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 15, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 16, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(16, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(16, 10, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(16, 11, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(16, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(16, 13, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(16, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(16, 15, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(17, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(17, 10, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(17, 11, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(17, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(17, 13, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(17, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(17, 15, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(18, 9, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(18, 10, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(18, 11, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(18, 12, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(18, 13, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(18, 14, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(19, 9, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(5, 15, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(5, 16, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(6, 14, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(6, 15, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(6, 16, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(6, 17, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(7, 13, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(7, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(7, 15, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(7, 16, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(7, 17, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(8, 13, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(8, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(8, 15, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(8, 16, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(8, 17, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(9, 14, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(9, 15, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(9, 16, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(10, 16, Assets::getMapTilesGrass()["MapTileGrassEndRight"]);
    createStaticMapTile(11, 2, Assets::getMapTilesGrass()["MapTileGrassBorderLeft"]);
    createStaticMapTile(11, 3, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(12, 3, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(12, 4, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(13, 3, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 4, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(14, 2, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(14, 3, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(22, 12, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(22, 13, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(23, 11, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(23, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(23, 13, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(23, 14, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(24, 11, Assets::getMapTilesGrass()["MapTileGrassBorderUp"]);
    createStaticMapTile(24, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(24, 13, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(24, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(24, 15, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(25, 10, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(25, 11, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(25, 12, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(25, 13, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(25, 14, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(25, 15, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);

}





auto Map::createFoam(float x, float y) -> void {
    auto foam = std::make_unique<MapTileAnimated>(Assets::getMapTileFoam());
    foam->setPosition(sf::Vector2f(x * tileSize, y * tileSize));
    foam->setScale(scale);
    mapTilesAnimated.push_back(foam.get());
    mapTiles.push_back(std::move(foam));
}

auto Map::createStaticMapTile(float x, float y, MapTile& asset) -> void {
    auto mapTile = std::make_unique<MapTile>(asset);
    mapTile->setPosition(sf::Vector2f(x * tileSize, y * tileSize));
    mapTile->setScale(scale);
    mapTiles.push_back(std::move(mapTile));
}

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


