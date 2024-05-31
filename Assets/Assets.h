#pragma once

#include <SFML/Graphics.hpp>
#include <fmt/ranges.h>

class Assets {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    static inline sf::Texture knightOriginal;

    // ----- public methods --------------------------------------------------------------------------------------------
    static auto createKnightOriginal() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Assets();
    ~Assets();

    // ----- public methods --------------------------------------------------------------------------------------------
    static auto getKnightOriginal() -> sf::Texture&;


    //jako pola beda konkretne asety (tekstrury statycznych spritów lub animacje)
    //konstruktor je wszytkie inicjalizuje ubduje i wylicza)
    //getterami konkretne klasy uzyskuja do nich dostep

};
