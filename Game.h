#pragma once

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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

    //TODO TO DELETE
    /*sf::Texture gridTexture;
    sf::Sprite grid;*/


    // ----- event polling ---------------------------------------------------------------------------------------------
    auto updateEvents() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto updateMap() -> void;
    auto updateKnight() -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    explicit Game(sf::RenderWindow& window);
    ~Game() = default;

    // ----- public methods --------------------------------------------------------------------------------------------
    auto isRunning() -> bool;
    //auto handleCollision() -> void;
    auto updateState() -> void;
    auto render() -> void;

};
