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

    // ----- private methods -------------------------------------------------------------------------------------------
    static auto loadTextures() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Assets();
    ~Assets();

    // ----- public methods --------------------------------------------------------------------------------------------
    static auto getKnightStanding() -> Animation&;

    //jako pola beda konkretne asety (tekstrury statycznych spritów lub animacje)
    //konstruktor je wszytkie inicjalizuje ubduje i wylicza)
    //getterami konkretne klasy uzyskuja do nich dostep

};
