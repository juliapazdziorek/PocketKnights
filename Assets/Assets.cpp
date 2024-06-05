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

    //tileMapGrassSandTexture //TODO cosmetics: change tileMap -> mapTile
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

    //tileMapShadowTexture
    auto tileMapShadowTexture = sf::Texture();
    if (!tileMapShadowTexture.loadFromFile("TinySwords/Shadow.png")) {
        fmt::println("File can not load from file: TinySwords/Shadow.png");
    }
    tileMapShadowTexture.setSmooth(true);
    Assets::textures["tileMapShadowTexture"] = tileMapShadowTexture;

    //tileMapFoamTexture
    auto tileFoamTexture = sf::Texture();
    if (!tileFoamTexture.loadFromFile("TinySwords/Foam.png")) {
        fmt::println("File can not load from file: TinySwords/Foam.png");
    }
    tileFoamTexture.setSmooth(true);
    Assets::textures["tileFoamTexture"] = tileFoamTexture;

}


auto Assets::initializeMapTileMaps() -> void {

    //mapTileGrass map
    MapTilesGrass["MapTileGrassCornerLeftUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(0 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize),true);
    MapTilesGrass["MapTileGrassBorderUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(1 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassCornerRightUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(2 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(3 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassWall"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(4 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBorderLeft"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(0 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassMiddle"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(1 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBorderRight"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(2 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBordersLeftRight"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(3 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassCornerLeftDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(0 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBorderDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(1 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassCornerRightDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(2 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(3 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndLeft"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(0 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBordersUpDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(1 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndRight"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(2 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrass"] = MapTile(Assets::textures["tileMapGrassSandTexture"], sf::IntRect(3 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileSand map
    MapTilesSand["MapTileSandCornerLeftUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(5 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(6 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandCornerRightUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(7 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndUp"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(8 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandWall"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(9 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderLeft"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(5 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandMiddle"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(6 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderRight"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(7 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBordersLeftRight"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(8 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandCornerLeftDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(5 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(6 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandCornerRightDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(7 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(8 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndLeft"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(5 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBordersUpDown"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(6 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndRight"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(7 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSand"] = MapTile(Assets::textures["tileMapGrassSandTexture"],sf::IntRect(8 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileWall map
    MapTilesWall["MapTileWallCornerLeftUp"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(0 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderUp"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(1 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallCornerRightUp"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(2 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndUp"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(3 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderLeft"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(0 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallMiddle"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(1 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderRight"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(2 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBordersLeftRight"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(3 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallCornerLeftDown"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(0 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderDown"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(1 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallCornerRightDown"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(2 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndDown"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(3 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndLeft"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(5 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBordersUpDown"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(6 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndRight"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(7 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWall"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(8 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWallLeft"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(0 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWallMiddle"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(1 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWallRight"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(2 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWallMiddle"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(3 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);

    //mapTileStairs map
    MapTilesStairs["MapTileStairsLeft"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(0 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesStairs["MapTileStairsMiddle"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(1 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesStairs["MapTileStairsRight"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(2 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesStairs["MapTileStairsMiddle"] = MapTile(Assets::textures["tileMapWallTexture"], sf::IntRect(3 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileBridge map
    MapTilesBridge["MapTileEndLeft"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (0 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileHorizontal"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (1 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileEndRight"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (2 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileEndUp"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (0 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileCrushed1"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (1 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesBridge["MapTileCrushed2"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (2 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesBridge["MapTileVertical"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (0 * mapTileSize,2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileCrushed3"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (1 * mapTileSize,2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesBridge["MapTileEndDown"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (0 * mapTileSize,3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileShadow"] = MapTile(Assets::textures["tileMapBridgeTexture"], sf::IntRect (2 * mapTileSize,3 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileShadow
    MapTileShadow = MapTile(Assets::textures["tileMapShadowTexture"], sf::IntRect(0, 0, 82, 82), true);

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
auto Assets::getKnightRunningLeft() -> Animation& { return Assets::knightRunningLeft; }
auto Assets::getKnightRunningRight() -> Animation& { return Assets::knightRunningRight; }
auto Assets::getKnightAttackRight() -> Animation& { return Assets::knightAttackRight; }
auto Assets::getKnightAttackLeft() -> Animation& { return Assets::knightAttackLeft; }
auto Assets::getKnightAttackUp() -> Animation& { return Assets::knightAttackUp; }
auto Assets::getKnightAttackDown() -> Animation& { return Assets::knightAttackDown; }

//goblin animation getters
auto Assets::getGoblinStanding() -> Animation& { return Assets::goblinStanding; }
auto Assets::getGoblinRunningLeft() -> Animation& { return Assets::goblinRunningLeft; }
auto Assets::getGoblinRunningRight() -> Animation& { return Assets::goblinRunningRight; }
auto Assets::getGoblinAttackRight() -> Animation& { return Assets::goblinAttackRight; }
auto Assets::getGoblinAttackLeft() -> Animation& { return Assets::goblinAttackLeft; }
auto Assets::getGoblinAttackUp() -> Animation& { return Assets::goblinAttackUp; }
auto Assets::getGoblinAttackDown() -> Animation& { return Assets::goblinAttackDown; }

//mapTile animation getters
auto Assets::getMapTilesGrass() -> std::map<std::string, MapTile> { return Assets::MapTilesGrass; }
auto Assets::getMapTilesSand() -> std::map<std::string, MapTile> { return Assets::MapTilesSand; }
auto Assets::getMapTilesWall() -> std::map<std::string, MapTile> { return Assets::MapTilesWall; }
auto Assets::getMapTilesStairs() -> std::map<std::string, MapTile> { return Assets::MapTilesStairs; }
auto Assets::getMapTilesBridge() -> std::map<std::string, MapTile> { return Assets::MapTilesBridge; }
auto Assets::getMapTileShadow() -> MapTile { return Assets::MapTileShadow; }
auto Assets::getMapTileFoam() -> MapTileAnimated { return Assets::MapTileFoam; }

auto Assets::getFoamAnimation() -> Animation& { return Assets::foam; }


