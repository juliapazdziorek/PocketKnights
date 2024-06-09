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


auto Assets::initializeMapTileMaps() const -> void {

    //mapTileGrass map
    mapTilesGrass["MapTileGrassCornerLeftUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassBorderUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassCornerRightUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassEndUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassWall"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(4 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassBorderLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassMiddle"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassBorderRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassBordersLeftRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassCornerLeftDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassBorderDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassCornerRightDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassEndDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassEndLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassBordersUpDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrassEndRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesGrass["MapTileGrass"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);

    //mapTileSand map
    mapTilesSand["MapTileSandCornerLeftUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandBorderUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandCornerRightUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandEndUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandWall"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(9 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandBorderLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandMiddle"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandBorderRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandBordersLeftRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandCornerLeftDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandBorderDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandCornerRightDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandEndDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandEndLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandBordersUpDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSandEndRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesSand["MapTileSand"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);

    //mapTileWall map
    mapTilesWall["MapTileWallCornerLeftUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallBorderUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallCornerRightUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallEndUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallBorderLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallBorderRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallBordersLeftRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallCornerLeftDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallBorderDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallCornerRightDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallEndDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallEndLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallBordersUpDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallEndRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWall"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallWallLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallWallMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallWallRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesWall["MapTileWallWall"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);

    //mapTileStairs map
    mapTilesStairs["MapTileStairsLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesStairs["MapTileStairsMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesStairs["MapTileStairsRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesStairs["MapTileStairs"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);

    //mapTileBridge map
    mapTilesBridge["MapTileBridgeEndLeft"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesBridge["MapTileBridgeHorizontal"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (1 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesBridge["MapTileBridgeEndRight"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (2 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesBridge["MapTileBridgeEndUp"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesBridge["MapTileBridgeCrushed1"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (1 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesBridge["MapTileBridgeCrushed2"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (2 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesBridge["MapTileBridgeVertical"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesBridge["MapTileBridgeCrushed3"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (1 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), false);
    mapTilesBridge["MapTileBridgeEndDown"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (0 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);
    mapTilesBridge["MapTileBridgeShadow"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect (2 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture), true);

    //mapTileShadow
    mapTileShadow = MapTile(Assets::textures["mapTileShadowTexture"], sf::IntRect(0, 0, 192, 192), true);

}



//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Assets::Assets() {
    loadTextures();

    this->mapTileSizeInTexture = 64;
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
auto Assets::getMapTilesGrass() -> std::map<std::string, MapTile> { return Assets::mapTilesGrass; }
auto Assets::getMapTilesSand() -> std::map<std::string, MapTile> { return Assets::mapTilesSand; }
auto Assets::getMapTilesWall() -> std::map<std::string, MapTile> { return Assets::mapTilesWall; }
auto Assets::getMapTilesStairs() -> std::map<std::string, MapTile> { return Assets::mapTilesStairs; }
auto Assets::getMapTilesBridge() -> std::map<std::string, MapTile> { return Assets::mapTilesBridge; }
auto Assets::getMapTileShadow() -> MapTile { return Assets::mapTileShadow; }
auto Assets::getMapTileFoam() -> MapTileAnimated { return Assets::mapTileFoam; }


