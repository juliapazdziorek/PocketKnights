#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Assets/Assets.h"
#include "Assets/Animation.h"

class Knight {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    static inline sf::Texture texture;
    sf::Sprite knight;
    float movingSpeed;


    // ----- event updating ---------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateTexture() -> void;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Knight();
    ~Knight();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto updateState() -> void;
    auto render(sf::RenderTarget* window) -> void;

};