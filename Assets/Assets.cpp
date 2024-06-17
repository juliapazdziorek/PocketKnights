#include "Assets.h"

//private:

// ----- private methods ------------------------------------------------------------------------------------------------

// load from file

auto Assets::loadTextures() -> void {

    // bannerTexture
    auto bannerTexture = sf::Texture();
    if (!bannerTexture.loadFromFile("../TinySwords/Banner.png")) {
        fmt::println("Could not load from file: TinySwords/Banner.png");
    }
    bannerTexture.setSmooth(true);
    Assets::textures["bannerTexture"] = bannerTexture;

    // knightTexture
    auto knightTexture = sf::Texture();
    if (!knightTexture.loadFromFile("../TinySwords/Knight.png")) {
        fmt::println("Could not load from file: TinySwords/Knight.png");
    }
    knightTexture.setSmooth(true);
    Assets::textures["knightTexture"] = knightTexture;

    // knightTextureFlipped
    auto knightTextureFlipped = sf::Texture();
    if (!knightTextureFlipped.loadFromFile("../TinySwords/KnightFlipped.png")) {
        fmt::println("Could not load from file: TinySwords/KnightFlipped.png");
    }
    knightTextureFlipped.setSmooth(true);
    Assets::textures["knightTextureFlipped"] = knightTextureFlipped;

    // goblinTexture
    auto goblinTexture = sf::Texture();
    if (!goblinTexture.loadFromFile("../TinySwords/Goblin.png")) {
        fmt::println("Could not load from file: TinySwords/Goblin.png");
    }
    goblinTexture.setSmooth(true);
    Assets::textures["goblinTexture"] = goblinTexture;

    // goblinTextureFlipped
    auto goblinTextureFlipped = sf::Texture();
    if (!goblinTextureFlipped.loadFromFile("../TinySwords/GoblinFlipped.png")) {
        fmt::println("Could not load from file: TinySwords/GoblinFlipped.png");
    }
    goblinTextureFlipped.setSmooth(true);
    Assets::textures["goblinTextureFlipped"] = goblinTextureFlipped;

    // mapTileGrassSandTexture
    auto mapTileGrassSandTexture = sf::Texture();
    if (!mapTileGrassSandTexture.loadFromFile("../TinySwords/MapTileGrassSand.png")) {
        fmt::println("Could not load from file: TinySwords/MapTileGrassSand.png");
    }
    mapTileGrassSandTexture.setSmooth(true);
    Assets::textures["mapTileGrassSandTexture"] = mapTileGrassSandTexture;

    // mapTileWallTexture
    auto mapTileWallTexture = sf::Texture();
    if (!mapTileWallTexture.loadFromFile("../TinySwords/MapTileWall.png")) {
        fmt::println("Could not load from file: TinySwords/MapTileWall.png");
    }
    mapTileWallTexture.setSmooth(true);
    Assets::textures["mapTileWallTexture"] = mapTileWallTexture;

    // mapTileBridgeTexture
    auto mapTileBridgeTexture = sf::Texture();
    if (!mapTileBridgeTexture.loadFromFile("../TinySwords/MapTileBridge.png")) {
        fmt::println("Could not load from file: TinySwords/MapTileBridge.png");
    }
    mapTileBridgeTexture.setSmooth(true);
    Assets::textures["mapTileBridgeTexture"] = mapTileBridgeTexture;

    // mapTileShadowTexture
    auto mapTileShadowTexture = sf::Texture();
    if (!mapTileShadowTexture.loadFromFile("../TinySwords/Shadow.png")) {
        fmt::println("Could not load from file: TinySwords/Shadow.png");
    }
    mapTileShadowTexture.setSmooth(true);
    Assets::textures["mapTileShadowTexture"] = mapTileShadowTexture;

    // tileFoamTexture
    auto tileFoamTexture = sf::Texture();
    if (!tileFoamTexture.loadFromFile("../TinySwords/Foam.png")) {
        fmt::println("Could not load from file: TinySwords/Foam.png");
    }
    tileFoamTexture.setSmooth(true);
    Assets::textures["tileFoamTexture"] = tileFoamTexture;

    // sheepTexture
    auto sheepTexture = sf::Texture();
    if (!sheepTexture.loadFromFile("../TinySwords/Sheep.png")) {
        fmt::println("Could not load from file: TinySwords/Sheep.png");
    }
    sheepTexture.setSmooth(true);
    Assets::textures["sheepTexture"] = sheepTexture;

    // meatTexture
    auto meatTexture = sf::Texture();
    if (!meatTexture.loadFromFile("../TinySwords/Meat.png")) {
        fmt::println("Could not load from file: TinySwords/Meat.png");
    }
    meatTexture.setSmooth(true);
    Assets::textures["meatTexture"] = meatTexture;

    // tntBlueTexture
    auto tntBlueTexture = sf::Texture();
    if (!tntBlueTexture.loadFromFile("../TinySwords/TntBlue.png")) {
        fmt::println("Could not load from file: TinySwords/TntBlue.png");
    }
    tntBlueTexture.setSmooth(true);
    Assets::textures["tntBlueTexture"] = tntBlueTexture;

    // tntRedTexture
    auto tntRedTexture = sf::Texture();
    if (!tntRedTexture.loadFromFile("../TinySwords/TntRed.png")) {
        fmt::println("Could not load from file: TinySwords/TntRed.png");
    }
    tntRedTexture.setSmooth(true);
    Assets::textures["tntRedTexture"] = tntRedTexture;

    // explosionTexture
    auto explosionTexture = sf::Texture();
    if (!explosionTexture.loadFromFile("../TinySwords/Explosion.png")) {
        fmt::println("Could not load from file: TinySwords/Explosion.png");
    }
    explosionTexture.setSmooth(true);
    Assets::textures["explosionTexture"] = explosionTexture;

    // mushroom Texture
    auto mushroomTexture = sf::Texture();
    if (!mushroomTexture.loadFromFile("../TinySwords/Mushroom.png")) {
        fmt::println("Could not load from file: TinySwords/Mushroom.png");
    }
    mushroomTexture.setSmooth(true);
    Assets::textures["mushroomTexture"] = mushroomTexture;

}


