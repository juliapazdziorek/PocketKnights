#pragma once

#include <memory>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Engine/Collidable.h"
#include "Engine/Utility.h"
#include "Assets/Assets.h"
#include "Assets/MapBorder.h"
#include "DifficultyLevel.h"
#include "Map.h"
#include "Knight.h"
#include "Goblin.h"
#include "Meat.h"
#include "Menu.h"
#include "Sheep.h"


class Game {

private:

    // enums
    enum class GameState {MENU, FIRST_WAVE, SECOND_WAVE, THIRD_WAVE};

    // ----- variables -------------------------------------------------------------------------------------------------

    // window
    sf::RenderWindow* window;

    // game state
    GameState gameState;
    DifficultyLevel difficultyLevel;
    sf::Clock progressClock;
    bool readyToProgress;
    bool doInitializeFirstWave;
    bool doInitializeSecondWave;
    bool doInitializeThirdWave;

    // menu
    Menu menu;

    // assets
    Assets assets;

    // map
    Map map;

    // knight
    Knight knight;

    // goblins
    std::vector<std::unique_ptr<Goblin>> goblins;

    // flock of sheep
    int maxNumberOfSheep;
    sf::Clock spawnSheepClock;
    std::vector<std::unique_ptr<Sheep>> flockOfSheep;
    std::vector<sf::Vector2f> sheepPositions;

    // meat
    std::vector<std::unique_ptr<Meat>> resourcesMeat;

    // collision containers
    std::vector<std::unique_ptr<Collidable>> mapBorders;
    std::vector<std::unique_ptr<Collidable>> attacks;

    // subtitles variables
    sf::Clock subtitleClock;
    bool drawWave1;
    bool drawWave2;
    bool drawWave3;
    bool drawVictory;

    //TODO to delete
    /*sf::Texture gridTexture;
    sf::Sprite grid;*/


    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;
    auto updateMap() -> void;
    auto updateKnight() -> void;
    auto updateGoblins() -> void;
    auto updateFlockOfSheep() -> void;
    auto updateResourcesMeat() -> void;
    auto updateAttacks() -> void;
    auto updateLifeSpan() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // game progress
    auto observeGameState() -> void;
    auto observeMenuState() -> void;
    auto initializeFirstWave() -> void;
    auto observeFirstWaveState() -> void;
    auto initializeSecondWave() -> void;
    auto observeSecondWaveState() -> void;
    auto initializeThirdWave() -> void;
    auto observeThirdWaveState() -> void;

    // spawning
    auto spawnGoblin(int amount) -> void;
    auto spawnMeat(sf::Vector2f meatPosition) -> void;

    // handling collision
    auto handleCollision() -> void;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    explicit Game(sf::RenderWindow& window);

    // ----- public methods --------------------------------------------------------------------------------------------

    // update state
    auto updateState() -> void;

    // render
    auto render() -> void;

    // isRunning
    auto isRunning() -> bool;

};
