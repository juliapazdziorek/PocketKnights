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

            updatePosition();
            updateBounds();
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

            updatePosition();
            updateBounds();
            nextPositionBounds.left = bounds.left + movingSpeed;
            nextPositionBounds.top = bounds.top;
        }

        // moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            goblinFacing = GoblinFacing::UP;
            velocity.x = 0;
            velocity.y = -movingSpeed;
            if (!isColliding) goblin.move(velocity);

            updatePosition();
            updateBounds();
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

            updatePosition();
            updateBounds();
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
            this->attackClock.restart();
            this->attackPosition = sf::Vector2f(this->position);
        }

        // standing
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            this->goblinState = GoblinState::STANDING;
        }
    }
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
        while (attackClock.getElapsedTime() <= sf::seconds(0.1f)) {
            this->goblin.setPosition(attackPosition);
        }

        // move on after attacking
        if (attackClock.getElapsedTime() >= sf::seconds(0.6f)) {
            this->attacking = false;
        }
    }
}


auto Goblin::updateTexture() -> void {

    // apply animations for: standing, running
    switch (this->goblinState) {
        case GoblinState::STANDING: {
            Assets::getAnimationGoblinStanding().updateFrame(animationClock);
            Assets::getAnimationGoblinStanding().applyTexture(goblin);
            break;
        }

        case GoblinState::RUNNING_RIGHT: {
            Assets::getAnimationGoblinRunningRight().updateFrame(animationClock);
            Assets::getAnimationGoblinRunningRight().applyTexture(goblin);
            break;
        }

        case GoblinState::RUNNING_LEFT: {
            Assets::getAnimationGoblinRunningLeft().updateFrame(animationClock);
            Assets::getAnimationGoblinRunningLeft().applyTexture(goblin);
            break;
        }

        // apply animations for: attacking
        case GoblinState::ATTACKING: {
            switch (goblinFacing) {
                case GoblinFacing::RIGHT: {
                    Assets::getAnimationGoblinAttackRight().updateFrame(animationClock);
                    Assets::getAnimationGoblinAttackRight().applyTexture(goblin);
                    break;
                }

                case GoblinFacing::LEFT: {
                    Assets::getAnimationGoblinAttackLeft().updateFrame(animationClock);
                    Assets::getAnimationGoblinAttackLeft().applyTexture(goblin);
                    break;
                }

                case GoblinFacing::UP: {
                    Assets::getAnimationGoblinAttackUp().updateFrame(animationClock);
                    Assets::getAnimationGoblinAttackUp().applyTexture(goblin);
                    break;
                }

                case GoblinFacing::DOWN: {
                    Assets::getAnimationGoblinAttackDown().updateFrame(animationClock);
                    Assets::getAnimationGoblinAttackDown().applyTexture(goblin);
                    break;
                }
            }
            break;
        }
    }
}


auto Goblin::updatePosition() -> void {
    position = goblin.getPosition();
}


auto Goblin::updateBounds() -> void {
    bounds.left = position.x + 43;
    bounds.top = position.y + 54;
}


// ----- private methods -----------------------------------------------------------------------------------------------

auto Goblin::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}


auto Goblin::attack() -> void {

}



//public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Goblin::Goblin() {

    // goblin state
    goblinState = GoblinState::STANDING;
    goblinFacing = GoblinFacing::DOWN;

    // sprite variables
    position = sf::Vector2f(250, 250); //TODO -> będą spawnowane w różnych miejscach, więc to jest do usunięcia w którymś momencie
    goblin.setPosition(position);
    scale = sf::Vector2f(0.5f, 0.5f);
    goblin.setScale(scale);
    bounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 54), sf::Vector2f(10, 10));

    // moving variables
    velocity = sf::Vector2f(0, 0);
    movingSpeed = 3;
    isColliding = false;
    nextPositionBounds = bounds;

    // attack variables
    this->attacking = false;
    this->attackPosition = position;

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

auto Goblin::isCollidingWith(Collidable &other) -> bool {
    return nextPositionBounds.intersects(other.getGlobalBounds());
}


auto Goblin::onCollisionWith(Collidable &other) -> void {
    isColliding = true;
    collidables.push_back(&other);
}


auto Goblin::updateState() -> void {
    updateEvents();
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


