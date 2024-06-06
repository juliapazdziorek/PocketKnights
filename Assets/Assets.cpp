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

    //mapTileGrassSandTexture
    auto mapTileGrassSandTexture = sf::Texture();
    if (!mapTileGrassSandTexture.loadFromFile("TinySwords/Terrain/MapTileGrassSand.png")) {
        fmt::println("File can not load from file: TinySwords/MapTileGrassSand.png");
    }
    mapTileGrassSandTexture.setSmooth(true);
    Assets::textures["mapTileGrassSandTexture"] = mapTileGrassSandTexture;

    //mapTileWallTexture
    auto mapTileWallTexture = sf::Texture();
    if (!mapTileWallTexture.loadFromFile("TinySwords/Terrain/MapTileWall.png")) {
        fmt::println("File can not load from file: TinySwords/MapTileWall.png");
    }
    mapTileWallTexture.setSmooth(true);
    Assets::textures["mapTileWallTexture"] = mapTileWallTexture;

    //mapTileBridgeTexture
    auto mapTileBridgeTexture = sf::Texture();
    if (!mapTileBridgeTexture.loadFromFile("TinySwords/Terrain/MapTileBridge.png")) {
        fmt::println("File can not load from file: TinySwords/MapTileBridge.png");
    }
    mapTileBridgeTexture.setSmooth(true);
    Assets::textures["mapTileBridgeTexture"] = mapTileBridgeTexture;

    //mapTileShadowTexture
    auto mapTileShadowTexture = sf::Texture();
    if (!mapTileShadowTexture.loadFromFile("TinySwords/Terrain/Shadow.png")) {
        fmt::println("File can not load from file: TinySwords/Shadow.png");
    }
    mapTileShadowTexture.setSmooth(true);
    Assets::textures["mapTileShadowTexture"] = mapTileShadowTexture;

    //tileFoamTexture
    auto tileFoamTexture = sf::Texture();
    if (!tileFoamTexture.loadFromFile("TinySwords/Terrain/Foam.png")) {
        fmt::println("File can not load from file: TinySwords/Foam.png");
    }
    tileFoamTexture.setSmooth(true);
    Assets::textures["tileFoamTexture"] = tileFoamTexture;

    //smallRockTexture
    auto smallRockTexture = sf::Texture();
    if (!smallRockTexture.loadFromFile("TinySwords/Terrain/SmallRock.png")) {
        fmt::println("File can not load from file: TinySwords/SmallRock.png");
    }
    smallRockTexture.setSmooth(true);
    Assets::textures["smallRockTexture"] = smallRockTexture;

    //mediumRockTexture
    auto mediumRockTexture = sf::Texture();
    if (!mediumRockTexture.loadFromFile("TinySwords/Terrain/MediumRock.png")) {
        fmt::println("File can not load from file: TinySwords/MediumRock.png");
    }
    mediumRockTexture.setSmooth(true);
    Assets::textures["mediumRockTexture"] = mediumRockTexture;

    //bigRockTexture
    auto bigRockTexture = sf::Texture();
    if (!bigRockTexture.loadFromFile("TinySwords/Terrain/BigRock.png")) {
        fmt::println("File can not load from file: TinySwords/BigRock.png");
    }
    bigRockTexture.setSmooth(true);
    Assets::textures["bigRockTexture"] = bigRockTexture;

    //largeRockTexture
    auto largeRockTexture = sf::Texture();
    if (!largeRockTexture.loadFromFile("TinySwords/Terrain/LargeRock.png")) {
        fmt::println("File can not load from file: TinySwords/LargeRock.png");
    }
    largeRockTexture.setSmooth(true);
    Assets::textures["largeRockTexture"] = largeRockTexture;

}


