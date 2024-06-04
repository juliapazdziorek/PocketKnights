#include "Assets.h"

//private:

// ----- private methods ------------------------------------------------------------------------------------------------
auto Assets::loadTextures() -> void {

    //knightTexture
    auto knightTexture = sf::Texture();
    if (!knightTexture.loadFromFile("TinySwords/Knight.png")) {
        fmt::println("File can not load from file: TinySwords/Knight.png");
    }
    knightTexture.setSmooth(true);
    Assets::textures["knightTexture"] = knightTexture;

    //knightTextureFlipped
    auto knightTextureFlipped = sf::Texture();
    if (!knightTextureFlipped.loadFromFile("TinySwords/KnightFlipped.png")) {
        fmt::println("File can not load from file: TinySwords/KnightFlipped.png");
    }
    knightTextureFlipped.setSmooth(true);
    Assets::textures["knightTextureFlipped"] = knightTextureFlipped;

    //goblinTexture
    auto goblinTexture = sf::Texture();
    if (!goblinTexture.loadFromFile("TinySwords/Goblin.png")) {
        fmt::println("File can not load from file: TinySwords/Goblin.png");
    }
    goblinTexture.setSmooth(true);
    Assets::textures["goblinTexture"] = goblinTexture;

    //goblinTextureFlipped
    auto goblinTextureFlipped = sf::Texture();
    if (!goblinTextureFlipped.loadFromFile("TinySwords/GoblinFlipped.png")) {
        fmt::println("File can not load from file: TinySwords/GoblinFlipped.png");
    }
    goblinTextureFlipped.setSmooth(true);
    Assets::textures["goblinTextureFlipped"] = goblinTextureFlipped;

    //tileMapGrassSandTexture
    auto tileMapGrassSandTexture = sf::Texture();
    if (!tileMapGrassSandTexture.loadFromFile("TinySwords/TileMapGrassSand.png")) {
        fmt::println("File can not load from file: TinySwords/TileMapGrassSand.png");
    }
    tileMapGrassSandTexture.setSmooth(true);
    Assets::textures["tileMapGrassSandTexture"] = tileMapGrassSandTexture;

    //tileMapWallTexture
    auto tileMapWallTexture = sf::Texture();
    if (!tileMapWallTexture.loadFromFile("TinySwords/TileMapWall.png")) {
        fmt::println("File can not load from file: TinySwords/TileMapWall.png");
    }
    tileMapWallTexture.setSmooth(true);
    Assets::textures["tileMapWallTexture"] = tileMapWallTexture;

    //tileMapBridgeTexture
    auto tileMapBridgeTexture = sf::Texture();
    if (!tileMapBridgeTexture.loadFromFile("TinySwords/TileMapBridge.png")) {
        fmt::println("File can not load from file: TinySwords/TileMapBridge.png");
    }
    tileMapBridgeTexture.setSmooth(true);
    Assets::textures["tileMapBridgeTexture"] = tileMapBridgeTexture;


}

