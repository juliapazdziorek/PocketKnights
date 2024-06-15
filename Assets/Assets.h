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

    // ----- properties ------------------------------------------------------------------------------------------------
    static inline std::map<std::string, sf::Texture> textures;



    //map animations
    static inline Animation foam = Animation(Assets::textures["tileFoamTexture"], 1536, 192, 8, 1, 1, 8);
    static inline Animation smallRock = Animation(Assets::textures["smallRockTexture"], 1024, 128, 8, 1, 1, 8);
    static inline Animation mediumRock = Animation(Assets::textures["mediumRockTexture"], 1024, 128, 8, 1, 1, 8);
    static inline Animation bigRock = Animation(Assets::textures["bigRockTexture"], 1024, 128, 8, 1, 1, 8);
    static inline Animation largeRock = Animation(Assets::textures["largeRockTexture"], 1024, 128, 8, 1, 1, 8);

    //TODO mapy do knight i cos tam animations, ogolnie mapy do tego bo jest syf w ch

    //knight animations
    static inline Animation knightStanding = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 1, 6);
    static inline Animation knightRunningRight = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 2, 6);
    static inline Animation knightRunningLeft = Animation(Assets::textures["knightTextureFlipped"], 1152, 1536, 6, 8, 2, 6);
    static inline Animation knightAttackRight = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 4, 6);
    static inline Animation knightAttackLeft = Animation(Assets::textures["knightTextureFlipped"], 1152, 1536, 6, 8, 4, 6);
    static inline Animation knightAttackUp = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 7, 6);
    static inline Animation knightAttackDown = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 5, 6);

    //goblin animations
    static inline Animation goblinStanding = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 1, 6);
    static inline Animation goblinRunningRight = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 2, 6);
    static inline Animation goblinRunningLeft = Animation(Assets::textures["goblinTextureFlipped"], 1152, 960, 6, 5, 2, 6);
    static inline Animation goblinAttackRight = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 3, 6);
    static inline Animation goblinAttackLeft = Animation(Assets::textures["goblinTextureFlipped"], 1152, 960, 6, 5, 3, 6);
    static inline Animation goblinAttackUp = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 5, 6);
    static inline Animation goblinAttackDown = Animation(Assets::textures["goblinTexture"], 1152, 960, 6, 5, 4, 6);

    //mapTiles
    int mapTileSizeInTexture;
    static inline std::map<std::string, MapTile> mapTilesGrass;
    static inline std::map<std::string, MapTile> mapTilesSand;
    static inline std::map<std::string, MapTile> mapTilesWall;
    static inline std::map<std::string, MapTile> mapTilesStairs;
    static inline std::map<std::string, MapTile> mapTilesBridge;

    static inline MapTile mapTileShadow;
    static inline MapTileAnimated mapTileFoam = MapTileAnimated(Assets::foam, true);

    // font
    static inline sf::Font font;
    static inline std::map<std::string, sf::Text> subtitles;


    // ----- private methods -------------------------------------------------------------------------------------------
    static auto loadTextures() -> void;
    static auto loadFont() -> void;
    auto initializeMapTileMaps() -> void;
    auto initializeSubtitles() -> void;
    auto adjustText(sf::Text& text, std::string string, int size, sf::Color color) -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Assets();
    ~Assets();

    // ----- public methods --------------------------------------------------------------------------------------------

    //knight animation getters //TODO gettery tylko do map z tymi animacjami bo ociepieje
    static auto getAnimationKnightStanding() -> Animation&;
    static auto getAnimationKnightRunningRight() -> Animation&;
    static auto getAnimationKnightRunningLeft() -> Animation&;
    static auto getAnimationKnightAttackLeft() -> Animation&;
    static auto getAnimationKnightAttackRight() -> Animation&;
    static auto getAnimationKnightAttackUp() -> Animation&;
    static auto getAnimationKnightAttackDown() -> Animation&;

    //goblin animation getters
    static auto getAnimationGoblinStanding() -> Animation&;
    static auto getAnimationGoblinRunningRight() -> Animation&;
    static auto getAnimationGoblinRunningLeft() -> Animation&;
    static auto getAnimationGoblinAttackLeft() -> Animation&;
    static auto getAnimationGoblinAttackRight() -> Animation&;
    static auto getAnimationGoblinAttackUp() -> Animation&;
    static auto getAnimationGoblinAttackDown() -> Animation&;

    //mapAnimation getters
    static auto getAnimationFoam() -> Animation&;
    static auto getAnimationSmallRock() -> Animation&;
    static auto getAnimationMediumRock() -> Animation&;
    static auto getAnimationBigRock() -> Animation&;
    static auto getAnimationLargeRock() -> Animation&;

    //mapTile getters
    static auto getMapTilesGrass() -> std::map<std::string, MapTile>;
    static auto getMapTilesSand() -> std::map<std::string, MapTile>;
    static auto getMapTilesWall() -> std::map<std::string, MapTile>;
    static auto getMapTilesStairs() -> std::map<std::string, MapTile>;
    static auto getMapTilesBridge() -> std::map<std::string, MapTile>;
    static auto getMapTileShadow() -> MapTile;
    static auto getMapTileFoam() -> MapTileAnimated;

    static auto getSubtitles() -> std::map<std::string, sf::Text>;

};