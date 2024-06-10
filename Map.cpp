#include "Map.h"

//private:

// ----- private methods -----------------------------------------------------------------------------------------------

auto Map::initializeMapBorders() -> void {

    // horizontal borders
    createMapBorder(1 * tileSize, 1, 0 * tileSize, 6 * tileSize);
    createMapBorder(5 * tileSize, 1, 1 * tileSize, 7 * tileSize);
    createMapBorder(1 * tileSize, 1, 1 * tileSize, 9 * tileSize);
    createMapBorder(1 * tileSize, 1, 0 * tileSize, 11 * tileSize);
    createMapBorder(3 * tileSize, 1, 2 * tileSize, 8 * tileSize);
    createMapBorder(1 * tileSize, 1, 6 * tileSize, 6 * tileSize);
    createMapBorder(1 * tileSize, 1, 7 * tileSize, 5 * tileSize);
    createMapBorder(1 * tileSize, 1, 8 * tileSize, 4 * tileSize);
    createMapBorder(1 * tileSize, 1, 9 * tileSize, 6 * tileSize);
    createMapBorder(2 * tileSize, 1, 10 * tileSize, 7 * tileSize);
    createMapBorder(1 * tileSize, 1, 11 * tileSize, 4 * tileSize);
    createMapBorder(1 * tileSize, 1, 11 * tileSize, 2 * tileSize);
    createMapBorder(2 * tileSize, 1, 10 * tileSize, 1 * tileSize);
    createMapBorder(1 * tileSize, 1, 14 * tileSize, 1 * tileSize);
    createMapBorder(2 * tileSize, 1, 13 * tileSize, 2 * tileSize);
    createMapBorder(1 * tileSize, 1, 13 * tileSize, 3 * tileSize);
    createMapBorder(1 * tileSize, 1, 14 * tileSize, 4 * tileSize);
    createMapBorder(1 * tileSize, 1, 13 * tileSize, 5 * tileSize);
    createMapBorder(3 * tileSize, 1, 13 * tileSize, 7 * tileSize);
    createMapBorder(1 * tileSize, 1, 16 * tileSize, 6 * tileSize);
    createMapBorder(3 * tileSize, 1, 17 * tileSize, 5 * tileSize);
    createMapBorder(1 * tileSize, 1, 20 * tileSize, 6 * tileSize);
    createMapBorder(1 * tileSize, 1, 20 * tileSize, 7 * tileSize);
    createMapBorder(1 * tileSize, 1, 19 * tileSize, 8 * tileSize);
    createMapBorder(2 * tileSize, 1, 15 * tileSize, 8 * tileSize);
    createMapBorder(1 * tileSize, 1, 19 * tileSize, 10 * tileSize);
    createMapBorder(3 * tileSize, 1, 19 * tileSize, 13 * tileSize);
    createMapBorder(1 * tileSize, 1, 22 * tileSize, 12 * tileSize);
    createMapBorder(2 * tileSize, 1, 23 * tileSize, 11 * tileSize);
    createMapBorder(1 * tileSize, 1, 25 * tileSize, 10 * tileSize);
    createMapBorder(4 * tileSize, 1, 19 * tileSize, 14 * tileSize);
    createMapBorder(1 * tileSize, 1, 23 * tileSize, 15 * tileSize);
    createMapBorder(2 * tileSize, 1, 24 * tileSize, 16 * tileSize);
    createMapBorder(1 * tileSize, 1, 18 * tileSize, 15 * tileSize);
    createMapBorder(2 * tileSize, 1, 16 * tileSize, 16 * tileSize);
    createMapBorder(2 * tileSize, 1, 14 * tileSize, 17 * tileSize);
    createMapBorder(1 * tileSize, 1, 13 * tileSize, 15 * tileSize);
    createMapBorder(1 * tileSize, 1, 12 * tileSize, 13 * tileSize);
    createMapBorder(1 * tileSize, 1, 11 * tileSize, 12 * tileSize);
    createMapBorder(2 * tileSize, 1, 9 * tileSize, 11 * tileSize);
    createMapBorder(3 * tileSize, 1, 5 * tileSize, 11 * tileSize);
    createMapBorder(1 * tileSize, 1, 6 * tileSize, 10 * tileSize);
    createMapBorder(1 * tileSize, 1, 6 * tileSize, 9 * tileSize);
    createMapBorder(1 * tileSize, 1, 4 * tileSize, 9 * tileSize);
    createMapBorder(1 * tileSize, 1, 4 * tileSize, 10 * tileSize);
    createMapBorder(2 * tileSize, 1, 15 * tileSize, 9 * tileSize);
    createMapBorder(1 * tileSize, 1, 19 * tileSize, 9 * tileSize);
    createMapBorder(1 * tileSize, 1, 7 * tileSize, 13 * tileSize);
    createMapBorder(1 * tileSize, 1, 6 * tileSize, 14 * tileSize);
    createMapBorder(1 * tileSize, 1, 5 * tileSize, 15 * tileSize);
    createMapBorder(1 * tileSize, 1, 5 * tileSize, 17 * tileSize);
    createMapBorder(3 * tileSize, 1, 6 * tileSize, 18 * tileSize);
    createMapBorder(2 * tileSize, 1, 9 * tileSize, 17 * tileSize);
    createMapBorder(1 * tileSize, 1, 10 * tileSize, 16 * tileSize);
    createMapBorder(1 * tileSize, 1, 9 * tileSize, 14 * tileSize);


    // vertical borders
    createMapBorder(1, 1 * tileSize, 1 * tileSize, 6 * tileSize);
    createMapBorder(1, 2 * tileSize, 1 * tileSize, 9 * tileSize);
    createMapBorder(1, 1 * tileSize, 2 * tileSize, 8 * tileSize);
    createMapBorder(1, 2 * tileSize, 4 * tileSize, 8 * tileSize);
    createMapBorder(1, 1 * tileSize, 5 * tileSize, 8 * tileSize);
    createMapBorder(1, 1 * tileSize, 5 * tileSize, 10 * tileSize);
    createMapBorder(1, 2 * tileSize, 6 * tileSize, 8 * tileSize);
    createMapBorder(1, 1 * tileSize, 7 * tileSize, 9 * tileSize);
    createMapBorder(1, 4 * tileSize, 8 * tileSize, 9 * tileSize);
    createMapBorder(1, 1 * tileSize, 7 * tileSize, 13 * tileSize);
    createMapBorder(1, 1 * tileSize, 6 * tileSize, 14 * tileSize);
    createMapBorder(1, 2 * tileSize, 5 * tileSize, 15 * tileSize);
    createMapBorder(1, 1 * tileSize, 6 * tileSize, 17 * tileSize);
    createMapBorder(1, 1 * tileSize, 9 * tileSize, 17 * tileSize);
    createMapBorder(1, 1 * tileSize, 11 * tileSize, 16 * tileSize);
    createMapBorder(1, 2 * tileSize, 10 * tileSize, 14 * tileSize);
    createMapBorder(1, 3 * tileSize, 9 * tileSize, 11 * tileSize);
    createMapBorder(1, 1 * tileSize, 11 * tileSize, 11 * tileSize);
    createMapBorder(1, 1 * tileSize, 12 * tileSize, 12 * tileSize);
    createMapBorder(1, 2 * tileSize, 13 * tileSize, 13 * tileSize);
    createMapBorder(1, 2 * tileSize, 14 * tileSize, 15 * tileSize);
    createMapBorder(1, 1 * tileSize, 16 * tileSize, 16 * tileSize);
    createMapBorder(1, 1 * tileSize, 18 * tileSize, 15 * tileSize);
    createMapBorder(1, 1 * tileSize, 19 * tileSize, 14 * tileSize);
    createMapBorder(1, 1 * tileSize, 23 * tileSize, 14 * tileSize);
    createMapBorder(1, 1 * tileSize, 24 * tileSize, 15 * tileSize);
    createMapBorder(1, 1 * tileSize, 22 * tileSize, 12 * tileSize);
    createMapBorder(1, 1 * tileSize, 23 * tileSize, 11 * tileSize);
    createMapBorder(1, 1 * tileSize, 25 * tileSize, 10 * tileSize);
    createMapBorder(1, 3 * tileSize, 19 * tileSize, 10 * tileSize);
    createMapBorder(1, 1 * tileSize, 19 * tileSize, 8 * tileSize);
    createMapBorder(1, 3 * tileSize, 20 * tileSize, 7 * tileSize);
    createMapBorder(1, 1 * tileSize, 21 * tileSize, 6 * tileSize);
    createMapBorder(1, 1 * tileSize, 20 * tileSize, 5 * tileSize);
    createMapBorder(1, 1 * tileSize, 17 * tileSize, 5 * tileSize);
    createMapBorder(1, 1 * tileSize, 16 * tileSize, 6 * tileSize);
    createMapBorder(1, 2 * tileSize, 15 * tileSize, 7 * tileSize);
    createMapBorder(1, 1 * tileSize, 17 * tileSize, 8 * tileSize);
    createMapBorder(1, 2 * tileSize, 13 * tileSize, 5 * tileSize);
    createMapBorder(1, 3 * tileSize, 12 * tileSize, 4 * tileSize);
    createMapBorder(1, 2 * tileSize, 11 * tileSize, 2 * tileSize);
    createMapBorder(1, 2 * tileSize, 12 * tileSize, 1 * tileSize);
    createMapBorder(1, 1 * tileSize, 10 * tileSize, 0 * tileSize);
    createMapBorder(1, 1 * tileSize, 13 * tileSize, 2 * tileSize);
    createMapBorder(1, 2 * tileSize, 14 * tileSize, 1 * tileSize);
    createMapBorder(1, 1 * tileSize, 15 * tileSize, 0 * tileSize);
    createMapBorder(1, 2 * tileSize, 15 * tileSize, 2 * tileSize);
    createMapBorder(1, 1 * tileSize, 14 * tileSize, 4 * tileSize);
    createMapBorder(1, 1 * tileSize, 10 * tileSize, 6 * tileSize);
    createMapBorder(1, 2 * tileSize, 9 * tileSize, 4 * tileSize);
    createMapBorder(1, 1 * tileSize, 8 * tileSize, 4 * tileSize);
    createMapBorder(1, 1 * tileSize, 7 * tileSize, 5 * tileSize);
    createMapBorder(1, 1 * tileSize, 6 * tileSize, 6 * tileSize);

}


