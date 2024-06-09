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
       for (auto const& mapBorder : mapBorders) {
            if (movingCollidable->isCollidingWith(*mapBorder)) {
                movingCollidable->onCollisionWith(*mapBorder);
            }
        } /*
        for (auto const& collidable : collidables ) {
            if (movingCollidable->isCollidingWith(*collidable)) {
                movingCollidable->onCollisionWith(*collidable);
            }
        }*/
    }
}

auto Game::updateMap() -> void {
    this->map.updateState();
}

auto Game::updateKnight() -> void {
    this->knight.updateState();
}



//public

// ----- constructor / destructor --------------------------------------------------------------------------------------

Game::Game(sf::RenderWindow& window) {

    // window
    this->window = &window;

    // (assets are created by default)
    mapBorders.insert(mapBorders.end(), map.getMapBorders().begin(), map.getMapBorders().end());

    movingCollidables.push_back(&knight);

    //TODO TO DELETE
    /*if (!gridTexture.loadFromFile("grid.png")) {
        fmt::println("File can not load from file: grid.png");
    }
    gridTexture.setSmooth(true);
    grid.setTexture(gridTexture);*/

}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Game::isRunning() -> bool {
    return this->window->isOpen();
}

auto Game::updateState() -> void {
    updateEvents();
    handleCollision();
    updateMap();
    updateKnight();
}

auto Game::render() -> void {

    // render window
    this->window->clear(sf::Color(71, 171, 169));

    // render map
    this->map.render(this->window);

    // render entities //TODO in vector maybe
    this->knight.render(this->window);

    //TODO TO DELETE
    //this->window->draw(grid);

    this->window->display();
}

