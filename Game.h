#pragma once

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Engine/Collidable.h"
#include "Engine/Utility.h"
#include "Assets/Assets.h"
#include "Assets/MapBorder.h"
#include "Map.h"
#include "Knight.h"
#include "Goblin.h"


class Game {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::RenderWindow* window;

    bool doInitializeFirstWave;
    bool doInitializeSecondWave;
    bool doInitializeThirdWave;

    Assets assets;
    Map map;

    Knight knight;
    std::vector<std::unique_ptr<Goblin>> goblins;

    std::vector<Collidable*> movingCollidables;
    std::vector<std::unique_ptr<Collidable>> mapBorders;
    std::vector<std::unique_ptr<Collidable>> attacks;
    std::vector<std::unique_ptr<Collidable>> collidables;

    enum class GameState {MENU, PAUSE, FIRST_WAVE, SECOND_WAVE, THIRD_WAVE};
    GameState gameState;

    enum class DifficultyLevel {EASY, MEDIUM, HARD};
    DifficultyLevel difficultyLevel;

    sf::Clock progressClock;
    bool readyToProgress;

    //TODO TO DELETE
    /*sf::Texture gridTexture;
    sf::Sprite grid;*/


    // ----- event polling ---------------------------------------------------------------------------------------------
    auto updateEvents() -> void;

    // ----- update events ---------------------------------------------------------------------------------------------
    auto updateMap() -> void;
    auto updateKnight() -> void;
    auto updateGoblins() -> void;
    auto updateAttacks() -> void;
    auto updateLifeSpan() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // game progress
    auto observeGameState() -> void;
    auto initializeFirstWave() -> void;
    auto observeFirstWaveState() -> void;
    auto initializeSecondWave() -> void;
    auto observeSecondWaveState() -> void;
    auto initializeThirdWave() -> void;
    auto observeThirdWaveState() -> void;
    auto spawnGoblin(int amount) -> void;


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
