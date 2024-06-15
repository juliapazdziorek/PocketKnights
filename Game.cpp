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
        goblin->setChasedPosition(knight.getPosition());
    }
}

auto Game::updateLifeSpan() -> void {
    auto toEraseGoblins = std::ranges::remove_if(goblins, [](std::unique_ptr<Goblin> const& goblin){return !goblin->isAlive; });
    goblins.erase(toEraseGoblins.begin(), toEraseGoblins.end());

    auto toEraseSheep = std::ranges::remove_if(flockOfSheep, [](std::unique_ptr<Sheep> const& sheep){return !sheep->isAlive; });
    flockOfSheep.erase(toEraseSheep.begin(), toEraseSheep.end());

}

auto Game::updateFlockOfSheep() -> void {

    // if not max number of sheep in the flock add new one
    if (flockOfSheep.size() < maxNumberOfSheep && spawnSheepClock.getElapsedTime() >= sf::seconds(5)) {

        // find position of new sheep
        auto positionFound = true;
        auto positionIndex = mathRandomInCpp(0, maxNumberOfSheep - 1);

        // if there are other sheep compare if position is occupied
        if (!flockOfSheep.empty()) {
            auto positionOccupied = false;
            for (auto const& sheep : flockOfSheep) {
                if (sheep->getPosition() == sheepPositions[positionIndex]) {
                    positionOccupied = true;
                }
            }
            if (positionOccupied)  {
                positionFound = false;
            }
        }

        // add new sheep to the flock
        if (positionFound) {
            auto sheep = std::make_unique<Sheep>();
            sheep->setPosition(sheepPositions[positionIndex]);
            flockOfSheep.push_back(std::move(sheep));
            spawnSheepClock.restart();
        }
    }

    // update sheep state
    for (auto const& sheep : flockOfSheep) {
        sheep->updateState();
    }
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

                drawWave1 = true;
                subtitleClock.restart();
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

                drawWave2 = true;
                subtitleClock.restart();
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

                drawWave3 = true;
                subtitleClock.restart();
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

    for (auto const& sheep : flockOfSheep) {
        if (knight.getCurrentAttack().isCollidingWith(*sheep)) {
            sheep->onCollisionWith(knight.getCurrentAttack());
        }
    }
}


auto Game::initializeFirstWave() -> void {
    readyToProgress = false;

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
    if (goblins.empty() && !readyToProgress) {
        readyToProgress = true;
        progressClock.restart();
    }

    if (subtitleClock.getElapsedTime() >= sf::seconds(3)) {
        drawWave1 = false;
    }


    if (progressClock.getElapsedTime() >= sf::seconds(5) && readyToProgress) {
        gameState = GameState::SECOND_WAVE;
        doInitializeSecondWave = true;
    }
}


auto Game::initializeSecondWave() -> void {
    readyToProgress = false;

    switch (difficultyLevel) {
        case DifficultyLevel::EASY: {
            spawnGoblin(2);
            break;
        }
        case DifficultyLevel::MEDIUM: {
            spawnGoblin(4);
            break;
        }
        case DifficultyLevel::HARD: {
            spawnGoblin(6);
            break;
        }
    }
}


auto Game::observeSecondWaveState() -> void {

    if (goblins.empty() && !readyToProgress) {
        readyToProgress = true;
        progressClock.restart();
    }

    if (subtitleClock.getElapsedTime() >= sf::seconds(3)) {
        drawWave2 = false;
    }

    if (progressClock.getElapsedTime() >= sf::seconds(7) && readyToProgress) {
        gameState = GameState::THIRD_WAVE;
        doInitializeThirdWave = true;
    }
}


auto Game::initializeThirdWave() -> void {
    readyToProgress = false;

    switch (difficultyLevel) {
        case DifficultyLevel::EASY: {
            spawnGoblin(4);
            break;
        }
        case DifficultyLevel::MEDIUM: {
            spawnGoblin(8);
            break;
        }
        case DifficultyLevel::HARD: {
            spawnGoblin(12);
            break;
        }
    }
}


auto Game::observeThirdWaveState() -> void {

    if (goblins.empty() && !readyToProgress) {
        drawVictory = true;
    }

    if (subtitleClock.getElapsedTime() >= sf::seconds(3)) {
        drawWave3 = false;
    }
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
    difficultyLevel = DifficultyLevel::HARD;

    movingCollidables.push_back(&knight);

    drawWave1 = false;
    drawWave2 = false;
    drawWave3 = false;

    maxNumberOfSheep = 8; //TODO set w zaleznosci od poziomu trudnosci
    sheepPositions.emplace_back(0, 230);
    sheepPositions.emplace_back(220, 450);
    sheepPositions.emplace_back(250, 480);
    sheepPositions.emplace_back(200, 180);
    sheepPositions.emplace_back(300, 240);
    sheepPositions.emplace_back(540, 160);
    sheepPositions.emplace_back(440, 430);
    sheepPositions.emplace_back(750, 350);
    spawnSheepClock.restart();

    /*for (auto sheepPosition : sheepPositions) {
        auto sheep = std::make_unique<Sheep>();
        sheep->setPosition(sheepPosition);
        flockOfSheep.push_back(std::move(sheep));
    }*/


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
    updateFlockOfSheep();

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
    for (auto const& goblin : goblins) {
        goblin->render(window);
    }

    for (auto const& sheep : flockOfSheep) {
        sheep->render(window);
    }

    if (knight.isAlive) knight.render(window);

    if (drawWave1) { window->draw(Assets::getSubtitles()["wave1"]); }
    if (drawWave2) { window->draw(Assets::getSubtitles()["wave2"]); }
    if (drawWave3) { window->draw(Assets::getSubtitles()["wave3"]); }

    if (drawVictory) { window->draw(Assets::getSubtitles()["victory!"]); }
    if (!knight.isAlive) { window->draw(Assets::getSubtitles()["gameOver"]); }


    //TODO TO DELETE
    //this->window->draw(grid);

    window->display();
}







