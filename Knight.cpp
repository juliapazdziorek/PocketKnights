#include "Knight.h"

//private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Knight::updateEvents() -> void {

    // if not in other animation
    if(!attacking) {

        // moving left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            this->knightState = KnightState::KNIGHT_RUNNING_LEFT;
            this->knightFacing = KnightFacing::LEFT;
            this->knight.move(-this->movingSpeed, 0);
        }

        // moving right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            this->knightState = KnightState::KNIGHT_RUNNING_RIGHT;
            this->knightFacing = KnightFacing::RIGHT;
            this->knight.move(this->movingSpeed, 0);
        };

        // moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            this->knightFacing = KnightFacing::UP;
            this->knight.move(0, -this->movingSpeed);

            // some animation while moving up
            if (this->knightState == KnightState::KNIGHT_STANDING) {
                this->knightState = KnightState::KNIGHT_RUNNING_LEFT;
            }
        }

        // moving down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            this->knightFacing = KnightFacing::DOWN;
            this->knight.move(0, this->movingSpeed);

            // some animation while moving down
            if (this->knightState == KnightState::KNIGHT_STANDING) {
                this->knightState = KnightState::KNIGHT_RUNNING_RIGHT;
            }
        }

        // attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->knightState = KnightState::KNIGHT_ATTACKING;
            this->attacking = true;
            this->attackClock.restart();
            this->attackPosition = sf::Vector2f(this->position);
            //attack();

        }

        // standing
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->knightState = KnightState::KNIGHT_STANDING;
        }

    }

}


auto Knight::updateAttack() -> void {
    if(this->attacking) {

        // not moving while attack
        while (attackClock.getElapsedTime() <= sf::seconds(0.1f)) {
            this->knight.setPosition(attackPosition);
        }

        // move on after attacking
        if (attackClock.getElapsedTime() >= sf::seconds(0.6f)) {
            this->attacking = false;
        }

    }
}


auto Knight::updateTexture() -> void {

    switch (this->knightState) {
        case KnightState::KNIGHT_STANDING: {
            Assets::getAnimationKnightStanding().updateFrame(animationClock);
            Assets::getAnimationKnightStanding().applyTexture(knight);
            break;
        }

        case KnightState::KNIGHT_RUNNING_RIGHT: {
            Assets::getAnimationKnightRunningRight().updateFrame(animationClock);
            Assets::getAnimationKnightRunningRight().applyTexture(knight);
            break;
        }

        case KnightState::KNIGHT_RUNNING_LEFT: {
            Assets::getAnimationKnightRunningLeft().updateFrame(animationClock);
            Assets::getAnimationKnightRunningLeft().applyTexture(knight);
            break;
        }


        case KnightState::KNIGHT_ATTACKING: {
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

auto Knight::attack() -> void {

}


//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Knight::Knight() {

    this->knightState = KnightState::KNIGHT_STANDING;
    this->knightFacing = KnightFacing::DOWN;
    this->position = sf::Vector2f(350, 250);
    this->scale = sf::Vector2f(0.5f, 0.5f);
    this->movingSpeed = 3;

    this->attacking = false;
    this->attackPosition = position;

    this->knight.setScale(this->scale);
    this->knight.setPosition(this->position);

    this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setOutlineThickness(5);
    this->hitBox.setSize(bounds.getSize());
    this->hitBox.setPosition(bounds.getPosition());
    this->hitBox.setFillColor(sf::Color::Transparent);
    //this->hitBox.setScale(scale);

}

Knight::~Knight() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto Knight::updateState() -> void {
    this->position = knight.getPosition();
    updateEvents();
    updateAttack();
    updateTexture();

    this->bounds = knight.getGlobalBounds();
    this->hitBox.setSize(bounds.getSize());
    this->hitBox.setPosition(bounds.getPosition());
}

auto Knight::render(sf::RenderTarget *window) -> void {
    window->draw(this->knight);
    window->draw(this->hitBox);
}


