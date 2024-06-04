#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Map {

private:

    // ----- properties ------------------------------------------------------------------------------------------------


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Map();
    ~Map();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto render(sf::RenderTarget* window) -> void;

};