auto Assets::initializeMapTileMaps() -> void {

    //mapTileGrass map
    MapTilesGrass["MapTileGrassCornerLeftUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(0 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize),true);
    MapTilesGrass["MapTileGrassBorderUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassCornerRightUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassWall"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(4 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBorderLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassMiddle"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBorderRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBordersLeftRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassCornerLeftDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBorderDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassCornerRightDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassBordersUpDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrassEndRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesGrass["MapTileGrass"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileSand map
    MapTilesSand["MapTileSandCornerLeftUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(5 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(6 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandCornerRightUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(7 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(8 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandWall"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(9 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(5 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandMiddle"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(6 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(7 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBordersLeftRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(8 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandCornerLeftDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(5 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBorderDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(6 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandCornerRightDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(7 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(8 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(5 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandBordersUpDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(6 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSandEndRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(7 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesSand["MapTileSand"] = MapTile(Assets::textures["mapTileGrassSandTexture"],sf::IntRect(8 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileWall map
    MapTilesWall["MapTileWallCornerLeftUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallCornerRightUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSize, 0 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBordersLeftRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSize, 1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallCornerLeftDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBorderDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallCornerRightDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSize, 2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallBordersUpDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallEndRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWall"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSize, 4 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWallLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWallMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWallRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesWall["MapTileWallWall"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSize, 3 * mapTileSize, mapTileSize, mapTileSize), false);

    //mapTileStairs map
    MapTilesStairs["MapTileStairsLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesStairs["MapTileStairsMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesStairs["MapTileStairsRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesStairs["MapTileStairs"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSize, 7 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileBridge map
    MapTilesBridge["MapTileBridgeEndLeft"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileBridgeHorizontal"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (1 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileBridgeEndRight"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (2 * mapTileSize,0 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileBridgeEndUp"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileBridgeCrushed1"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (1 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesBridge["MapTileBridgeCrushed2"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (2 * mapTileSize,1 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesBridge["MapTileBridgeVertical"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSize,2 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileBridgeCrushed3"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (1 * mapTileSize,2 * mapTileSize, mapTileSize, mapTileSize), false);
    MapTilesBridge["MapTileBridgeEndDown"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSize,3 * mapTileSize, mapTileSize, mapTileSize), true);
    MapTilesBridge["MapTileBridgeShadow"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (2 * mapTileSize,3 * mapTileSize, mapTileSize, mapTileSize), true);

    //mapTileShadow
    MapTileShadow = MapTile(Assets::textures["mapTileShadowTexture"], sf::IntRect(0, 0, 192, 192), true);

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
auto Assets::getAnimationKnightStanding() -> Animation& { return Assets::knightStanding; }
auto Assets::getAnimationKnightRunningLeft() -> Animation& { return Assets::knightRunningLeft; }
auto Assets::getAnimationKnightRunningRight() -> Animation& { return Assets::knightRunningRight; }
auto Assets::getAnimationKnightAttackRight() -> Animation& { return Assets::knightAttackRight; }
auto Assets::getAnimationKnightAttackLeft() -> Animation& { return Assets::knightAttackLeft; }
auto Assets::getAnimationKnightAttackUp() -> Animation& { return Assets::knightAttackUp; }
auto Assets::getAnimationKnightAttackDown() -> Animation& { return Assets::knightAttackDown; }

//goblin animation getters
auto Assets::getAnimationGoblinStanding() -> Animation& { return Assets::goblinStanding; }
auto Assets::getAnimationGoblinRunningLeft() -> Animation& { return Assets::goblinRunningLeft; }
auto Assets::getAnimationGoblinRunningRight() -> Animation& { return Assets::goblinRunningRight; }
auto Assets::getAnimationGoblinAttackRight() -> Animation& { return Assets::goblinAttackRight; }
auto Assets::getAnimationGoblinAttackLeft() -> Animation& { return Assets::goblinAttackLeft; }
auto Assets::getAnimationGoblinAttackUp() -> Animation& { return Assets::goblinAttackUp; }
auto Assets::getAnimationGoblinAttackDown() -> Animation& { return Assets::goblinAttackDown; }

//mapAnimation getters
auto Assets::getAnimationFoam() -> Animation& { return Assets::foam; }
auto Assets::getAnimationSmallRock() -> Animation& { return Assets::smallRock; }
auto Assets::getAnimationMediumRock() -> Animation& { return Assets::mediumRock; }
auto Assets::getAnimationBigRock() -> Animation& { return Assets::bigRock; }
auto Assets::getAnimationLargeRock() -> Animation& { return Assets::largeRock; }


//mapTile animation getters
auto Assets::getMapTilesGrass() -> std::map<std::string, MapTile> { return Assets::MapTilesGrass; }
auto Assets::getMapTilesSand() -> std::map<std::string, MapTile> { return Assets::MapTilesSand; }
auto Assets::getMapTilesWall() -> std::map<std::string, MapTile> { return Assets::MapTilesWall; }
auto Assets::getMapTilesStairs() -> std::map<std::string, MapTile> { return Assets::MapTilesStairs; }
auto Assets::getMapTilesBridge() -> std::map<std::string, MapTile> { return Assets::MapTilesBridge; }
auto Assets::getMapTileShadow() -> MapTile { return Assets::MapTileShadow; }
auto Assets::getMapTileFoam() -> MapTileAnimated { return Assets::MapTileFoam; }




