#include "Goblin.h"

//private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Goblin::updateEvents() -> void {

    // if not in other animation
    if(!attacking) {

        // moving left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            goblinState = GoblinState::RUNNING_LEFT;
            goblinFacing = GoblinFacing::LEFT;
            velocity.x = -movingSpeed;
            velocity.y = 0;
            if (!isColliding) goblin.move(velocity);

            updatePositionVariable();
            updateBoundsVariable();
            nextPositionBounds.left = bounds.left - movingSpeed;
            nextPositionBounds.top = bounds.top;
        }

        // moving right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            goblinState = GoblinState::RUNNING_RIGHT;
            goblinFacing = GoblinFacing::RIGHT;
            velocity.x = movingSpeed;
            velocity.y = 0;
            if (!isColliding) goblin.move(velocity);

            updatePositionVariable();
            updateBoundsVariable();
            nextPositionBounds.left = bounds.left + movingSpeed;
            nextPositionBounds.top = bounds.top;
        }

        // moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            goblinFacing = GoblinFacing::UP;
            velocity.x = 0;
            velocity.y = -movingSpeed;
            if (!isColliding) goblin.move(velocity);

            updatePositionVariable();
            updateBoundsVariable();
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top- movingSpeed;

            // some animation while moving up
            if (goblinState == GoblinState::STANDING) {
                goblinState = GoblinState::RUNNING_LEFT;
            }
        }

            // moving down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            goblinFacing = GoblinFacing::DOWN;
            velocity.x = 0;
            velocity.y = movingSpeed;
            if (!isColliding) goblin.move(velocity);

            updatePositionVariable();
            updateBoundsVariable();
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top + movingSpeed;

            // some animation while moving down
            if (this->goblinState == GoblinState::STANDING) {
                this->goblinState = GoblinState::RUNNING_RIGHT;
            }
        }

        // attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
            this->goblinState = GoblinState::ATTACKING;
            this->attacking = true;
            this->attackAnimationClock.restart();
            this->attackPosition = sf::Vector2f(this->position);
        }

        // standing
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            this->goblinState = GoblinState::STANDING;
        }
    }
}


auto Goblin::updateMovement() -> void {

    // if not ready to chase move to chasing position
    if (!readyToChase) {
        moveToChasingPosition();
        return;
    }

    // chase
    chase();

}


auto Goblin::updateCollision() -> void {
    // checking if still colliding
    for (auto const& collidable : collidables) {
        if (!this->isCollidingWith(*collidable)) {
            collidables.erase(std::remove(collidables.begin(), collidables.end(), collidable), collidables.end());
        }
    }

    // if not colliding with anything
    if (collidables.empty()) {
        isColliding = false;
    }
}


auto Goblin::updateAttack() -> void {
    if(this->attacking) {

        // not moving while attack
        while (attackAnimationClock.getElapsedTime() <= sf::seconds(0.1f)) {
            this->goblin.setPosition(attackPosition);
        }

        // move on after attacking
        if (attackAnimationClock.getElapsedTime() >= sf::seconds(0.6f)) {
            this->attacking = false;
        }
    }
}


auto Goblin::updateIsAlive() -> void {
    if (health < 0) {
        isAlive = false;
    }
}


auto Goblin::updateTexture() -> void {

    // apply animations for: standing, running
    switch (this->goblinState) {
        case GoblinState::STANDING: {
            animations[0].updateFrame(animationClock);
            animations[0].applyTexture(goblin);
            break;
        }

        case GoblinState::RUNNING_RIGHT: {
            animations[1].updateFrame(animationClock);
            animations[1].applyTexture(goblin);
            break;
        }

        case GoblinState::RUNNING_LEFT: {
            animations[2].updateFrame(animationClock);
            animations[2].applyTexture(goblin);
            break;
        }

        // apply animations for: attacking
        case GoblinState::ATTACKING: {
            switch (goblinFacing) {
                case GoblinFacing::RIGHT: {
                    animations[3].updateFrame(animationClock);
                    animations[3].applyTexture(goblin);
                    break;
                }

                case GoblinFacing::LEFT: {
                    animations[4].updateFrame(animationClock);
                    animations[4].applyTexture(goblin);
                    break;
                }

                case GoblinFacing::UP: {
                    animations[5].updateFrame(animationClock);
                    animations[5].applyTexture(goblin);
                    break;
                }

                case GoblinFacing::DOWN: {
                    animations[6].updateFrame(animationClock);
                    animations[6].applyTexture(goblin);
                    break;
                }
            }
            break;
        }
    }
}


