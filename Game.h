#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Assets/Assets.h"
#include "Map.h"
#include "Knight.h"
#include "Goblin.h"


class Game {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::RenderWindow* window;

    Assets assets;
    Map map;
    Knight knight;
    Goblin goblin;

    //TO DELETE
    sf::Texture gridTexture;
    sf::Sprite grid;


    // ----- event polling ---------------------------------------------------------------------------------------------
    auto updateEvents() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto updateMap() -> void;
    auto updateKnight() -> void;
    auto updateGoblin() -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Game();
    ~Game();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto isRunning() -> bool;
    auto updateState() -> void;
    auto render() -> void;

};
