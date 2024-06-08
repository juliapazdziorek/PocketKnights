#include "Game.h"

#include <SFML/Window.hpp>

auto main() -> int {

    // ----- creating window -------------------------------------------------------------------------------------------
    auto window = sf::RenderWindow(sf::VideoMode(832, 640), "Pocket Knight", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    // ----- creating game ---------------------------------------------------------------------------------------------
    auto game = Game(window);

    // ----- game loop -------------------------------------------------------------------------------------------------
    while (game.isRunning()) {

        // update game state
        game.updateState();

        // render game
        game.render();

    }

}