auto Goblin::updatePositionVariable() -> void {

    // updates position variable
    position = goblin.getPosition();
}


auto Goblin::updateBoundsVariable() -> void {

    // updates bounds accordingly to position
    bounds.left = position.x + 43;
    bounds.top = position.y + 54;
}


// ----- private methods -----------------------------------------------------------------------------------------------

auto Goblin::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}


auto Goblin::moveToChasingPosition() -> void {

    // starting from west island
    if (position.x <= 160) {
        moveRight();
        fmt::println("x: {}", position.x);
        fmt::println("y: {}", position.y);
        fmt::println("");

        // check if ready to chase
        if (position.x >= 160) {
            readyToChase = true;
            fmt::println("TWOJA STARA 1");
        }
    }

    // starting from north island
    if (position.y <= 176) {
        moveDown();

        // check if ready to chase
        if (position.y >= 176) {
            readyToChase = true;
            fmt::println("TWOJA STARA 2");

        }
    }

    // starting from east island
    if (position.x >= 544) {
        moveLeft();

        // check if ready to chase
        if (position.x <= 544) {
            readyToChase = true;
            fmt::println("TWOJA STARA 3");
        }
    }
}


auto Goblin::chase() -> void {

    if (position.y > chasingPosition.y) {
        moveUp();
    }

    if (position.y < chasingPosition.y) {
        moveDown();
    }

    if (position.x < chasingPosition.x) {
       moveRight();
    }

    if (position.x > chasingPosition.x) {
        moveLeft();
    }

}


auto Goblin::moveLeft() -> void {

    // goblin state
    goblinState = GoblinState::RUNNING_LEFT;
    goblinFacing = GoblinFacing::LEFT;

    // move goblin left
    velocity.x = -movingSpeed;
    velocity.y = 0;
    if (!isColliding) goblin.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    nextPositionBounds.left = bounds.left - movingSpeed;
    nextPositionBounds.top = bounds.top;
}


auto Goblin::moveRight() -> void {

    // goblin state
    goblinState = GoblinState::RUNNING_RIGHT;
    goblinFacing = GoblinFacing::RIGHT;

    // move goblin right
    velocity.x = movingSpeed;
    velocity.y = 0;
    if (!isColliding) goblin.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    nextPositionBounds.left = bounds.left + movingSpeed;
    nextPositionBounds.top = bounds.top;
}


auto Goblin::moveUp() -> void {

    // goblin state
    goblinFacing = GoblinFacing::UP;

    // if first move is up give some animation
    if (goblinState == GoblinState::STANDING) {
        goblinState = GoblinState::RUNNING_LEFT;
    }

    // move goblin up
    velocity.x = 0;
    velocity.y = -movingSpeed;
    if (!isColliding) goblin.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    nextPositionBounds.left = bounds.left;
    nextPositionBounds.top = bounds.top- movingSpeed;

}

auto Goblin::moveDown() -> void {

    // goblin state
    goblinFacing = GoblinFacing::DOWN;

    // if first move is up give some animation
    if (this->goblinState == GoblinState::STANDING) {
        this->goblinState = GoblinState::RUNNING_RIGHT;
    }

    // move goblin down
    velocity.x = 0;
    velocity.y = movingSpeed;
    if (!isColliding) goblin.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    nextPositionBounds.left = bounds.left;
    nextPositionBounds.top = bounds.top + movingSpeed;

}



