#include "Tnt.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Tnt::updateMovement() -> void {

    // chase is not isAttacking
    if (!isExploding) {
        chase();
    }
}


auto Tnt::updateCollision() -> void {

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


auto Tnt::updateTexture() -> void {

    switch (tntColor) {

        // apply animations for different colors
        case TntColor::BLUE: {

            // apply animations for tnt
            switch (tntState) {
                case TntState::OUT: {
                    animationsBlue[0].updateFrame(animationClock);
                    animationsBlue[0].applyTexture(tnt);
                    break;
                }

                case TntState::RUNNING: {
                    animationsBlue[1].updateFrame(animationClock);
                    animationsBlue[1].applyTexture(tnt);
                    break;
                }

                case TntState::EXPLODING: {
                    animationsBlue[2].updateFrame(animationClock);
                    animationsBlue[2].applyTexture(tnt);
                    break;
                }
            }
            break;
        }

        case TntColor::RED: {

            // apply animations for tnt
            switch (tntState) {
                case TntState::OUT: {
                    animationsRed[0].updateFrame(animationClock);
                    animationsRed[0].applyTexture(tnt);
                    break;
                }

                case TntState::RUNNING: {
                    animationsRed[1].updateFrame(animationClock);
                    animationsRed[1].applyTexture(tnt);
                    break;
                }

                case TntState::EXPLODING: {
                    animationsRed[2].updateFrame(animationClock);
                    animationsRed[2].applyTexture(tnt);
                    break;
                }
            }
            break;
        }
    }
}


// update variables

auto Tnt::updatePositionVariable() -> void {

    // update position variable
    position = tnt.getPosition();
}


auto Tnt::updateBoundsVariable() -> void {

    // update bounds accordingly to position
    bounds.left = position.x + 43;
    bounds.top = position.y + 54;
}


auto Tnt::updateNextPositionBoundsVariable() -> void {

    // update next position bounds accordingly
    switch (tntFacing) {

        case TntFacing::LEFT: {
            nextPositionBounds.left = bounds.left - movingSpeed;
            nextPositionBounds.top = bounds.top;
            break;
        }

        case TntFacing::RIGHT: {
            nextPositionBounds.left = bounds.left + movingSpeed;
            nextPositionBounds.top = bounds.top;
            break;
        }

        case TntFacing::UP: {
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top- movingSpeed;
            break;
        }
        case TntFacing::DOWN: {
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top + movingSpeed;
            break;
        }
    }
}


// ----- private methods -----------------------------------------------------------------------------------------------

// movement

auto Tnt::chase() -> void {

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


auto Tnt::moveLeft() -> void {

    // goblin state
    tntState = TntState::RUNNING;
    tntFacing = TntFacing::LEFT;

    // move goblin left
    velocity.x = -movingSpeed;
    velocity.y = 0;
    if (!isColliding) tnt.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    updateNextPositionBoundsVariable();
}


auto Tnt::moveRight() -> void {

    // goblin state
    tntState = TntState::RUNNING;
    tntFacing = TntFacing::RIGHT;

    // move goblin right
    velocity.x = movingSpeed;
    velocity.y = 0;
    if (!isColliding) tnt.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    updateNextPositionBoundsVariable();
}


auto Tnt::moveUp() -> void {

    // goblin state
    tntState = TntState::RUNNING;
    tntFacing = TntFacing::UP;

    // move goblin up
    velocity.x = 0;
    velocity.y = -movingSpeed;
    if (!isColliding) tnt.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    updateNextPositionBoundsVariable();

}


auto Tnt::moveDown() -> void {

    // goblin state
    tntState = TntState::RUNNING;
    tntFacing = TntFacing::DOWN;

    // move goblin down
    velocity.x = 0;
    velocity.y = movingSpeed;
    if (!isColliding) tnt.move(velocity);

    // update variables
    updatePositionVariable();
    updateBoundsVariable();
    updateNextPositionBoundsVariable();
}


// overrides

auto Tnt::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Tnt::Tnt(TntColor color)
    : tntColor(color) {

    // tnt state
    isAlive = true;
    tntState = TntState::OUT;
    tntFacing = TntFacing::DOWN;

    // sprite variables
    position = sf::Vector2f();
    scale = sf::Vector2f(0.5f, 0.5f);
    bounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 54), sf::Vector2f(10, 10));
    tnt.setPosition(position);
    tnt.setScale(scale);

    // animation variables
    animationsBlue.push_back(Assets::getAnimationTntBlueOut()); //0
    animationsBlue.push_back(Assets::getAnimationTntBlueRunning());
    animationsBlue.push_back(Assets::getAnimationTntBlueFire()); //2
    animationsBlue.push_back(Assets::getAnimationTntRedOut()); //0
    animationsBlue.push_back(Assets::getAnimationTntRedRunning());
    animationsBlue.push_back(Assets::getAnimationTntRedFire()); //2

    // movement variables
    movingSpeed = 1;
    velocity = sf::Vector2f(0, 0);
    nextPositionBounds = bounds;
    chasedPosition = sf::Vector2f(416, 320); // center of a screen as default

    // explosion variables
    isExploding = false;

    // collision variables
    isColliding = false;

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

    this->explosionHitBox.setOutlineColor(sf::Color::Yellow);
    this->explosionHitBox.setOutlineThickness(1);
    this->explosionHitBox.setSize(explosionBounds.getSize());
    this->explosionHitBox.setPosition(bounds.getPosition());
    this->explosionHitBox.setFillColor(sf::Color::Transparent);
}


// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto Tnt::render(sf::RenderTarget *window) -> void {

    // render the goblin
    window->draw(tnt);

    //TODO to delete
    window->draw(this->hitBox);
    window->draw(this->nextPositionHitBox);
}


// overrides

auto Tnt::updateState() -> void {

    // update goblin's state
    updateMovement();

    if(isColliding) {
        updateCollision();
    }

    updateTexture();

    //TODO to delete
    hitBox.setPosition(bounds.getPosition());
    nextPositionHitBox.setPosition(nextPositionBounds.getPosition());
}


auto Tnt::isCollidingWith(Collidable &other) -> bool {

    /*// check if goblin's attack is colliding with an enemy
    if (attackBounds.intersects(other.getGlobalBounds()) && typeid(other) == typeid(Knight) && attackBounds != currentAttack.getGlobalBounds()) {

        // update attack variables
        goblinState = GoblinState::ATTACKING;
        isAttacking = true;
        attackAnimationClock.restart();
        attackPosition = position;
        currentAttack.setBounds(attackBounds); //to jest od goblina
    }*/

    // return if tnt is colliding
    return nextPositionBounds.intersects(other.getGlobalBounds());
}

auto Tnt::onCollisionWith(Collidable &other) -> void {

    // if colliding with new attack subtract health
    /*if (typeid(other) == typeid(Attack)) {
        if (other.getGlobalBounds() != previousBeingAttacked.getGlobalBounds()) {
            health -= mathRandomInCpp(10, 20);
            previousBeingAttacked.setBounds(other.getGlobalBounds());
        }
    }

        // set collision variables
    else {*/
        isColliding = true;
        collidables.push_back(&other);
    //}
}


// getters

/*auto Tnt::getCurrentExplosion() -> Attack & {
    return ;
}*/


// setters

auto Tnt::setPosition(sf::Vector2f newPosition) -> void {

    // set new position
    position = newPosition;
    tnt.setPosition(position);
}


auto Tnt::setChasedPosition(sf::Vector2f newChasedPosition) -> void {
    chasedPosition = newChasedPosition;
}



