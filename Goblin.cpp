#include "Goblin.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Goblin::updateIsAlive() -> void {

    //slay that goblin
    if (health <= 0) {
        isAlive = false;
    }
}


auto Goblin::updateAttack() -> void {
    if(isAttacking) {

        // not move while setAttackBounds
        while (attackAnimationClock.getElapsedTime() <= sf::seconds(0.1f)) {
            goblin.setPosition(attackPosition);
        }

        // move on after setAttackBounds animation
        if (attackAnimationClock.getElapsedTime() >= sf::seconds(0.6f)) {
            isAttacking = false;
        }
    }
}


auto Goblin::updateMovement() -> void {

    // if not ready to chase move to chasing position
    if (!readyToChase) {
        moveToChasingPosition();
        return;
    }

    // chase is not isAttacking
    if(!isAttacking) {
        chase();
    }
}


auto Goblin::updateCollision() -> void {

    // check if still colliding
    for (auto const& collidable : collidables) {
        if (!this->isCollidingWith(*collidable)) {
            collidables.erase(std::remove(collidables.begin(), collidables.end(), collidable), collidables.end());
        }
    }

    // if not colliding with anything let the goblin go :'(
    if (collidables.empty()) {
        isColliding = false;
    }
}


auto Goblin::updateTexture() -> void {

    // apply animations for standing and running
    switch (goblinState) {
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

        // apply animations for attacking
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


// update variables

auto Goblin::updatePositionVariable() -> void {

    // update position variable
    position = goblin.getPosition();
}


auto Goblin::updateBoundsVariable() -> void {

    // update bounds accordingly to position
    bounds.left = position.x + 43;
    bounds.top = position.y + 54;
}


auto Goblin::updateNextPositionBoundsVariable() -> void {

    // update next position bounds accordingly
    switch (goblinFacing) {

        case GoblinFacing::LEFT: {
            nextPositionBounds.left = bounds.left - movingSpeed;
            nextPositionBounds.top = bounds.top;
            break;
        }

        case GoblinFacing::RIGHT: {
            nextPositionBounds.left = bounds.left + movingSpeed;
            nextPositionBounds.top = bounds.top;
            break;
        }

        case GoblinFacing::UP: {
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top- movingSpeed;
            break;
        }
        case GoblinFacing::DOWN: {
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top + movingSpeed;
            break;
        }
    }
}


auto Goblin::updateAttackBoundsVariable() -> void {
    if (!isAttacking) {

        // update attack bounds accordingly
        switch (goblinFacing) {

            case GoblinFacing::LEFT: {
                attackBounds.left = nextPositionBounds.left - 32;
                attackBounds.top = nextPositionBounds.top - 11;
                break;
            }

            case GoblinFacing::RIGHT: {
                attackBounds.left = nextPositionBounds.left + 10;
                attackBounds.top = nextPositionBounds.top - 11;
                break;
            }

            case GoblinFacing::UP: {
                attackBounds.left = nextPositionBounds.left - 11;
                attackBounds.top = nextPositionBounds.top - 32;
                break;
            }
            case GoblinFacing::DOWN: {
                attackBounds.left = bounds.left - 11;
                attackBounds.top = bounds.top + 10;
                break;
            }
        }
    }
}


// ----- private methods -----------------------------------------------------------------------------------------------

// movement

auto Goblin::moveToChasingPosition() -> void {

    // starting from west island
    if (position.x <= 160) {
        moveRight();

        // check if ready to chase
        if (position.x >= 160) {
            readyToChase = true;
        }
    }

    // starting from north island
    if (position.y <= 176) {
        moveDown();

        // check if ready to chase
        if (position.y >= 176) {
            readyToChase = true;
        }
    }

    // starting from east island
    if (position.x >= 544) {
        moveLeft();

        // check if ready to chase
        if (position.x <= 544) {
            readyToChase = true;
        }
    }
}


auto Goblin::chase() -> void {

    // chase target accordingly to its position

    // run left
    if (position.x > chasedPosition.x) {
        moveLeft();
    }

    // run right
    if (position.x < chasedPosition.x) {
        moveRight();
    }

    // run up
    if (position.y > chasedPosition.y) {
        moveUp();
    }

    // run down
    if (position.y < chasedPosition.y) {
        moveDown();
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
    updateAttackBoundsVariable();
    updateNextPositionBoundsVariable();
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
    updateAttackBoundsVariable();
    updateNextPositionBoundsVariable();
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
    updateAttackBoundsVariable();
    updateNextPositionBoundsVariable();

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
    updateAttackBoundsVariable();
    updateNextPositionBoundsVariable();
}


// overrides

auto Goblin::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Goblin::Goblin() {

    // goblin state
    isAlive = true;
    health = 50;
    goblinState = GoblinState::STANDING;
    goblinFacing = GoblinFacing::DOWN;

    // sprite variables
    position = sf::Vector2f();
    scale = sf::Vector2f(0.5f, 0.5f);
    bounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 54), sf::Vector2f(10, 10));
    goblin.setPosition(position);
    goblin.setScale(scale);

    // animations
    animations.push_back(Assets::getAnimationGoblinStanding()); // 0
    animations.push_back(Assets::getAnimationGoblinRunningRight());
    animations.push_back(Assets::getAnimationGoblinRunningLeft());
    animations.push_back(Assets::getAnimationGoblinAttackRight());
    animations.push_back(Assets::getAnimationGoblinAttackLeft());
    animations.push_back(Assets::getAnimationGoblinAttackUp());
    animations.push_back(Assets::getAnimationGoblinAttackDown()); // 6

    // movement variables
    movingSpeed = 1.5;
    readyToChase = false;
    velocity = sf::Vector2f(0, 0);
    nextPositionBounds = bounds;
    chasedPosition = sf::Vector2f(416, 320); // center of a screen as default

    // attack variables
    isAttacking = false;
    attackPosition = position;
    attackBounds = sf::FloatRect (sf::Vector2f(position.x + 43, position.y + 56) ,sf::Vector2f(32, 32));
    currentAttack = Attack(attackBounds);

    // collision variable
    isColliding = false;

    //TODO to delete
    /*this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setOutlineThickness(1);
    this->hitBox.setSize(bounds.getSize());
    this->hitBox.setPosition(bounds.getPosition());
    this->hitBox.setFillColor(sf::Color::Transparent);

    this->nextPositionHitBox.setOutlineColor(sf::Color::Blue);
    this->nextPositionHitBox.setOutlineThickness(1);
    this->nextPositionHitBox.setSize(bounds.getSize());
    this->nextPositionHitBox.setPosition(bounds.getPosition());
    this->nextPositionHitBox.setFillColor(sf::Color::Transparent);

    this->attackHitBox.setOutlineColor(sf::Color::Yellow);
    this->attackHitBox.setOutlineThickness(1);
    this->attackHitBox.setSize(attackBounds.getSize());
    this->attackHitBox.setPosition(bounds.getPosition());
    this->attackHitBox.setFillColor(sf::Color::Transparent);*/
}


// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto Goblin::render(sf::RenderTarget *window) -> void {

    // render the goblin
    window->draw(goblin);

    //TODO to delete
    /*window->draw(this->hitBox);
    window->draw(this->nextPositionHitBox);
    window->draw(this->attackHitBox);*/
}


