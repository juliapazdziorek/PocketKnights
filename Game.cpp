#include "Game.h"

// private:


// ----- event updating  -----------------------------------------------------------------------------------------------

auto Game::updateEvents() -> void {
    for (auto event = sf::Event(); this->window->pollEvent(event); ) {

        // close game
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }

    // spawn blue tnt in second and third wave
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && tntBlueClock.getElapsedTime() >= sf::seconds(5)
        && (gameState == GameState::SECOND_WAVE || gameState == GameState::THIRD_WAVE)) {
        spawnTnt(TntColor::BLUE);
        tntBlueClock.restart();
    }

}


auto Game::updateMap() -> void {

    // update map state
    map.updateState();
}


auto Game::updateKnight() -> void {

    // update knight state
    knight.updateState();
}


auto Game::updateGoblins() -> void {

    // update goblins state and chasing position
    for (auto& goblin : goblins) {
        goblin->updateState();
        goblin->setChasedPosition(knight.getPosition());
    }
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


auto Game::updateResourcesMeat() -> void {

    // update meat state
    for (auto const& meat : resourcesMeat) {
        meat->updateState();
    }
}


auto Game::updateTnt() -> void {
    for (auto const& tnt : tntVector) {
        switch (tnt->getTntColor()) {

            // set chase position of blue tnt
            case TntColor::BLUE: {
                if (!goblins.empty()) {
                    tnt->setChasedPosition(goblins[0]->getPosition());
                }
                break;
            }

            // set chase position of red tnt
            case TntColor::RED: {
                tnt->setChasedPosition(knight.getPosition());
                break;
            }
        }

        // update tnt state
        tnt->updateState();
    }
}


auto Game::updateAttacks() -> void {

    // goblins being attacked
    for (auto& goblin : goblins) {
        if (knight.getCurrentAttack().isCollidingWith(*goblin)) {
            goblin->onCollisionWith(knight.getCurrentAttack());
        }

        // knight being attacked
        if (goblin->getCurrentAttack().isCollidingWith(knight)) {
            knight.onCollisionWith(goblin->getCurrentAttack());
        }
    }

    // sheep being attacked
    for (auto const& sheep : flockOfSheep) {
        if (knight.getCurrentAttack().isCollidingWith(*sheep)) {
            sheep->onCollisionWith(knight.getCurrentAttack());
        }
    }

    // tnt being attacked
    for (auto const& tnt : tntVector) {
        switch (tnt->getTntColor()) {

            // check if blue tnt are getting attacked
            case TntColor::BLUE: {
                for (auto const& goblin : goblins) {
                    if (tnt->isCollidingWith(goblin->getCurrentAttack())) {
                        tnt->onCollisionWith(goblin->getCurrentAttack());
                    }
                }
                break;
            }

            // check if red tnt are getting attacked
            case TntColor::RED: {
                if (tnt->isCollidingWith(knight.getCurrentAttack())) {
                    tnt->onCollisionWith(knight.getCurrentAttack());
                }
            }
        }
    }
}


auto Game::updateLifeSpan() -> void {

    // handle goblins lifespan
    auto toEraseGoblins = std::ranges::remove_if(goblins,[](std::unique_ptr<Goblin> const& goblin) { return !goblin->isAlive; });
    goblins.erase(toEraseGoblins.begin(), toEraseGoblins.end());

    // if sheep dies spawn meat
    for (auto const &sheep: flockOfSheep) {
        if (!sheep->isAlive) {
            spawnMeat(sheep->getPosition());
        }
    }

    // handle sheep lifespan
    auto toEraseSheep = std::ranges::remove_if(flockOfSheep,[](std::unique_ptr<Sheep> const& sheep) { return !sheep->isAlive; });
    flockOfSheep.erase(toEraseSheep.begin(), toEraseSheep.end());

    // handle meat lifespan
    auto toEraseMeat = std::ranges::remove_if(resourcesMeat,[](std::unique_ptr<Meat> const& meat) { return !meat->isAlive; });
    resourcesMeat.erase(toEraseMeat.begin(), toEraseMeat.end());

    // handle tnt lifespan
    auto toEraseTnt = std::ranges::remove_if(tntVector,[](std::unique_ptr<Tnt> const& tnt) { return !tnt->isAlive; });
    tntVector.erase(toEraseTnt.begin(), toEraseTnt.end());
}


// ---- private methods ------------------------------------------------------------------------------------------------

// game progress

auto Game::observeGameState() -> void {
    switch (gameState) {

        case GameState::MENU: {

            // observe menu state
            observeMenuState();
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


auto Game::observeMenuState() -> void {

    // when difficulty level chosen start first wave
    if (menu.getDifficultyLevel() != DifficultyLevel::NONE) {
        difficultyLevel = menu.getDifficultyLevel();
        gameState = GameState::FIRST_WAVE;
        doInitializeFirstWave = true;
    }
}


auto Game::initializeFirstWave() -> void {
    readyToProgress = false;

    // spawn goblins accordingly
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
        case DifficultyLevel::NONE:
            break;
    }
}


auto Game::observeFirstWaveState() -> void {

    // check if all the goblins have been killed
    if (goblins.empty() && !readyToProgress) {
        readyToProgress = true;
        progressClock.restart();
    }

    // stop drawing subtitles after few seconds
    if (subtitleClock.getElapsedTime() >= sf::seconds(3)) {
        drawWave1 = false;
    }

    // start another wave after goblins have been killed and few seconds
    if (progressClock.getElapsedTime() >= sf::seconds(5) && readyToProgress) {
        gameState = GameState::SECOND_WAVE;
        doInitializeSecondWave = true;
    }
}


auto Game::initializeSecondWave() -> void {
    readyToProgress = false;

    // spawn goblins accordingly
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
        case DifficultyLevel::NONE:
            break;
    }
}


auto Game::observeSecondWaveState() -> void {

    // check if all the goblins have been killed
    if (goblins.empty() && !readyToProgress) {
        readyToProgress = true;
        progressClock.restart();
    }

    // stop drawing subtitles after few seconds
    if (subtitleClock.getElapsedTime() >= sf::seconds(3)) {
        drawWave2 = false;
    }

    // start another wave after goblins have been killed and few seconds
    if (progressClock.getElapsedTime() >= sf::seconds(7) && readyToProgress) {
        gameState = GameState::THIRD_WAVE;
        doInitializeThirdWave = true;
    }
}


auto Game::initializeThirdWave() -> void {
    readyToProgress = false;

    // spawn goblins accordingly
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
        case DifficultyLevel::NONE:
            break;
    }
}


auto Game::observeThirdWaveState() -> void {

    // draw Victory! when goblins have been killed
    if (goblins.empty() && !readyToProgress) {
        drawVictory = true;
    }

    // stop drawing subtitles after few seconds
    if (subtitleClock.getElapsedTime() >= sf::seconds(3)) {
        drawWave3 = false;
    }
}


// spawning

auto Game::spawnGoblin(int amount) -> void { //TODO !(not tested)!

    // island enum
    enum class Island {
        WEST = 0, NORTH = 1, EAST = 2
    };
    Island island;

    for (int i = 1; i <= amount; ++i) {

        // choose random island
        auto islandId = mathRandomInCpp(0, 2);
        island = static_cast<Island>(islandId);

        auto goblin = std::make_unique<Goblin>();

        // spawn new goblin accordingly
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


auto Game::spawnMeat(sf::Vector2f meatPosition) -> void {

    // spawn new meat
    auto meat = std::make_unique<Meat>(meatPosition);
    resourcesMeat.push_back(std::move(meat));
}


auto Game::spawnTnt(TntColor color) -> void {

    // spawn new tnt
    auto tnt = std::make_unique<Tnt>(color);

    // set tnt's position
    switch (color) {
        case TntColor::BLUE: {
            tnt->setPosition(knight.getPosition());
            break;
        }

        case TntColor::RED:
            tnt->setPosition(goblins[0]->getPosition());
            break;
    }

    tntVector.push_back(std::move(tnt));
}


// handling collision

auto Game::handleCollision() -> void {

    // knight colliding with map borders
    for (auto const& mapBorder : map.getMapBorders()) {
        if (knight.isCollidingWith(*mapBorder)) {
            knight.onCollisionWith(*mapBorder);
        }
    }


    for (auto const& goblin : goblins) {

        // goblins colliding with map borders
        for (auto const& mapBorder : map.getMapBorders()) {
            if (goblin->isCollidingWith(*mapBorder)) {
                goblin->onCollisionWith(*mapBorder);
            }
        }

        // goblins colliding with knight
        if (goblin->isCollidingWith(knight)) {
            goblin->onCollisionWith(knight);
        }
    }

    // meat and knight colliding
    for (auto const& meat : resourcesMeat) {
        if (meat->isCollidingWith(knight)) {
            meat->onCollisionWith(knight);
            knight.onCollisionWith(*meat);
        }
    }

    for (auto const& tnt : tntVector) {

        // tnt colliding with map borders
        for (auto const &mapBorder: map.getMapBorders()) {
            if (tnt->isCollidingWith(*mapBorder)) {
                tnt->onCollisionWith(*mapBorder);
            }
        }

        // knight colliding with red tnt
        if (tnt->isCollidingWith(knight) && tnt->getTntColor() == TntColor::RED) {
            tnt->onCollisionWith(knight);
        }

        // goblins are colliding with ble tnt
        for (auto const &goblin: goblins) {
            if (tnt->isCollidingWith(*goblin) && tnt->getTntColor() == TntColor::BLUE) {
                tnt->onCollisionWith(*goblin);
            }
        }
    }
}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Game::Game(sf::RenderWindow& window) {

    // window
    this->window = &window;

    // game state
    gameState = GameState::MENU;
    difficultyLevel = DifficultyLevel::NONE;
    readyToProgress = false;
    doInitializeFirstWave = false;
    doInitializeSecondWave = false;
    doInitializeThirdWave = false;

    // menu
    menu = Menu();

    // assets
    assets = Assets();

    // map
    map = Map();

    // knight
    knight = Knight();

    // goblins
    goblins = std::vector<std::unique_ptr<Goblin>>();

    // flock of sheep
    maxNumberOfSheep = 8;
    flockOfSheep = std::vector<std::unique_ptr<Sheep>>();
    sheepPositions.emplace_back(0, 230);
    sheepPositions.emplace_back(220, 450);
    sheepPositions.emplace_back(250, 480);
    sheepPositions.emplace_back(200, 180);
    sheepPositions.emplace_back(300, 240);
    sheepPositions.emplace_back(540, 160);
    sheepPositions.emplace_back(440, 430);
    sheepPositions.emplace_back(750, 350);

    // subtitles variables
    drawWave1 = false;
    drawWave2 = false;
    drawWave3 = false;
    drawVictory = false;

    //TODO to delete
    /*if (!gridTexture.loadFromFile("grid.png")) {
        fmt::println("File can not load from file: grid.png");
    }
    gridTexture.setSmooth(true);
    grid.setTexture(gridTexture);*/
}


// ----- public methods ------------------------------------------------------------------------------------------------

// update state

auto Game::updateState() -> void {

    // observe game state
    observeGameState();

    // update game state
    if (gameState == GameState::MENU) menu.updateState();
    updateEvents();
    handleCollision();
    updateKnight();
    updateGoblins();
    updateFlockOfSheep();
    updateResourcesMeat();
    updateTnt();
    updateAttacks();
    updateLifeSpan();
    updateMap();
}


// render

auto Game::render() -> void {

    // clear window
    window->clear(sf::Color(71, 171, 169));

    // render map
    map.render(window);

    // render meat
    for (auto const& meat : resourcesMeat) {
        meat->render(window);
    }

    // render flock of sheep
    for (auto const& sheep : flockOfSheep) {
        sheep->render(window);
    }

    // render tnt
    for (auto const& tnt : tntVector) {
        tnt->render(window);
    }

    // render goblins
    for (auto const& goblin : goblins) {
        goblin->render(window);
    }

    // render knight
    if (knight.isAlive) knight.render(window);

    // render menu
    if (gameState == GameState::MENU) {
        menu.render(window);
    }

    // render subtitles
    if (drawWave1) window->draw(Assets::getSubtitles()["wave1"]);
    if (drawWave2) window->draw(Assets::getSubtitles()["wave2"]);
    if (drawWave3) window->draw(Assets::getSubtitles()["wave3"]);
    if (drawVictory) window->draw(Assets::getSubtitles()["victory!"]);
    if (!knight.isAlive) window->draw(Assets::getSubtitles()["gameOver"]);

    //TODO to delete
    //this->window->draw(grid);

    // display window
    window->display();
}


// isRunning

auto Game::isRunning() -> bool {
    return window->isOpen();
}
