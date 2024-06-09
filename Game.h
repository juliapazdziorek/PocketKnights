#pragma once

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Engine/Collidable.h"
#include "Assets/Assets.h"
#include "Assets/MapBorder.h"
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
    std::vector<Goblin> goblins;

    std::vector<Collidable*> movingCollidables;
    std::vector<std::unique_ptr<Collidable>> mapBorders;
    std::vector<std::unique_ptr<Collidable>> collidables;

    enum class GameState {MENU, PAUSE, FIRST_WAVE, SECOND_WAVE, THIRD_WAVE};
    GameState gameState;

    enum class DifficultyLevel {EASY, MEDIUM, HARD};
    DifficultyLevel difficultyLevel;

    //TODO TO DELETE
    /*sf::Texture gridTexture;
    sf::Sprite grid;*/


    // ----- event polling ---------------------------------------------------------------------------------------------
    auto updateEvents() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto updateMap() -> void;
    auto updateKnight() -> void;
    auto updateGoblins() -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    explicit Game(sf::RenderWindow& window);
    ~Game() = default;

    // ----- public methods --------------------------------------------------------------------------------------------
    auto isRunning() -> bool;
    auto handleCollision() -> void;
    auto updateState() -> void;
    auto render() -> void;

};
