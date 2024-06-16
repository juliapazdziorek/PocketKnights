#pragma once

#include <SFML/Graphics.hpp>

#include "Assets/Assets.h"
#include "DifficultyLevel.h"

class Menu {

private:

    // ----- variables -------------------------------------------------------------------------------------------------

    // menu state
    DifficultyLevel difficultyLevel;

    // sprite variables
    sf::Sprite tabEasy;
    sf::Sprite tabMedium;
    sf::Sprite tabHard;

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateEvents() -> void;

public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    Menu();

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // update state
    auto updateState() -> void;

    // getters
    auto getDifficultyLevel() -> DifficultyLevel;

};