auto Goblin::attack() -> void {

}



//public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Goblin::Goblin() {
    // goblin state
    goblinState = GoblinState::STANDING;
    goblinFacing = GoblinFacing::DOWN;
    isAlive = true;
    health = 50;

    // sprite variables
    position = sf::Vector2f(-64, 32 * 5 + 16); //TODO -> będą spawnowane w różnych miejscach, więc to jest do usunięcia w którymś momencie
    goblin.setPosition(position);
    scale = sf::Vector2f(0.5f, 0.5f);
    goblin.setScale(scale);
    bounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 54), sf::Vector2f(10, 10));

    // animations
    animations.push_back(Assets::getAnimationGoblinStanding());
    animations.push_back(Assets::getAnimationGoblinRunningRight());
    animations.push_back(Assets::getAnimationGoblinRunningLeft());
    animations.push_back(Assets::getAnimationGoblinAttackRight());
    animations.push_back(Assets::getAnimationGoblinAttackLeft());
    animations.push_back(Assets::getAnimationGoblinAttackUp());
    animations.push_back(Assets::getAnimationGoblinAttackDown());

    // movement variables
    readyToChase = false;
    velocity = sf::Vector2f(0, 0);
    movingSpeed = 1;
    isColliding = false;
    chasingPosition = sf::Vector2f(416, 320);
    nextPositionBounds = bounds;

    // attack variables
    attacking = false;
    attackPosition = position;
    attackBounds = sf::FloatRect (sf::Vector2f(position.x + 43, position.y + 56) ,sf::Vector2f(32, 32)); //TODO
    currentAttack = Attack(attackBounds);
    previousBeingAttacked = Attack();


    //TODO to delete
    this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setOutlineThickness(1);
    this->hitBox.setSize(bounds.getSize());
    this->hitBox.setPosition(bounds.getPosition());
    this->hitBox.setFillColor(sf::Color::Transparent);

    this->nextPositionHitBox.setOutlineColor(sf::Color::Blue);
    this->nextPositionHitBox.setOutlineThickness(1);
    this->nextPositionHitBox.setSize(bounds.getSize());
    this->nextPositionHitBox.setPosition(bounds.getPosition());
    this->nextPositionHitBox.setFillColor(sf::Color::Transparent);
}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Goblin::isCollidingWith(Collidable &other) const -> bool {
    return nextPositionBounds.intersects(other.getGlobalBounds());
}


auto Goblin::onCollisionWith(Collidable &other) -> void {
    isColliding = true;
    collidables.push_back(&other);

    if (typeid(other) == typeid(Attack)) {
        if (other.getGlobalBounds() != previousBeingAttacked.getGlobalBounds()) {
            fmt::println("GOWNO"); //TO DELETE
            health -= mathRandomInCpp(10, 20);
            fmt::println("{}", health); //TO DELETE
            fmt::println("{}", isAlive); //TO DELETE
            previousBeingAttacked.setBounds(other.getGlobalBounds());
        }
    }

    if (typeid(other) == typeid(Knight)) {
        attack();
    }

}


auto Goblin::updateState() -> void {
    //updateEvents();
    updateMovement();
    updateIsAlive();
    updateAttack();
    updateTexture();

    if(isColliding) {
        updateCollision();
    }

    //TODO to delete
    hitBox.setPosition(bounds.getPosition());
    nextPositionHitBox.setPosition(nextPositionBounds.getPosition());
}


auto Goblin::render(sf::RenderTarget *window) -> void {
    window->draw(this->goblin);

    //TODO to delete
    window->draw(this->hitBox);
    window->draw(this->nextPositionHitBox);
}


auto Goblin::setPosition(sf::Vector2f position) -> void {
    this->position = position;
    goblin.setPosition(position);
}

auto Goblin::getCurrentAttack() -> Attack& {
    return currentAttack;
}

auto Goblin::setChasingPosition(sf::Vector2f chasingPosition) -> void {
    this->chasingPosition = chasingPosition;
}






