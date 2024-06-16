#include "Knight.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Knight::updateEvents() -> void {

    // if not in attacking animation
    if(!isAttacking && isAlive) {

        // move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

            // knight state
            knightState = KnightState::RUNNING_LEFT;
            knightFacing = KnightFacing::LEFT;

            // move goblin left
            velocity.x = -movingSpeed;
            velocity.y = 0;
            if (!isColliding) knight.move(velocity);

            // update variables
            updatePositionVariable();
            updateBoundsVariable();
            updateAttackBoundsVariable();
            updateNextPositionBoundsVariable();
        }

        // move right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

            // knight state
            knightState = KnightState::RUNNING_RIGHT;
            knightFacing = KnightFacing::RIGHT;

            // move goblin right
            velocity.x = movingSpeed;
            velocity.y = 0;
            if (!isColliding) knight.move(velocity);

            // update variables
            updatePositionVariable();
            updateBoundsVariable();
            updateAttackBoundsVariable();
            updateNextPositionBoundsVariable();
        }

        // move up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

            // knight state
            knightFacing = KnightFacing::UP;

            // if first move is up give some animation
            if (knightState == KnightState::STANDING) {
                knightState = KnightState::RUNNING_LEFT;
            }

            // move goblin up
            velocity.x = 0;
            velocity.y = -movingSpeed;
            if (!isColliding) knight.move(velocity);

            // update variables
            updatePositionVariable();
            updateBoundsVariable();
            updateAttackBoundsVariable();
            updateNextPositionBoundsVariable();
        }

        // move down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

            // knight state
            knightFacing = KnightFacing::DOWN;

            // if first move is up give some animation
            if (knightState == KnightState::STANDING) {
                knightState = KnightState::RUNNING_RIGHT;
            }

            // move goblin down
            velocity.x = 0;
            velocity.y = movingSpeed;
            if (!isColliding) knight.move(velocity);

            // update variables
            updatePositionVariable();
            updateBoundsVariable();
            updateAttackBoundsVariable();
            updateNextPositionBoundsVariable();
        }

        // attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

            // update attack variables
            knightState = KnightState::ATTACKING;
            isAttacking = true;
            attackAnimationClock.restart();
            attackPosition = position;
            currentAttack.setBounds(attackBounds);

            // update attack lifespan
            currentAttack.isAlive = true;
            currentAttack.aliveClock.restart();
        }

        // stand if nothing pressed
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            knightState = KnightState::STANDING;
        }
    }
}


auto Knight::updateHealthBar() -> void {
    healthBar.setPosition(bounds.left - 16, bounds.top - 42);
    healthInBar.setPosition(healthBar.getPosition().x, healthBar.getPosition().y);
    healthInBar.setSize(sf::Vector2f((float)health, 5));
}


auto Knight::updateIsAlive() -> void {

    // knight dies :(
    if (health <= 0) {
        isAlive = false;
    }
}


auto Knight::updateAttack() -> void {
    if(isAttacking) {

        // update attack state
        currentAttack.updateState();

        // not moving while setAttackBounds
        while (attackAnimationClock.getElapsedTime() <= sf::seconds(0.1f)) {
            knight.setPosition(attackPosition);
        }

        // move on after isAttacking
        if (attackAnimationClock.getElapsedTime() >= sf::seconds(0.6f)) {
            isAttacking = false;
        }
    }
}


