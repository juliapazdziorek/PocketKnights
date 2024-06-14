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

    for (auto const& mapBorder : map.getMapBorders()) {
        if (knight.isCollidingWith(*mapBorder)) {
            knight.onCollisionWith(*mapBorder);
        }
    }

    for (auto const& goblin : goblins) {
        for (auto const& mapBorder : map.getMapBorders()) {
            if (goblin->isCollidingWith(*mapBorder)) {
                goblin->onCollisionWith(*mapBorder);
            }
        }

        if (goblin->isCollidingWith(knight)) {
           goblin->onCollisionWith(knight);
        }
    }


/*    for (auto const& movingCollidable : movingCollidables) {
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
    }*/
}

auto Game::updateMap() -> void {
    map.updateState();
}

auto Game::updateKnight() -> void {
    knight.updateState();
}

auto Game::updateGoblins() -> void {
    for (auto& goblin : goblins) {
        goblin->updateState();
        goblin->setChasingPosition(knight.getPosition());
    }
}

auto Game::updateLifeSpan() -> void {
    movingCollidables.erase(std::remove_if(movingCollidables.begin(), movingCollidables.end(),
                              [](Collidable* collidable){return !collidable->isAlive; }), movingCollidables.end());

    auto toEraseGoblins = std::ranges::remove_if(goblins, [](std::unique_ptr<Goblin> const& goblin){return !goblin->isAlive; });
    goblins.erase(toEraseGoblins.begin(), toEraseGoblins.end());

}



// ---- private methods ------------------------------------------------------------------------------------------------

auto Game::observeGameState() -> void {

    switch (gameState) {
        case GameState::MENU: {

            break;
        }

        case GameState::PAUSE: {

            break;
        }

        case GameState::FIRST_WAVE: {

            // initialize wave
            if (doInitializeFirstWave) {
                initializeFirstWave();
                doInitializeFirstWave = false;
            }

            // observe wave state
            observeFirstWaveState();
            break;
        }

        case GameState::SECOND_WAVE: {


            // initialize wave
            if (doInitializeSecondWave) {
                initializeSecondWave();
                doInitializeSecondWave = false;
            }

            // observe wave state
            observeSecondWaveState();
            break;
        }

        case GameState::THIRD_WAVE: {

            // initialize wave
            if (doInitializeThirdWave) {
                initializeThirdWave();
                doInitializeThirdWave = false;
            }

            // observe wave state
            observeThirdWaveState();
            break;
        }
    }
}


auto Game::updateAttacks() -> void {

    // goblins being attacked
    for (auto& goblin : goblins) {
        if (knight.getCurrentAttack().isCollidingWith(*goblin)) {
            goblin->onCollisionWith(knight.getCurrentAttack());
        }

        if (goblin->getCurrentAttack().isCollidingWith(knight)) {
            knight.onCollisionWith(goblin->getCurrentAttack());
        }

    }

    // knight being attacked


    //TODO for goblins same

}


auto Game::initializeFirstWave() -> void {
    switch (difficultyLevel) {
        case DifficultyLevel::EASY: {
            spawnGoblin(1);
            break;
        }
        case DifficultyLevel::MEDIUM: {
            spawnGoblin(2);
            break;
        }
        case DifficultyLevel::HARD: {
            spawnGoblin(3);
            break;
        }
    }

}


auto Game::observeFirstWaveState() -> void {

}


auto Game::initializeSecondWave() -> void {

}


auto Game::observeSecondWaveState() -> void {

}


auto Game::initializeThirdWave() -> void {

}


auto Game::observeThirdWaveState() -> void {

}


auto Game::spawnGoblin(int amount) -> void { //TODO !(not tested)!

    enum class Island {
        WEST = 0, NORTH = 1, EAST = 2
    };
    Island island;

    for (int i = 1; i <= amount; ++i) {
        auto islandId = mathRandomInCpp(0, 2);
        island = static_cast<Island>(islandId);

        auto goblin = std::make_unique<Goblin>();

        switch (island) {
            case Island::WEST: {
                goblin->setPosition(sf::Vector2f((float)(-192 * i), 180));
                break;
            }

            case Island::NORTH: {
                goblin->setPosition(sf::Vector2f(352, (float)(-192 * i)));
                break;
            }

            case Island::EAST: {
                goblin->setPosition(sf::Vector2f((float)(832 + (192 * i)), 368));
                break;
            }
        }
        goblins.push_back(std::move(goblin));
    }

}



//public

// ----- constructor / destructor --------------------------------------------------------------------------------------

Game::Game(sf::RenderWindow& window) {

    // window
    this->window = &window;

    //game state
    doInitializeFirstWave = true;
    doInitializeSecondWave = false;
    doInitializeThirdWave = false;
    gameState = GameState::FIRST_WAVE; //TODO : powiino byc menu ale huj
    difficultyLevel = DifficultyLevel::EASY;

    movingCollidables.push_back(&knight);

    /*auto goblin1 = Goblin();
    goblin1.setPosition(sf::Vector2f((float)(-192 * 1), 176));
    auto goblin2 = Goblin();
    goblin2.setPosition(sf::Vector2f((float)(-192 * 2), 176));
    auto goblin3 = Goblin();
    goblin3.setPosition(sf::Vector2f(848 + 192, 368));
    goblins.push_back(goblin1);
    goblins.push_back(goblin2);
    goblins.push_back(goblin3);*/

    /*for (auto& goblin : goblins) {
        movingCollidables.push_back(&goblin);
    }*/



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
    observeGameState();

    updateEvents();
    handleCollision();

    updateKnight();
    updateGoblins();
    updateAttacks();
    updateLifeSpan();
    updateMap();

}

auto Game::render() -> void {

    // render window
    window->clear(sf::Color(71, 171, 169));

    // render map
    map.render(window);

    // render entities
    if (knight.isAlive) knight.render(window);
    for (auto& goblin : goblins) {
        goblin->render(window);
    }

    //TODO TO DELETE
    //this->window->draw(grid);

    window->display();
}