auto Assets::loadFont() -> void {

    // load font
    if (!font.loadFromFile("../Fonts/alagard.ttf")) {
        fmt::println("Font could not be loaded from file: ../Fonts/alagard.ttf");
    }
}

// initialize variables

auto Assets::initializeMapTileMaps() -> void {

    // mapTileGrass map
    mapTilesGrass["MapTileGrassCornerLeftUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassBorderUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassCornerRightUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassEndUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassWall"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(4 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassBorderLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassMiddle"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassBorderRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassBordersLeftRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassCornerLeftDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassBorderDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassCornerRightDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassEndDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassEndLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(0 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassBordersUpDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(1 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrassEndRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(2 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesGrass["MapTileGrass"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(3 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));

    // mapTileSand map
    mapTilesSand["MapTileSandCornerLeftUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandBorderUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandCornerRightUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandEndUp"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandWall"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(9 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandBorderLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandMiddle"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandBorderRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandBordersLeftRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandCornerLeftDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandBorderDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandCornerRightDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandEndDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandEndLeft"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(5 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandBordersUpDown"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(6 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSandEndRight"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(7 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesSand["MapTileSand"] = MapTile(Assets::textures["mapTileGrassSandTexture"], sf::IntRect(8 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));

    // mapTileWall map
    mapTilesWall["MapTileWallCornerLeftUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallBorderUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallCornerRightUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallEndUp"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallBorderLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallBorderRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallBordersLeftRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallCornerLeftDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallBorderDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallCornerRightDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallEndDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallEndLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallBordersUpDown"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallEndRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWall"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 4 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallWallLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallWallMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallWallRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesWall["MapTileWallWall"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));

    // mapTileStairs map
    mapTilesStairs["MapTileStairsLeft"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(0 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesStairs["MapTileStairsMiddle"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(1 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesStairs["MapTileStairsRight"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(2 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesStairs["MapTileStairs"] = MapTile(Assets::textures["mapTileWallTexture"], sf::IntRect(3 * mapTileSizeInTexture, 7 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));

    // mapTileBridge map
    mapTilesBridge["MapTileBridgeEndLeft"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(0 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeHorizontal"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(1 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeEndRight"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(2 * mapTileSizeInTexture, 0 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeEndUp"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(0 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeCrushed1"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(1 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeCrushed2"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(2 * mapTileSizeInTexture, 1 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeVertical"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(0 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeCrushed3"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(1 * mapTileSizeInTexture, 2 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeEndDown"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(0 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));
    mapTilesBridge["MapTileBridgeShadow"] = MapTile(Assets::textures["mapTileBridgeTexture"], sf::IntRect(2 * mapTileSizeInTexture, 3 * mapTileSizeInTexture, mapTileSizeInTexture, mapTileSizeInTexture));

    // mapTileShadow
    mapTileShadow = MapTile(Assets::textures["mapTileShadowTexture"], sf::IntRect(0, 0, 192, 192));

}


auto Assets::initializeSubtitles() -> void {

    // 1 EASY
    subtitles["easy"] = sf::Text();
    adjustText(subtitles["easy"], "1 EASY", 60, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(320, 120));

    // 2 MEDIUM
    subtitles["medium"] = sf::Text();
    adjustText(subtitles["medium"], "2 MEDIUM", 60, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(280, 260));

    // 3 HARD
    subtitles["hard"] = sf::Text();
    adjustText(subtitles["hard"], "3 HARD", 60, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(320, 400));

    // Wave 1
    subtitles["wave1"] = sf::Text();
    adjustText(subtitles["wave1"],"Wave 1", 100, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(256, 128));

    // Wave 2
    subtitles["wave2"] = sf::Text();
    adjustText(subtitles["wave2"], "Wave 2", 100, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(256, 128));

    // Wave 3
    subtitles["wave3"] = sf::Text();
    adjustText(subtitles["wave3"], "Wave 3", 100, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(256, 128));

    // Attack by hitting SPACE
    subtitles["attackBySpace"] = sf::Text();
    adjustText(subtitles["attackBySpace"], "Attack goblins by hitting SPACE", 50, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(48, 256));

    // Plant TNTs by hitting T
    subtitles["plantTnt"] = sf::Text();
    adjustText(subtitles["plantTnt"], "Plant TNTs by hitting T", 50, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(148, 256));

    // Beware of TNTs!
    subtitles["bewareOfTnt"] = sf::Text();
    adjustText(subtitles["bewareOfTnt"], "Beware of TNTs!", 50, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(248, 256));

    // Game over
    subtitles["gameOver"] = sf::Text();
    adjustText(subtitles["gameOver"], "Game over", 100, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(176, 128));

    // Victory!
    subtitles["victory!"] = sf::Text();
    adjustText(subtitles["victory!"], "Victory!", 100, sf::Color::White, sf::Color::Black, (float)5, sf::Vector2f(224, 128));
}


// adjust text

auto Assets::adjustText(sf::Text& text, std::string string, int size, sf::Color fillColor, sf::Color outlineColor, float outLineThickness ,sf::Vector2f position) -> void {

    // set text variables accordingly
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(fillColor);
    text.setOutlineColor(outlineColor);
    text.setOutlineThickness(outLineThickness);
    text.setPosition(position);
}



//public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Assets::Assets() {

    // load from files
    loadTextures();
    loadFont();

    // initialize map tiles
    mapTileSizeInTexture = 64;
    initializeMapTileMaps();

    // initialize subtitles
    initializeSubtitles();
}


// ----- public methods ------------------------------------------------------------------------------------------------

// menu items getters

auto Assets::getTextureBanner() -> sf::Texture& { return Assets::textures["bannerTexture"]; }


// subtitle getters

auto Assets::getSubtitles() -> std::map<std::string, sf::Text> {return Assets::subtitles; }


// mapTile getters

auto Assets::getMapTilesGrass() -> std::map<std::string, MapTile> { return Assets::mapTilesGrass; }
auto Assets::getMapTilesSand() -> std::map<std::string, MapTile> { return Assets::mapTilesSand; }
auto Assets::getMapTilesWall() -> std::map<std::string, MapTile> { return Assets::mapTilesWall; }
auto Assets::getMapTilesStairs() -> std::map<std::string, MapTile> { return Assets::mapTilesStairs; }
auto Assets::getMapTilesBridge() -> std::map<std::string, MapTile> { return Assets::mapTilesBridge; }
auto Assets::getMapTileShadow() -> MapTile { return Assets::mapTileShadow; }
auto Assets::getMapTileFoam() -> MapTileAnimated { return Assets::mapTileFoam; }


// knight animation getters

auto Assets::getAnimationKnightStanding() -> Animation& { return Assets::knightStanding; }
auto Assets::getAnimationKnightRunningLeft() -> Animation& { return Assets::knightRunningLeft; }
auto Assets::getAnimationKnightRunningRight() -> Animation& { return Assets::knightRunningRight; }
auto Assets::getAnimationKnightAttackRight() -> Animation& { return Assets::knightAttackRight; }
auto Assets::getAnimationKnightAttackLeft() -> Animation& { return Assets::knightAttackLeft; }
auto Assets::getAnimationKnightAttackUp() -> Animation& { return Assets::knightAttackUp; }
auto Assets::getAnimationKnightAttackDown() -> Animation& { return Assets::knightAttackDown; }


// goblin animation getters

auto Assets::getAnimationGoblinStanding() -> Animation& { return Assets::goblinStanding; }
auto Assets::getAnimationGoblinRunningLeft() -> Animation& { return Assets::goblinRunningLeft; }
auto Assets::getAnimationGoblinRunningRight() -> Animation& { return Assets::goblinRunningRight; }
auto Assets::getAnimationGoblinAttackRight() -> Animation& { return Assets::goblinAttackRight; }
auto Assets::getAnimationGoblinAttackLeft() -> Animation& { return Assets::goblinAttackLeft; }
auto Assets::getAnimationGoblinAttackUp() -> Animation& { return Assets::goblinAttackUp; }
auto Assets::getAnimationGoblinAttackDown() -> Animation& { return Assets::goblinAttackDown; }


// sheep animation getters

auto Assets::getAnimationSheepStanding() -> Animation& { return Assets::sheepStanding; }
auto Assets::getAnimationSheepBouncing() -> Animation& { return Assets::sheepBouncing; }


// meat assets getters

auto Assets::getAnimationMeatSpawning() -> Animation& { return Assets::meatSpawning; }
auto Assets::getTextureMeat() -> sf::Texture& { return Assets::textures["meatTexture"]; }


// tnt animation getters

auto Assets::getAnimationTntBlueOut() -> Animation & { return Assets::tntBlueOut; }
auto Assets::getAnimationTntBlueRunning() -> Animation & { return Assets::tntBlueRunning; }
auto Assets::getAnimationTntBlueFire() -> Animation & { return Assets::tntBlueFire; }
auto Assets::getAnimationTntRedOut() -> Animation & { return Assets::tntRedOut; }
auto Assets::getAnimationTntRedRunning() -> Animation & { return Assets::tntRedRunning; }
auto Assets::getAnimationTntRedFire() -> Animation & { return Assets::tntRedFire; }


// explosion animation getters

auto Assets::getAnimationExplosion() -> Animation& { return Assets::explosion; }


// mushroom assets getters

auto Assets::getTextureMushroom() -> sf::Texture& { return Assets::textures["mushroomTexture"]; }