auto Assets::initializeMapTileMaps() -> void {

    //mapTile grass intRects map
    this->intRectsGrass["MapTileGrassCornerLeftUp"] = sf::IntRect(0 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassBorderUp"] = sf::IntRect(1 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassCornerRightUp"] = sf::IntRect(2 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassEndUp"] = sf::IntRect(3 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassWall"] = sf::IntRect(4 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassBorderLeft"] = sf::IntRect(0 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassMiddle"] = sf::IntRect(1 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassBorderRight"] = sf::IntRect(2 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassBordersLeftRight"] = sf::IntRect(3 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassCornerLeftDown"] = sf::IntRect(0 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassBorderDown"] = sf::IntRect(1 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassCornerRightDown"] = sf::IntRect(2 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassEndDown"] = sf::IntRect(3 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassEndLeft"] = sf::IntRect(0 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassBordersUpDown"] = sf::IntRect(1 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrassEndRight"] = sf::IntRect(2 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsGrass["MapTileGrass"] = sf::IntRect(3 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);

    //mapTile sand intRects map
    this->intRectsSand["MapTileSandCornerLeftUp"] = sf::IntRect(5 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandBorderUp"] = sf::IntRect(6 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandCornerRightUp"] = sf::IntRect(7 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandEndUp"] = sf::IntRect(8 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandWall"] = sf::IntRect(9 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandBorderLeft"] = sf::IntRect(5 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandMiddle"] = sf::IntRect(6 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandBorderRight"] = sf::IntRect(7 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandBordersLeftRight"] = sf::IntRect(8 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandCornerLeftDown"] = sf::IntRect(5 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandBorderDown"] = sf::IntRect(6 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandCornerRightDown"] = sf::IntRect(7 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandEndDown"] = sf::IntRect(8 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandEndLeft"] = sf::IntRect(5 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandBordersUpDown"] = sf::IntRect(6 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSandEndRight"] = sf::IntRect(7 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsSand["MapTileSand"] = sf::IntRect(8 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);

    //mapTile wall intRects map
    this->intRectsWall["MapTileWallCornerLeftUp"] = sf::IntRect(0 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallBorderUp"] = sf::IntRect(1 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallCornerRightUp"] = sf::IntRect(2 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallEndUp"] = sf::IntRect(3 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallBorderLeft"] = sf::IntRect(0 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallMiddle"] = sf::IntRect(1 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallBorderRight"] = sf::IntRect(2 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallBordersLeftRight"] = sf::IntRect(3 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallCornerLeftDown"] = sf::IntRect(0 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallBorderDown"] = sf::IntRect(1 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallCornerRightDown"] = sf::IntRect(2 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallEndDown"] = sf::IntRect(3 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallEndLeft"] = sf::IntRect(5 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallBordersUpDown"] = sf::IntRect(6 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallEndRight"] = sf::IntRect(7 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWall"] = sf::IntRect(8 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallWallLeft"] = sf::IntRect(0 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallWallMiddle"] = sf::IntRect(1 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallWallRight"] = sf::IntRect(2 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileWallWallMiddle"] = sf::IntRect(3 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize);

    //mapTile stairs intRects map
    this->intRectsWall["MapTileStairsLeft"] = sf::IntRect(0 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileStairsMiddle"] = sf::IntRect(1 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileStairsRight"] = sf::IntRect(2 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsWall["MapTileStairsMiddle"] = sf::IntRect(3 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize);

    //mapTile stairs intRects map
    this->intRectsBridge["MapTileEndLeft"] = sf::IntRect (0 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileHorizontal"] = sf::IntRect (1 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileEndRight"] = sf::IntRect (2 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileEndUp"] = sf::IntRect (0 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileCrushed1"] = sf::IntRect (1 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileCrushed2"] = sf::IntRect (2 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileVertical"] = sf::IntRect (0 * mapTileSize,2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileCrushed3"] = sf::IntRect (1 * mapTileSize,2 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileEndDown"] = sf::IntRect (0 * mapTileSize,3 * mapTileSize, mapTileSize, mapTileSize);
    this->intRectsBridge["MapTileShadow"] = sf::IntRect (2 * mapTileSize,3 * mapTileSize, mapTileSize, mapTileSize);

}



//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Assets::Assets() {
    loadTextures();

    this->mapTileSize = 64;
    initializeMapTileMaps();
}

Assets::~Assets() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

//knight animation getters
auto Assets::getKnightStanding() -> Animation& { return Assets::knightStanding; }
auto Assets::getKnightRunningLeft() -> Animation & { return Assets::knightRunningLeft; }
auto Assets::getKnightRunningRight() -> Animation & { return Assets::knightRunningRight; }
auto Assets::getKnightAttackRight() -> Animation & { return Assets::knightAttackRight; }
auto Assets::getKnightAttackLeft() -> Animation & { return Assets::knightAttackLeft; }
auto Assets::getKnightAttackUp() -> Animation & { return Assets::knightAttackUp; }
auto Assets::getKnightAttackDown() -> Animation & { return Assets::knightAttackDown; }


//goblin animation getters
auto Assets::getGoblinStanding() -> Animation& { return Assets::goblinStanding; }
auto Assets::getGoblinRunningLeft() -> Animation & { return Assets::goblinRunningLeft; }
auto Assets::getGoblinRunningRight() -> Animation & { return Assets::goblinRunningRight; }
auto Assets::getGoblinAttackRight() -> Animation & { return Assets::goblinAttackRight; }
auto Assets::getGoblinAttackLeft() -> Animation & { return Assets::goblinAttackLeft; }
auto Assets::getGoblinAttackUp() -> Animation & { return Assets::goblinAttackUp; }
auto Assets::getGoblinAttackDown() -> Animation & { return Assets::goblinAttackDown; }

