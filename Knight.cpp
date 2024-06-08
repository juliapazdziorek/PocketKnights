#include "Knight.h"

//private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Knight::updateEvents() -> void {

    // if not in other animation
    if(!attacking) {

        // moving left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            knightState = KnightState::RUNNING_LEFT;
            knightFacing = KnightFacing::LEFT;
            knight.move(-movingSpeed, 0);
        }

        // moving right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            knightState = KnightState::RUNNING_RIGHT;
            knightFacing = KnightFacing::RIGHT;
            knight.move(movingSpeed, 0);
        };

        // moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            knightFacing = KnightFacing::UP;
            knight.move(0, -movingSpeed);

            // some animation while moving up
            if (knightState == KnightState::STANDING) {
                knightState = KnightState::RUNNING_LEFT;
            }
        }

        // moving down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            knightFacing = KnightFacing::DOWN;
            knight.move(0, movingSpeed);

            // some animation while moving down
            if (knightState == KnightState::STANDING) {
                knightState = KnightState::RUNNING_RIGHT;
            }
        }

        // attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            knightState = KnightState::ATTACKING;
            attacking = true;
            attackClock.restart();
            attackPosition = sf::Vector2f(position);
            //attack();

        }

        // standing
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            knightState = KnightState::STANDING;
        }

    }

}


auto Knight::updateAttack() -> void {
    if(attacking) {

        // not moving while attack
        while (attackClock.getElapsedTime() <= sf::seconds(0.1f)) {
            knight.setPosition(attackPosition);
        }

        // move on after attacking
        if (attackClock.getElapsedTime() >= sf::seconds(0.6f)) {
            attacking = false;
        }

    }
}


auto Knight::updateTexture() -> void {

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


        case KnightState::ATTACKING: {
            switch (knightFacing) {
                case KnightFacing::RIGHT: {
                    Assets::getAnimationKnightAttackRight().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackRight().applyTexture(knight);
                    break;
                }

                case KnightFacing::LEFT: {
                    Assets::getAnimationKnightAttackLeft().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackLeft().applyTexture(knight);
                    break;
                }

                case KnightFacing::UP: {
                    Assets::getAnimationKnightAttackUp().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackUp().applyTexture(knight);
                    break;
                }

                case KnightFacing::DOWN: {
                    Assets::getAnimationKnightAttackDown().updateFrame(animationClock);
                    Assets::getAnimationKnightAttackDown().applyTexture(knight);
                    break;
                }
            }
            break;
        }
    }

}


// ----- private methods -----------------------------------------------------------------------------------------------

auto Knight::getGlobalBounds() const -> sf::FloatRect {
    auto tempBounds = sf::FloatRect(
            sf::Vector2f(position.x + 36, position.y + 56),
            sf::Vector2f(24, 10));

    return tempBounds;
}



auto Knight::attack() -> void {

}

//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Knight::Knight() {

    knightState = KnightState::STANDING;
    knightFacing = KnightFacing::DOWN;

    position = sf::Vector2f(350, 250);
    scale = sf::Vector2f(0.5f, 0.5f);
    bounds = getGlobalBounds();
    movingSpeed = 3;

    attacking = false;
    attackPosition = position;

    knight.setScale(this->scale);
    knight.setPosition(this->position);
    bounds = knight.getGlobalBounds();

    //TODO to delete
    this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setOutlineThickness(1);
    this->hitBox.setSize(bounds.getSize());
    this->hitBox.setPosition(bounds.getPosition());
    this->hitBox.setFillColor(sf::Color::Transparent);

}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Knight::updateState() -> void {
    this->position = knight.getPosition();
    updateEvents();
    updateAttack();
    updateTexture();

    bounds = getGlobalBounds();

    //TODO to delete
    hitBox.setSize(bounds.getSize());
    hitBox.setPosition(bounds.getPosition());
}

auto Knight::render(sf::RenderTarget *window) -> void {
    window->draw(this->knight);

    //TODO to delete
    window->draw(this->hitBox);
}