// overrides

auto Goblin::updateState() -> void {

    // update goblin's state
    updateIsAlive();
    updateAttack();
    updateMovement();

    if(isColliding) {
        updateCollision();
    }

    updateTexture();

    //TODO to delete
    /*hitBox.setPosition(bounds.getPosition());
    nextPositionHitBox.setPosition(nextPositionBounds.getPosition());
    attackHitBox.setPosition(attackBounds.getPosition());*/
}


auto Goblin::isCollidingWith(Collidable &other) -> bool {

    // check if goblin's attack is colliding with an enemy
    if (attackBounds.intersects(other.getGlobalBounds()) && typeid(other) == typeid(Knight) && attackBounds != currentAttack.getGlobalBounds()) {

        // update attack variables
        goblinState = GoblinState::ATTACKING;
        isAttacking = true;
        attackAnimationClock.restart();
        attackPosition = position;
        currentAttack.setBounds(attackBounds);
    }

    // return if goblin is colliding
    return nextPositionBounds.intersects(other.getGlobalBounds());
}


auto Goblin::onCollisionWith(Collidable &other) -> void {

    // if colliding with new attack subtract health
    if (typeid(other) == typeid(Attack)) {
        if (other.getGlobalBounds() != previousBeingAttacked.getGlobalBounds()) {
            health -= mathRandomInCpp(10, 20);
            previousBeingAttacked.setBounds(other.getGlobalBounds());
        }
    }

    // set collision variables
    else {
        isColliding = true;
        collidables.push_back(&other);
    }
}


// getters

auto Goblin::getCurrentAttack() -> Attack& {
    return currentAttack;
}


// setters

auto Goblin::setPosition(sf::Vector2f newPosition) -> void {

    // set new position
    position = newPosition;
    goblin.setPosition(position);
}


auto Goblin::setChasedPosition(sf::Vector2f newChasedPosition) -> void {
    chasedPosition = newChasedPosition;
}
