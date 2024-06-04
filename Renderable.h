#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Renderable {

public:

    // ----- public methods --------------------------------------------------------------------------------------------
    virtual auto render(sf::RenderTarget* window) -> void = 0;

};
