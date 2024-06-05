#pragma once

#include <SFML/Graphics.hpp>
#include <fmt/ranges.h>
#include <map>
#include <string>

#include "Animation.h"
#include "MapTile.h"
#include "MapTileAnimated.h"

class Assets {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    static inline std::map<std::string, sf::Texture> textures;

    //map animations
    static inline Animation foam = Animation(Assets::textures["tileFoamTexture"], 1536, 192, 8, 1, 1, 8);

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
    int mapTileSize;
    static inline std::map<std::string, MapTile> MapTilesGrass;
    static inline std::map<std::string, MapTile> MapTilesSand;
    static inline std::map<std::string, MapTile> MapTilesWall;
    static inline std::map<std::string, MapTile> MapTilesStairs;
    static inline std::map<std::string, MapTile> MapTilesBridge;

    static inline MapTile MapTileShadow;
    static inline MapTileAnimated MapTileFoam = MapTileAnimated(foam, true);




    // ----- private methods -------------------------------------------------------------------------------------------
    static auto loadTextures() -> void;
    auto initializeMapTileMaps() -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Assets();
    ~Assets();

    // ----- public methods --------------------------------------------------------------------------------------------

    //knight animation getters
    static auto getKnightStanding() -> Animation&;
    static auto getKnightRunningRight() -> Animation&;
    static auto getKnightRunningLeft() -> Animation&;
    static auto getKnightAttackLeft() -> Animation&;
    static auto getKnightAttackRight() -> Animation&;
    static auto getKnightAttackUp() -> Animation&;
    static auto getKnightAttackDown() -> Animation&;

    //goblin animation getters
    static auto getGoblinStanding() -> Animation&;
    static auto getGoblinRunningRight() -> Animation&;
    static auto getGoblinRunningLeft() -> Animation&;
    static auto getGoblinAttackLeft() -> Animation&;
    static auto getGoblinAttackRight() -> Animation&;
    static auto getGoblinAttackUp() -> Animation&;
    static auto getGoblinAttackDown() -> Animation&;

    //mapAnimation getters
    static auto getFoamAnimation() -> Animation&;

    //mapTile getters
    static auto getMapTilesGrass() -> std::map<std::string, MapTile>;
    static auto getMapTilesSand() -> std::map<std::string, MapTile>;
    static auto getMapTilesWall() -> std::map<std::string, MapTile>;
    static auto getMapTilesStairs() -> std::map<std::string, MapTile>;
    static auto getMapTilesBridge() -> std::map<std::string, MapTile>;
    static auto getMapTileShadow() -> MapTile;
    static auto getMapTileFoam() -> MapTileAnimated;

};