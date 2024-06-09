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

auto Game::handleCollision() -> void {
    for (auto const& movingCollidable : movingCollidables) {
       for (auto const& mapBorder : map.getMapBorders()) {
            if (movingCollidable->isCollidingWith(*mapBorder)) {
                movingCollidable->onCollisionWith(*mapBorder);
            }
        }
        for (auto const& collidable : collidables ) {
            if (movingCollidable->isCollidingWith(*collidable)) {
                movingCollidable->onCollisionWith(*collidable);
            }
        }
    }
}

auto Game::updateMap() -> void {
    map.updateState();
}

auto Game::updateKnight() -> void {
    knight.updateState();
}

auto Game::updateGoblins() -> void {
    for (auto& goblin : goblins) {
        goblin.updateState();
    }
}



//public

// ----- constructor / destructor --------------------------------------------------------------------------------------

Game::Game(sf::RenderWindow& window) {

    // window
    this->window = &window;

    movingCollidables.push_back(&knight);

    gameState = GameState::MENU;
    difficultyLevel = DifficultyLevel::MEDIUM;

    goblins.emplace_back();

    for (auto& goblin : goblins) {
        movingCollidables.push_back(&goblin);
    }



    //TODO TO DELETE
    /*if (!gridTexture.loadFromFile("grid.png")) {
        fmt::println("File can not load from file: grid.png");
    }
    gridTexture.setSmooth(true);
    grid.setTexture(gridTexture);*/

}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Game::isRunning() -> bool {
    return window->isOpen();
}

auto Game::updateState() -> void {
    updateEvents();
    handleCollision();

    updateKnight();
    updateGoblins();
    updateMap();

}

auto Game::render() -> void {

    // render window
    window->clear(sf::Color(71, 171, 169));

    // render map
    map.render(window);

    // render entities
    knight.render(window);
    for (auto& goblin : goblins) {
        goblin.render(window);
    }

    //TODO TO DELETE
    //this->window->draw(grid);

    window->display();
}

