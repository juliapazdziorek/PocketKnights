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


// ----- updating events -----------------------------------------------------------------------------------------------

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


// ---- private methods ------------------------------------------------------------------------------------------------

auto Game::spawnGoblins(int amount) -> void { //TODO !(not tested)!

    enum class Island {
        WEST, NORTH, EAST
    };
    Island island;

    //generate random number from 0 and set island variable according to enum

    switch (island) {
        case Island::WEST: {
            for (int i = 1; i <= amount; ++i) {
                auto goblin = Goblin();
                goblin.setPosition(sf::Vector2f((float)(-192 * i), 176));
                goblins.push_back(goblin);
            }
            break;
        }

        case Island::NORTH: {
            for (int i = 0; i < amount; ++i) {
                auto goblin = Goblin();
                goblin.setPosition(sf::Vector2f(0, 0));
                goblins.push_back(goblin);
            }
            break;
        }

        case Island::EAST: {
            for (int i = 0; i < amount; ++i) {
                auto goblin = Goblin();
                goblin.setPosition(sf::Vector2f(0, 0));
                goblins.push_back(goblin);
            }
            break;
        }
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

    auto goblin1 = Goblin();
    goblin1.setPosition(sf::Vector2f((float)(-192 * 1), 176));
    auto goblin2 = Goblin();
    goblin2.setPosition(sf::Vector2f((float)(-192 * 2), 176));
    auto goblin3 = Goblin();
    goblin3.setPosition(sf::Vector2f((float)(-192 * 3), 176));
    goblins.push_back(goblin1);
    goblins.push_back(goblin2);
    goblins.push_back(goblin3);

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



