#pragma once

#include <SFML/Graphics.hpp>
#include <fmt/ranges.h>
#include <map>
#include <string>

#include "Animation.h"

class Assets {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    static inline std::map<std::string, sf::Texture> textures;

    static inline Animation knightStanding = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 1);
    static inline Animation knightRunningRight = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 2);
    static inline Animation knightRunningLeft = Animation(Assets::textures["knightTextureFlipped"], 1152, 1536, 6, 8, 2);
    static inline Animation knightAttackRight = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 4);
    static inline Animation knightAttackLeft = Animation(Assets::textures["knightTextureFlipped"], 1152, 1536, 6, 8, 3);
    static inline Animation knightAttackUp = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 7);
    static inline Animation knightAttackDown = Animation(Assets::textures["knightTexture"], 1152, 1536, 6, 8, 5);

    // ----- private methods -------------------------------------------------------------------------------------------
    static auto loadTextures() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Assets();
    ~Assets();

    // ----- public methods --------------------------------------------------------------------------------------------
    static auto getKnightStanding() -> Animation&;
    static auto getKnightRunningRight() -> Animation&;
    static auto getKnightRunningLeft() -> Animation&;
    static auto getKnightAttackLeft() -> Animation&;
    static auto getKnightAttackRight() -> Animation&;
    static auto getKnightAttackUp() -> Animation&;
    static auto getKnightAttackDown() -> Animation&;


};