auto Map::initializeTiles() -> void {
    initializeFoam();
    initializeSand();
    initializeShadowsFirstLayer();
    initializeWallsFirstLayer();
    initializeSandDetail();
    initializeWallFlorFirstLayer();
    initializeGrassFirstLayer();
    initializeShadowsSecondLayer();
    initializeWallSecondLayer();
    initializeGrassDetail();
    initializeWallFlorSecondLayer();
    initializeGrassSecondLayer();
    initializeBridges();
}

//initialize mapTiles vector

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
    createFoam(4, 15);
    createFoam(4, 16);
    createFoam(5, 17);
    createFoam(6, 17);
    createFoam(7, 17);
    createFoam(8, 17);
    createFoam(9, 16);
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

    // west island
    createStaticMapTile(0, 12, Assets::getMapTilesSand()["MapTileSandCornerRightDown"]);
    createStaticMapTile(1, 11, Assets::getMapTilesSand()["MapTileSandCornerRightDown"]);
    createStaticMapTile(1, 10, Assets::getMapTilesSand()["MapTileSandBorderRight"]);

    // center island
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

    // east island
    createStaticMapTile(23, 16, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(24, 17, Assets::getMapTilesSand()["MapTileSandCornerLeftDown"]);
    createStaticMapTile(25, 17, Assets::getMapTilesSand()["MapTileSandBorderDown"]);

}

