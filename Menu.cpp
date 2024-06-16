#include "Menu.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Menu::updateEvents() -> void {

    // if 1 set to easy
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        difficultyLevel = DifficultyLevel::EASY;
    }

    // if 2 set to medium
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        difficultyLevel = DifficultyLevel::MEDIUM;
    }

    // if 3 set to hard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        difficultyLevel = DifficultyLevel::HARD;
    }

}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Menu::Menu() {

    // menu state
    difficultyLevel = DifficultyLevel::NONE;

    // easyTab
    tabEasy.setTexture(Assets::getTextureBanner());
    tabEasy.setPosition(sf::Vector2f(32, 60));
    tabEasy.setScale(sf::Vector2f(4, 1));

    // mediumTab
    tabMedium.setTexture(Assets::getTextureBanner());
    tabMedium.setPosition(sf::Vector2f(32, 200));
    tabMedium.setScale(sf::Vector2f(4, 1));

    // hardTab
    tabHard.setTexture(Assets::getTextureBanner());
    tabHard.setPosition(sf::Vector2f(32, 340));
    tabHard.setScale(sf::Vector2f(4, 1));

}


// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto Menu::render(sf::RenderTarget *window) -> void {

    // render banners
    window->draw(tabEasy);
    window->draw(tabMedium);
    window->draw(tabHard);
    window->draw(Assets::getSubtitles()["easy"]);
    window->draw(Assets::getSubtitles()["medium"]);
    window->draw(Assets::getSubtitles()["hard"]);
}


// update states

auto Menu::updateState() -> void {

    // update events
    updateEvents();
}


// getters

auto Menu::getDifficultyLevel() -> DifficultyLevel {
    return difficultyLevel;
}




