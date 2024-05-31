#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Knight.h"


class Game {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::RenderWindow* window;
    sf::Vector2f scale;
    Knight knight;


    // ----- event polling ---------------------------------------------------------------------------------------------
    auto updateEvents() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto updateKnight() -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Game();
    ~Game();

    // ----- public methods ----------------------------------------------------------------------------------------------
    auto isRunning() -> bool;
    auto updateState() -> void;
    auto render() -> void;

};