auto Map::initializeShadowsFirstLayer() -> void {
    createStaticMapTile(-1, 10, Assets::getMapTileShadow());
    createStaticMapTile(-1, 9, Assets::getMapTileShadow());
    createStaticMapTile(0, 8, Assets::getMapTileShadow());
    createStaticMapTile(0, 7, Assets::getMapTileShadow());
    createStaticMapTile(2, 5, Assets::getMapTileShadow());
    createStaticMapTile(3, 6, Assets::getMapTileShadow());
    createStaticMapTile(3, 7, Assets::getMapTileShadow());
    createStaticMapTile(4, 7, Assets::getMapTileShadow());
    createStaticMapTile(5, 8, Assets::getMapTileShadow());
    createStaticMapTile(6, 8, Assets::getMapTileShadow());
    createStaticMapTile(7, 9, Assets::getMapTileShadow());
    createStaticMapTile(7, 10, Assets::getMapTileShadow());
    createStaticMapTile(8, 10, Assets::getMapTileShadow());
    createStaticMapTile(9, 10, Assets::getMapTileShadow());
    createStaticMapTile(10, 11, Assets::getMapTileShadow());
    createStaticMapTile(11, 12, Assets::getMapTileShadow());
    createStaticMapTile(12, 13, Assets::getMapTileShadow());
    createStaticMapTile(12, 14, Assets::getMapTileShadow());
    createStaticMapTile(13, 15, Assets::getMapTileShadow());
    createStaticMapTile(13, 16, Assets::getMapTileShadow());
    createStaticMapTile(14, 16, Assets::getMapTileShadow());
    createStaticMapTile(15, 15, Assets::getMapTileShadow());
    createStaticMapTile(16, 15, Assets::getMapTileShadow());
    createStaticMapTile(17, 14, Assets::getMapTileShadow());
    createStaticMapTile(17, 13, Assets::getMapTileShadow());
    createStaticMapTile(17, 12, Assets::getMapTileShadow());
    createStaticMapTile(17, 11, Assets::getMapTileShadow());
    createStaticMapTile(17, 10, Assets::getMapTileShadow());
    createStaticMapTile(18, 9, Assets::getMapTileShadow());
    createStaticMapTile(18, 8, Assets::getMapTileShadow());
    createStaticMapTile(19, 7, Assets::getMapTileShadow());
    createStaticMapTile(4, 16, Assets::getMapTileShadow());
    createStaticMapTile(5, 17, Assets::getMapTileShadow());
    createStaticMapTile(6, 17, Assets::getMapTileShadow());
    createStaticMapTile(7, 17, Assets::getMapTileShadow());
    createStaticMapTile(8, 16, Assets::getMapTileShadow());
    createStaticMapTile(9, 16, Assets::getMapTileShadow());
    createStaticMapTile(9, 1, Assets::getMapTileShadow());
    createStaticMapTile(10, 2, Assets::getMapTileShadow());
    createStaticMapTile(10, 3, Assets::getMapTileShadow());
    createStaticMapTile(11, 4, Assets::getMapTileShadow());
    createStaticMapTile(12, 4, Assets::getMapTileShadow());
    createStaticMapTile(13, 3, Assets::getMapTileShadow());
    createStaticMapTile(13, 2, Assets::getMapTileShadow());
    createStaticMapTile(13, 1, Assets::getMapTileShadow());
    createStaticMapTile(14, 0, Assets::getMapTileShadow());
    createStaticMapTile(14, 0, Assets::getMapTileShadow());

    //east island
    createStaticMapTile(21, 12, Assets::getMapTileShadow());
    createStaticMapTile(21, 13, Assets::getMapTileShadow());
    createStaticMapTile(22, 14, Assets::getMapTileShadow());
    createStaticMapTile(23, 15, Assets::getMapTileShadow());
    createStaticMapTile(24, 15, Assets::getMapTileShadow());

    //bridges
    createStaticMapTile(2, 7, Assets::getMapTilesBridge()["MapTileBridgeShadow"]);
    createStaticMapTile(3, 7, Assets::getMapTilesBridge()["MapTileBridgeShadow"]);
    createStaticMapTile(19, 13, Assets::getMapTilesBridge()["MapTileBridgeShadow"]);
    createStaticMapTile(20, 13, Assets::getMapTilesBridge()["MapTileBridgeShadow"]);
    createStaticMapTile(21, 13, Assets::getMapTilesBridge()["MapTileBridgeShadow"]);

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

auto Map::initializeWallFlorFirstLayer() -> void {

    //west island
    createStaticMapTile(0, 6, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(1, 7, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(1, 8, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(0, 9, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(0, 10, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);

    //south island
    createStaticMapTile(7, 13, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(8, 13, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(6, 14, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(9, 14, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(5, 15, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(9, 15, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(5, 16, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(9, 16, Assets::getMapTilesWall()["MapTileWallBordersUpDown"]);
    createStaticMapTile(10, 16, Assets::getMapTilesWall()["MapTileWallEndRight"]);
    createStaticMapTile(6, 17, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(7, 17, Assets::getMapTilesWall()["MapTileWallBordersUpDown"]);
    createStaticMapTile(8, 17, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);

    //north island
    createStaticMapTile(10, 1, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(11, 2, Assets::getMapTilesWall()["MapTileWallBorderLeft"]);
    createStaticMapTile(11, 3, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(12, 4, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(13, 4, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(14, 3, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(14, 2, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(15, 0, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);

    //east island
    createStaticMapTile(25, 10, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(24, 11, Assets::getMapTilesWall()["MapTileWallBorderUp"]);
    createStaticMapTile(23, 11, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(22, 12, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(22, 13, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(23, 14, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(24, 15, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(25, 15, Assets::getMapTilesWall()["MapTileWallBorderDown"]);


    //central island
    createStaticMapTile(3, 5, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(4, 7, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(5, 7, Assets::getMapTilesWall()["MapTileWallBorderDown"]);
    createStaticMapTile(6, 8, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(7, 8, Assets::getMapTilesWall()["MapTileWallBorderDown"]);
    createStaticMapTile(8, 9, Assets::getMapTilesWall()["MapTileWallBorderLeft"]);
    createStaticMapTile(8, 10, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(9, 10, Assets::getMapTilesWall()["MapTileWallBorderDown"]);
    createStaticMapTile(10, 10, Assets::getMapTilesWall()["MapTileWallBorderDown"]);
    createStaticMapTile(11, 11, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(12, 12, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(13, 13, Assets::getMapTilesWall()["MapTileWallBorderLeft"]);
    createStaticMapTile(13, 14, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(14, 15, Assets::getMapTilesWall()["MapTileWallBorderLeft"]);
    createStaticMapTile(14, 16, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(15, 16, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(16, 15, Assets::getMapTilesWall()["MapTileWallBorderDown"]);
    createStaticMapTile(17, 15, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(18, 14, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(18, 13, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(18, 12, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(18, 11, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(18, 10, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(19, 9, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(20, 7, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(8, 4, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(8, 5, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(9, 6, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(10, 7, Assets::getMapTilesWall()["MapTileWallBorderUp"]);
    createStaticMapTile(11, 7, Assets::getMapTilesWall()["MapTileWallBorderUp"]);
    createStaticMapTile(12, 7, Assets::getMapTilesWall()["MapTileWallBorderUp"]);
    createStaticMapTile(13, 7, Assets::getMapTilesWall()["MapTileWallBorderUp"]);
    createStaticMapTile(14, 7, Assets::getMapTilesWall()["MapTileWallBorderUp"]);

}

auto Map::initializeGrassFirstLayer() -> void {

    //west island
    createStaticMapTile(0, 6, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(0, 7, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(0, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(0, 9, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(0, 10, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(1, 7, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(1, 8, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);

    //central island
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
    createStaticMapTile(4, 6, Assets::getMapTilesGrass()["MapTileGrassBorderLeft"]);
    createStaticMapTile(5, 6, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(6, 5, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(7, 4, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(15, 7, Assets::getMapTilesGrass()["MapTileGrassBorderUp"]);
    createStaticMapTile(15, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(16, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(17, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(18, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(19, 8, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);

    //south island
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

    //north island
    createStaticMapTile(11, 2, Assets::getMapTilesGrass()["MapTileGrassBorderLeft"]);
    createStaticMapTile(11, 3, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(12, 3, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(12, 4, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(13, 3, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 4, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(14, 2, Assets::getMapTilesGrass()["MapTileGrassBorderRight"]);
    createStaticMapTile(14, 3, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(11, 1, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(12, 2, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(13, 2, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(14, 1, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);

    //east island
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

auto Map::initializeShadowsSecondLayer() -> void {

    //central island
    createStaticMapTile(3, 5, Assets::getMapTileShadow());
    createStaticMapTile(4, 5, Assets::getMapTileShadow());
    createStaticMapTile(5, 4, Assets::getMapTileShadow());
    createStaticMapTile(6, 3, Assets::getMapTileShadow());
    createStaticMapTile(14, 7, Assets::getMapTileShadow());
    createStaticMapTile(15, 7, Assets::getMapTileShadow());
    createStaticMapTile(18, 7, Assets::getMapTileShadow());

    //north island
    createStaticMapTile(10, 0, Assets::getMapTileShadow());
    createStaticMapTile(12, 1, Assets::getMapTileShadow());
    createStaticMapTile(13, 0, Assets::getMapTileShadow());

}

auto Map::initializeWallSecondLayer() -> void {
    createStaticMapTile(3, 5, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(4, 6, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(5, 6, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(6, 5, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(7, 4, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(15, 8, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(16, 8, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(17, 8, Assets::getMapTilesStairs()["MapTileStairsLeft"]);
    createStaticMapTile(18, 8, Assets::getMapTilesStairs()["MapTileStairsRight"]);
    createStaticMapTile(19, 8, Assets::getMapTilesWall()["MapTileWallWall"]);
    createStaticMapTile(20, 7, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(10, 1, Assets::getMapTilesWall()["MapTileWallWallLeft"]);
    createStaticMapTile(11, 1, Assets::getMapTilesWall()["MapTileWallWallMiddle"]);
    createStaticMapTile(12, 2, Assets::getMapTilesStairs()["MapTileStairs"]);
    createStaticMapTile(13, 2, Assets::getMapTilesWall()["MapTileWallWall"]);
    createStaticMapTile(14, 1, Assets::getMapTilesWall()["MapTileWallWallRight"]);
    createStaticMapTile(15, 0, Assets::getMapTilesWall()["MapTileWallWallRight"]);

}

auto Map::initializeGrassDetail() -> void {
    createStaticMapTile(4, 6, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(5, 6, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(6, 5, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(7, 4, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(15, 8, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(16, 8, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(19, 8, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(11, 1, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(13, 2, Assets::getMapTilesGrass()["MapTileGrassWall"]);
    createStaticMapTile(14, 1, Assets::getMapTilesGrass()["MapTileGrassWall"]);
}

auto Map::initializeWallFlorSecondLayer() -> void {

    //central island
    createStaticMapTile(3, 4, Assets::getMapTilesWall()["MapTileWallEndLeft"]);
    createStaticMapTile(4, 3, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(5,2, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(4,5, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(5,5, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(6,4, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(7,3, Assets::getMapTilesWall()["MapTileWallEndRight"]);
    createStaticMapTile(6,2, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(4,4, Assets::getMapTilesWall()["MapTileWallMiddle"]);
    createStaticMapTile(5,3, Assets::getMapTilesWall()["MapTileWallMiddle"]);
    createStaticMapTile(17,5, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(18,5, Assets::getMapTilesWall()["MapTileWallBorderUp"]);
    createStaticMapTile(19,5, Assets::getMapTilesWall()["MapTileWallCornerRightUp"]);
    createStaticMapTile(18,6, Assets::getMapTilesWall()["MapTileWallMiddle"]);
    createStaticMapTile(19,6, Assets::getMapTilesWall()["MapTileWallMiddle"]);
    createStaticMapTile(20,6, Assets::getMapTilesWall()["MapTileWallEndRight"]);
    createStaticMapTile(19,7, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(15,7, Assets::getMapTilesWall()["MapTileWallEndLeft"]);
    createStaticMapTile(16,7, Assets::getMapTilesWall()["MapTileWallBorderDown"]);
    createStaticMapTile(16,6, Assets::getMapTilesWall()["MapTileWallCornerLeftUp"]);
    createStaticMapTile(17,6, Assets::getMapTilesWall()["MapTileWallMiddle"]);
    createStaticMapTile(17,7, Assets::getMapTilesWall()["MapTileWallMiddle"]);
    createStaticMapTile(18,7, Assets::getMapTilesWall()["MapTileWallMiddle"]);

    //north island
    createStaticMapTile(10,0, Assets::getMapTilesWall()["MapTileWallCornerLeftDown"]);
    createStaticMapTile(11,0, Assets::getMapTilesWall()["MapTileWallBorderDown"]);
    createStaticMapTile(12,0, Assets::getMapTilesWall()["MapTileWallMiddle"]);
    createStaticMapTile(14,0, Assets::getMapTilesWall()["MapTileWallCornerRightDown"]);
    createStaticMapTile(12,1, Assets::getMapTilesWall()["MapTileWallBorderLeft"]);
    createStaticMapTile(13,1, Assets::getMapTilesWall()["MapTileWallBorderRight"]);
    createStaticMapTile(13,0, Assets::getMapTilesWall()["MapTileWallMiddle"]);

}

auto Map::initializeGrassSecondLayer() -> void {
    createStaticMapTile(4, 4, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(4, 5, Assets::getMapTilesGrass()["MapTileGrassCornerLeftDown"]);
    createStaticMapTile(5, 3, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(5, 4, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(5, 5, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(6, 2, Assets::getMapTilesGrass()["MapTileGrassEndUp"]);
    createStaticMapTile(6, 3, Assets::getMapTilesGrass()["MapTileGrassMiddle"]);
    createStaticMapTile(6, 4, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(7, 3, Assets::getMapTilesGrass()["MapTileGrassEndRight"]);

    createStaticMapTile(12, 1, Assets::getMapTilesGrass()["MapTileGrassEndLeft"]);
    createStaticMapTile(13, 1, Assets::getMapTilesGrass()["MapTileGrassCornerRightDown"]);
    createStaticMapTile(13, 0, Assets::getMapTilesGrass()["MapTileGrassBordersLeftRight"]);

    createStaticMapTile(15, 7, Assets::getMapTilesGrass()["MapTileGrassEndLeft"]);
    createStaticMapTile(16, 7, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(16, 6, Assets::getMapTilesGrass()["MapTileGrassCornerLeftUp"]);
    createStaticMapTile(17, 6, Assets::getMapTilesGrass()["MapTileGrassCornerRightUp"]);
    createStaticMapTile(17, 7, Assets::getMapTilesGrass()["MapTileGrassBorderDown"]);
    createStaticMapTile(18, 7, Assets::getMapTilesGrass()["MapTileGrassEndRight"]);
}

auto Map::initializeBridges() -> void {
    createStaticMapTile(1, 7, Assets::getMapTilesBridge()["MapTileBridgeEndLeft"]);
    createStaticMapTile(2, 7, Assets::getMapTilesBridge()["MapTileBridgeHorizontal"]);
    createStaticMapTile(3, 7, Assets::getMapTilesBridge()["MapTileBridgeHorizontal"]);
    createStaticMapTile(4, 7, Assets::getMapTilesBridge()["MapTileBridgeEndRight"]);
    createStaticMapTile(8, 10, Assets::getMapTilesBridge()["MapTileBridgeEndUp"]);
    createStaticMapTile(8, 11, Assets::getMapTilesBridge()["MapTileBridgeVertical"]);
    createStaticMapTile(8, 12, Assets::getMapTilesBridge()["MapTileBridgeVertical"]);
    createStaticMapTile(8, 13, Assets::getMapTilesBridge()["MapTileBridgeEndDown"]);
    createStaticMapTile(12, 4, Assets::getMapTilesBridge()["MapTileBridgeEndUp"]);
    createStaticMapTile(12, 5, Assets::getMapTilesBridge()["MapTileBridgeVertical"]);
    createStaticMapTile(12, 6, Assets::getMapTilesBridge()["MapTileBridgeVertical"]);
    createStaticMapTile(12, 7, Assets::getMapTilesBridge()["MapTileBridgeEndDown"]);
    createStaticMapTile(18, 13, Assets::getMapTilesBridge()["MapTileBridgeEndLeft"]);
    createStaticMapTile(19, 13, Assets::getMapTilesBridge()["MapTileBridgeHorizontal"]);
    createStaticMapTile(20, 13, Assets::getMapTilesBridge()["MapTileBridgeHorizontal"]);
    createStaticMapTile(21, 13, Assets::getMapTilesBridge()["MapTileBridgeHorizontal"]);
    createStaticMapTile(22, 13, Assets::getMapTilesBridge()["MapTileBridgeEndRight"]);
}

auto Map::createMapBorder(float width, float height, float x, float y) -> void {
    auto border = std::make_unique<MapBorder>(width, height, x, y);
    mapBordersToRender.push_back(border.get());
    mapBorders.push_back(std::move(border));
}

auto Map::createFoam(float x, float y) -> void {
    auto foam = std::make_unique<MapTileAnimated>(Assets::getMapTileFoam());
    foam->setPosition(sf::Vector2f(x * tileSize, y * tileSize));
    foam->setScale(scale);
    mapTilesAnimated.push_back(foam.get());
    mapTiles.push_back(std::move(foam));
}

auto Map::createStaticMapTile(float x, float y, MapTile const& asset) -> void {
    auto mapTile = std::make_unique<MapTile>(asset);
    mapTile->setPosition(sf::Vector2f(x * tileSize, y * tileSize));
    mapTile->setScale(scale);
    mapTiles.push_back(std::move(mapTile));
}

auto Map::updateTextures() -> void {
    for (auto mapTileAnimated : mapTilesAnimated) {
        mapTileAnimated->updateTextures();
    }
}


//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Map::Map()
    : tileSize(32), scale(sf::Vector2f(0.5f, 0.5f)) {
    initializeTiles();
    initializeMapBorders();
}

Map::~Map() = default;


// ----- public methods --------------------------------------------------------------------------------------------

auto Map::updateState() -> void {
    updateTextures();
}

auto Map::render(sf::RenderTarget *window) -> void {
    for (auto& mapTile : mapTiles) {
        mapTile -> render(window);
    }
/*    for (auto& mapBorder : mapBordersToRender) {
        mapBorder->render(window);
    }*/
}


auto Map::getMapTilesMap() -> std::vector<std::unique_ptr<MapTile>>& {
    return mapTiles;
}

auto Map::getMapBorders() -> std::vector<std::unique_ptr<Collidable>> & {
    return mapBorders;
}