auto Knight::updateCollision() -> void {

    // check if still colliding
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


auto Knight::updateTexture() -> void {

    // apply animations for standing and running
    switch (knightState) {
        case KnightState::STANDING: {
            animations[0].updateFrame(animationClock);
            animations[0].applyTexture(knight);
            break;
        }

        case KnightState::RUNNING_RIGHT: {
            animations[1].updateFrame(animationClock);
            animations[1].applyTexture(knight);
            break;
        }

        case KnightState::RUNNING_LEFT: {
            animations[2].updateFrame(animationClock);
            animations[2].applyTexture(knight);
            break;
        }

        // apply animations for attacking
        case KnightState::ATTACKING: {
            switch (knightFacing) {
                case KnightFacing::RIGHT: {
                    animations[3].updateFrame(animationClock);
                    animations[3].applyTexture(knight);
                    break;
                }

                case KnightFacing::LEFT: {
                    animations[4].updateFrame(animationClock);
                    animations[4].applyTexture(knight);
                    break;
                }

                case KnightFacing::UP: {
                    animations[5].updateFrame(animationClock);
                    animations[5].applyTexture(knight);
                    break;
                }

                case KnightFacing::DOWN: {
                    animations[6].updateFrame(animationClock);
                    animations[6].applyTexture(knight);
                    break;
                }
            }
            break;
        }
    }
}


// update variables

auto Knight::updatePositionVariable() -> void {

    // updates position variable
    position = knight.getPosition();
}


auto Knight::updateBoundsVariable() -> void {

    // updates bounds accordingly to position
    bounds.left = position.x + 43;
    bounds.top = position.y + 56;
}


auto Knight::updateAttackBoundsVariable() -> void {

    // update attack bounds accordingly
    switch (knightFacing) {

        case KnightFacing::LEFT: {
            attackBounds.left = nextPositionBounds.left - 32;
            attackBounds.top = nextPositionBounds.top - 11;
            break;
        }

        case KnightFacing::RIGHT: {
            attackBounds.left = nextPositionBounds.left + 10;
            attackBounds.top = nextPositionBounds.top - 11;
            break;
        }

        case KnightFacing::UP: {
            attackBounds.left = nextPositionBounds.left - 11;
            attackBounds.top = nextPositionBounds.top - 32;
            break;
        }
        case KnightFacing::DOWN: {
            attackBounds.left = bounds.left - 11;
            attackBounds.top = bounds.top + 10;
            break;
        }
    }
}


auto Knight::updateNextPositionBoundsVariable() -> void {

    // update next position bounds accordingly
    switch (knightFacing) {

        case KnightFacing::LEFT: {
            nextPositionBounds.left = bounds.left - movingSpeed;
            nextPositionBounds.top = bounds.top;
            break;
        }

        case KnightFacing::RIGHT: {
            nextPositionBounds.left = bounds.left + movingSpeed;
            nextPositionBounds.top = bounds.top;
            break;
        }

        case KnightFacing::UP: {
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top- movingSpeed;
            break;
        }
        case KnightFacing::DOWN: {
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top + movingSpeed;
            break;
        }
    }
}


// ----- private methods -----------------------------------------------------------------------------------------------

// overrides

auto Knight::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Knight::Knight() {

    // knight state
    isAlive = true;
    health = 48;
    knightState = KnightState::STANDING;
    knightFacing = KnightFacing::DOWN;

    // sprite variables
    position = sf::Vector2f(350, 250);
    scale = sf::Vector2f(0.5f, 0.5f);
    bounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 56) ,sf::Vector2f(10, 10));
    knight.setPosition(position);
    knight.setScale(scale);

    // animations
    animations.push_back(Assets::getAnimationKnightStanding()); // 0
    animations.push_back(Assets::getAnimationKnightRunningRight());
    animations.push_back(Assets::getAnimationKnightRunningLeft());
    animations.push_back(Assets::getAnimationKnightAttackRight());
    animations.push_back(Assets::getAnimationKnightAttackLeft());
    animations.push_back(Assets::getAnimationKnightAttackUp());
    animations.push_back(Assets::getAnimationKnightAttackDown()); // 6

    // health bar variables
    healthBar.setSize(sf::Vector2f(48, 5));
    healthBar.setFillColor(sf::Color::White);
    healthBar.setOutlineColor(sf::Color::Black);
    healthBar.setOutlineThickness(2);
    healthInBar.setSize(sf::Vector2f(48, 5));
    healthInBar.setFillColor(sf::Color::Red);
    updateHealthBar();

    // movement variables
    velocity = sf::Vector2f(0, 0);
    movingSpeed = 2;
    isColliding = false;
    nextPositionBounds = bounds;

    // attack variables
    isAttacking = false;
    attackPosition = position;
    attackBounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 56) ,sf::Vector2f(32, 32));
    currentAttack = Attack(attackBounds);

    //TODO to delete
    /*this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setOutlineThickness(1);
    this->hitBox.setSize(bounds.getSize());
    this->hitBox.setPosition(bounds.getPosition());
    this->hitBox.setFillColor(sf::Color::Transparent);

    this->nextPositionHitBox.setOutlineColor(sf::Color::Blue);
    this->nextPositionHitBox.setOutlineThickness(1);
    this->nextPositionHitBox.setSize(nextPositionBounds.getSize());
    this->nextPositionHitBox.setPosition(nextPositionBounds.getPosition());
    this->nextPositionHitBox.setFillColor(sf::Color::Transparent);

    this->attackHitBox.setOutlineColor(sf::Color::Yellow);
    this->attackHitBox.setOutlineThickness(1);
    this->attackHitBox.setSize(attackBounds.getSize());
    this->attackHitBox.setPosition(bounds.getPosition());
    this->attackHitBox.setFillColor(sf::Color::Transparent);*/
}


// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto Knight::render(sf::RenderTarget *window) -> void {

    // render the knight
    window->draw(healthBar);
    window->draw(healthInBar);
    window->draw(knight);

    //TODO to delete
    /*window->draw(this->hitBox);
    window->draw(this->nextPositionHitBox);
    window->draw(this->attackHitBox);*/
}


// overrides

auto Knight::updateState() -> void {

    //fmt::println("{}", health);

    // update knight's state
    updateEvents();
    updateHealthBar();
    updateIsAlive();
    updateAttack();

    if(isColliding) {
        updateCollision();
    }
    updateTexture();

    //TODO to delete
    /*hitBox.setPosition(bounds.getPosition());
    nextPositionHitBox.setPosition(nextPositionBounds.getPosition());
    attackHitBox.setPosition(attackBounds.getPosition());*/
}


auto Knight::isCollidingWith(Collidable &other) -> bool {

    // return if knight is colliding
    return nextPositionBounds.intersects(other.getGlobalBounds());
}


auto Knight::onCollisionWith(Collidable &other) -> void {

    // if colliding with new attack subtract health
    if (typeid(other) == typeid(Attack)) {
        if (other.isAlive) {
            health -= mathRandomInCpp(1, 4);
        }
    }

    // if colliding with explosion subtract health
    else if (typeid(other) == typeid(Explosion)) {
        if (other.isAlive) {
            health -= mathRandomInCpp(4, 8);
        }
    }

    else if (typeid(other) == typeid(Meat)) {
        if (health <= 43) {
            health += 5;
        } else {
            health = 48;
        }
    }

        // set collision variables
    else {
        isColliding = true;
        collidables.push_back(&other);
    }
}


// getters

auto Knight::getCurrentAttack() -> Attack& {
    return currentAttack;
}


auto Knight::getPosition() -> sf::Vector2f {
    return position;
}
