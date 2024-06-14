#include "Knight.h"

//private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Knight::updateEvents() -> void { //zrobic wektor obiektow entiites ataku i potem przesylac go grze i te ataki beda sprawdzc czy koliduja z wrogami :))))

    // if not in other animation
    if(!attacking) {

        // moving left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            knightState = KnightState::RUNNING_LEFT;
            knightFacing = KnightFacing::LEFT;
            velocity.x = -movingSpeed;
            velocity.y = 0;
            if (!isColliding) knight.move(velocity);

            updatePosition();
            updateBounds();
            nextPositionBounds.left = bounds.left - movingSpeed;
            nextPositionBounds.top = bounds.top;
        }

        // moving right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            knightState = KnightState::RUNNING_RIGHT;
            knightFacing = KnightFacing::RIGHT;
            velocity.x = movingSpeed;
            velocity.y = 0;
            if (!isColliding) knight.move(velocity);

            updatePosition();
            updateBounds();
            nextPositionBounds.left = bounds.left + movingSpeed;
            nextPositionBounds.top = bounds.top;
        };

        // moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            knightFacing = KnightFacing::UP;
            velocity.x = 0;
            velocity.y = -movingSpeed;
            if (!isColliding) knight.move(velocity);

            updatePosition();
            updateBounds();
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top- movingSpeed;

            // some animation while moving up
            if (knightState == KnightState::STANDING) {
                knightState = KnightState::RUNNING_LEFT;
            }
        }

        // moving down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            knightFacing = KnightFacing::DOWN;
            velocity.x = 0;
            velocity.y = movingSpeed;
            if (!isColliding) knight.move(velocity);

            updatePosition();
            updateBounds();
            nextPositionBounds.left = bounds.left;
            nextPositionBounds.top = bounds.top + movingSpeed;

            // some animation while moving down
            if (knightState == KnightState::STANDING) {
                knightState = KnightState::RUNNING_RIGHT;
            }
        }

        // attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            knightState = KnightState::ATTACKING;
            attacking = true;
            attackAnimationClock.restart();
            attackPosition = position;
            attack();
        }

        // standing
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            knightState = KnightState::STANDING;
        }
    }
}


auto Knight::updateCollision() -> void {

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


auto Knight::updateAttack() -> void {
    if(attacking) {

        // not moving while attack
        while (attackAnimationClock.getElapsedTime() <= sf::seconds(0.1f)) {
            knight.setPosition(attackPosition);
        }

        // move on after attacking
        if (attackAnimationClock.getElapsedTime() >= sf::seconds(0.6f)) {
            attacking = false;
        }
    }
}


auto Knight::updateIsAlive() -> void {
    if (health < 0) {
        isAlive = false;
    }
}


auto Knight::updateTexture() -> void {

    // apply animations for: standing, running
    switch (knightState) {
        case KnightState::STANDING: {
            Assets::getAnimationKnightStanding().updateFrame(animationClock);
            Assets::getAnimationKnightStanding().applyTexture(knight);
            break;
        }

        case KnightState::RUNNING_RIGHT: {
            Assets::getAnimationKnightRunningRight().updateFrame(animationClock);
            Assets::getAnimationKnightRunningRight().applyTexture(knight);
            break;
        }

        case KnightState::RUNNING_LEFT: {
            Assets::getAnimationKnightRunningLeft().updateFrame(animationClock);
            Assets::getAnimationKnightRunningLeft().applyTexture(knight);
            break;
        }

        // apply animations for: attacking
        case KnightState::ATTACKING: {
            switch (knightFacing) {
                case KnightFacing::RIGHT: {
                    Assets::getAnimationKnightAttackRight().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackRight().applyTexture(knight);
                    attackBounds.left = bounds.left + 10;
                    attackBounds.top = bounds.top - 11;
                    break;
                }

                case KnightFacing::LEFT: {
                    Assets::getAnimationKnightAttackLeft().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackLeft().applyTexture(knight);
                    attackBounds.left = bounds.left - 32;
                    attackBounds.top = bounds.top - 11;
                    break;
                }

                case KnightFacing::UP: {
                    Assets::getAnimationKnightAttackUp().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackUp().applyTexture(knight);
                    attackBounds.left = bounds.left - 11;
                    attackBounds.top = bounds.top - 32;
                    break;
                }

                case KnightFacing::DOWN: {
                    Assets::getAnimationKnightAttackDown().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackDown().applyTexture(knight);
                    attackBounds.left = bounds.left - 11;
                    attackBounds.top = bounds.top + 10;
                    break;
                }
            }
            break;
        }
    }
}


auto Knight::updatePosition() -> void {

    // updates position variable
    position = knight.getPosition();
}


auto Knight::updateBounds() -> void {

    // updates bounds accordingly to position
    bounds.left = position.x + 43;
    bounds.top = position.y + 56;
}


// ----- private methods -----------------------------------------------------------------------------------------------

auto Knight::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}


auto Knight::attack() -> void {
    currentAttack.setBounds(attackBounds);
}



//public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Knight::Knight() {

    // knight state
    knightState = KnightState::STANDING;
    knightFacing = KnightFacing::DOWN;

    // sprite variables
    position = sf::Vector2f(350, 250);
    knight.setPosition(position);
    scale = sf::Vector2f(0.5f, 0.5f);
    knight.setScale(scale);
    bounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 56) ,sf::Vector2f(10, 10));

    isAlive = true;
    health = 100;

    // moving variables
    velocity = sf::Vector2f(0, 0);
    movingSpeed = 2;
    isColliding = false;
    nextPositionBounds = bounds;

    // attack variables
    attacking = false;
    attackPosition = position;
    attackBounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 56) ,sf::Vector2f(32, 32));
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
    this->nextPositionHitBox.setSize(nextPositionBounds.getSize());
    this->nextPositionHitBox.setPosition(nextPositionBounds.getPosition());
    this->nextPositionHitBox.setFillColor(sf::Color::Transparent);

    this->attackHitBox.setOutlineColor(sf::Color::Yellow);
    this->attackHitBox.setOutlineThickness(1);
    this->attackHitBox.setSize(attackBounds.getSize());
    this->attackHitBox.setPosition(bounds.getPosition());
    this->attackHitBox.setFillColor(sf::Color::Transparent);
}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Knight::isCollidingWith(Collidable &other) -> bool {
    return nextPositionBounds.intersects(other.getGlobalBounds());
}


auto Knight::onCollisionWith(Collidable &other) -> void {

    if (typeid(other) == typeid(Attack)) {
        if (other.getGlobalBounds() != previousBeingAttacked.getGlobalBounds()) {
            health -= mathRandomInCpp(1, 2);
            previousBeingAttacked.setBounds(other.getGlobalBounds());
        }
    }

    else {
        isColliding = true;
        collidables.push_back(&other);
    }
}


auto Knight::updateState() -> void {
    updateEvents();
    updateIsAlive();
    updateAttack();
    updateTexture();

    if(isColliding) {
        updateCollision();
    }

    //TODO to delete
    hitBox.setPosition(bounds.getPosition());
    nextPositionHitBox.setPosition(nextPositionBounds.getPosition());
    attackHitBox.setPosition(attackBounds.getPosition());


}


auto Knight::render(sf::RenderTarget *window) -> void {
    window->draw(this->knight);

    //TODO to delete
    window->draw(this->hitBox);
    window->draw(this->nextPositionHitBox);
    window->draw(this->attackHitBox);
}


auto Knight::getCurrentAttack() -> Attack& {
    return currentAttack;
}

auto Knight::getPosition() -> sf::Vector2f {
    return position;
}


