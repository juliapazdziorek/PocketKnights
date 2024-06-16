#pragma once

#include <SFML/Graphics.hpp>
#include <fmt/ranges.h>
#include <map>
#include <string>
#include <vector>

#include "Animation.h"
#include "MapTile.h"
#include "MapTileAnimated.h"

class Assets {

private:

    // ----- variables -------------------------------------------------------------------------------------------------

    // textures
    static inline std::map<std::string, sf::Texture> textures;

    // font
    static inline sf::Font font;
    static inline std::map<std::string, sf::Text> subtitles;

    // map animations
    static inline Animation foam = Animation(Assets::textures["tileFoamTexture"], 1536, 192, 8, 1, 1, 8);

    // mapTiles
    int mapTileSizeInTexture;
    static inline std::map<std::string, MapTile> mapTilesGrass;
    static inline std::map<std::string, MapTile> mapTilesSand;
    static inline std::map<std::string, MapTile> mapTilesWall;
    static inline std::map<std::string, MapTile> mapTilesStairs;
    static inline std::map<std::string, MapTile> mapTilesBridge;
    static inline MapTile mapTileShadow;
    static inline MapTileAnimated mapTileFoam = MapTileAnimated(Assets::foam);

    // knight animations
    static inline Animation knightStanding = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 1, 6);
    static inline Animation knightRunningRight = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 2, 6);
    static inline Animation knightRunningLeft = Animation(Assets::textures["knightTextureFlipped"], 1152, 1536, 6, 8, 2, 6);
    static inline Animation knightAttackRight = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 4, 6);
    static inline Animation knightAttackLeft = Animation(Assets::textures["knightTextureFlipped"], 1152, 1536, 6, 8, 4, 6);
    static inline Animation knightAttackUp = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 7, 6);
    static inline Animation knightAttackDown = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 5, 6);

    // goblin animations
    static inline Animation goblinStanding = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 1, 6);
    static inline Animation goblinRunningRight = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 2, 6);
    static inline Animation goblinRunningLeft = Animation(Assets::textures["goblinTextureFlipped"], 1152, 960, 6, 5, 2, 6);
    static inline Animation goblinAttackRight = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 3, 6);
    static inline Animation goblinAttackLeft = Animation(Assets::textures["goblinTextureFlipped"], 1152, 960, 6, 5, 3, 6);
    static inline Animation goblinAttackUp = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 5, 6);
    static inline Animation goblinAttackDown = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 4, 6);

    // sheep animations
    static inline Animation sheepStanding = Animation(Assets::textures["sheepTexture"], 1024, 256, 8, 2, 1, 8);
    static inline Animation sheepBouncing = Animation(Assets::textures["sheepTexture"], 1024, 256, 8, 2, 2, 6);

    // meat animations
    static inline Animation meatSpawning = Animation(Assets::textures["meatTexture"], 896, 128, 7, 1, 1, 7);

    // tnt animations
    static inline Animation tntBlueOut = Animation(Assets::textures["tntBlueTexture"], 768, 768, 6, 6, 2, 6);
    static inline Animation tntBlueRunning = Animation(Assets::textures["tntBlueTexture"], 768, 768, 6, 6, 5, 3);
    static inline Animation tntBlueFire = Animation(Assets::textures["tntBlueTexture"], 768, 768, 6, 6, 6, 3);
    static inline Animation tntRedOut = Animation(Assets::textures["tntRedTexture"], 768, 768, 6, 6, 2, 6);
    static inline Animation tntRedRunning = Animation(Assets::textures["tntRedTexture"], 768, 768, 6, 6, 5, 3);
    static inline Animation tntRedFire = Animation(Assets::textures["tntRedTexture"], 768, 768, 6, 6, 6, 3);

    // ----- private methods -------------------------------------------------------------------------------------------

    // load from files
    static auto loadTextures() -> void;
    static auto loadFont() -> void;

    // initialize variables
    auto initializeMapTileMaps() -> void;
    auto initializeSubtitles() -> void;

    // adjust text
    static auto adjustText(sf::Text& text, std::string string, int size, sf::Color fillColor, sf::Color outlineColor, float outLineThickness, sf::Vector2f position) -> void;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    Assets();

    // ----- public methods --------------------------------------------------------------------------------------------

    // menu items getters
    static auto getTextureBanner() -> sf::Texture&;

    // subtitle getters
    static auto getSubtitles() -> std::map<std::string, sf::Text>;


    // mapTile getters
    static auto getMapTilesGrass() -> std::map<std::string, MapTile>;
    static auto getMapTilesSand() -> std::map<std::string, MapTile>;
    static auto getMapTilesWall() -> std::map<std::string, MapTile>;
    static auto getMapTilesStairs() -> std::map<std::string, MapTile>;
    static auto getMapTilesBridge() -> std::map<std::string, MapTile>;
    static auto getMapTileShadow() -> MapTile;
    static auto getMapTileFoam() -> MapTileAnimated;

    // knight animation getters
    static auto getAnimationKnightStanding() -> Animation&;
    static auto getAnimationKnightRunningRight() -> Animation&;
    static auto getAnimationKnightRunningLeft() -> Animation&;
    static auto getAnimationKnightAttackLeft() -> Animation&;
    static auto getAnimationKnightAttackRight() -> Animation&;
    static auto getAnimationKnightAttackUp() -> Animation&;
    static auto getAnimationKnightAttackDown() -> Animation&;

    // goblin animation getters
    static auto getAnimationGoblinStanding() -> Animation&;
    static auto getAnimationGoblinRunningRight() -> Animation&;
    static auto getAnimationGoblinRunningLeft() -> Animation&;
    static auto getAnimationGoblinAttackLeft() -> Animation&;
    static auto getAnimationGoblinAttackRight() -> Animation&;
    static auto getAnimationGoblinAttackUp() -> Animation&;
    static auto getAnimationGoblinAttackDown() -> Animation&;

    // sheep animation getters
    static auto getAnimationSheepStanding() -> Animation&;
    static auto getAnimationSheepBouncing() -> Animation&;

    // meat assets getters
    static auto getAnimationMeatSpawning() -> Animation&;
    static auto getTextureMeat() -> sf::Texture&;

    // tnt animation getters
    static auto getAnimationTntBlueOut() -> Animation&;
    static auto getAnimationTntBlueRunning() -> Animation&;
    static auto getAnimationTntBlueFire() -> Animation&;
    static auto getAnimationTntRedOut() -> Animation&;
    static auto getAnimationTntRedRunning() -> Animation&;
    static auto getAnimationTntRedFire() -> Animation&;

};