#include "Game.h"

//private

// ----- event polling -------------------------------------------------------------------------------------------------

auto Game::updateEvents() -> void {
    for (auto event = sf::Event(); this->window->pollEvent(event); ) {

        // closing game
        if (event.type == sf::Event::Closed) {
            window->close();
        }

    }
}


// ----- private methods -----------------------------------------------------------------------------------------------

auto Game::updateKnight() -> void {
    this->knight.updateState();
}

auto Game::updateGoblin() -> void {
    this->goblin.updateState();
}


//public

// ----- constructor / destructor --------------------------------------------------------------------------------------

Game::Game() {

    //window
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pocket Knight", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

    //assets
    this->assets = Assets();
    this->knight = Knight();
    this->goblin = Goblin();

}

Game::~Game() {
    delete this->window;
}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Game::isRunning() -> bool {
    return this->window->isOpen();
}

auto Game::updateState() -> void {
    updateEvents();
    updateKnight();
    updateGoblin();

}

auto Game::render() -> void {
    this->window->clear(sf::Color(71, 171, 169));

    this->goblin.render(this->window);
    this->knight.render(this->window);

    this->window->display();

}
