#include "Knight.h"

//private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Knight::updateEvents() -> void {

    if(!attacking) {

        //moving: left, right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            this->knight.move(-this->movingSpeed, 0);
            this->knightState = KnightState::KNIGHT_RUNNING_LEFT;
            this->knightFacing = KnightFacing::LEFT;
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            this->knight.move(this->movingSpeed, 0);
            this->knightState = KnightState::KNIGHT_RUNNING_RIGHT;
            this->knightFacing = KnightFacing::RIGHT;
        };

        //moving up, down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            this->knight.move(0, -this->movingSpeed);
            this->knightFacing = KnightFacing::UP;

            if (this->knightState == KnightState::KNIGHT_STANDING) {
                this->knightState = KnightState::KNIGHT_RUNNING_LEFT;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            this->knight.move(0, this->movingSpeed);
            this->knightFacing = KnightFacing::DOWN;

            if (this->knightState == KnightState::KNIGHT_STANDING) {
                this->knightState = KnightState::KNIGHT_RUNNING_RIGHT;
            }
        }

        //attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->knightState = KnightState::KNIGHT_ATTACKING;
            this->attacking = true;
            this->attackClock.restart();
            this->attackPosition = sf::Vector2f(this->position);

            //attack();

        }

        //standing
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            this->knightState = KnightState::KNIGHT_STANDING;
        }

    }

}


auto Knight::updateAttack() -> void {
    if(this->attacking) {

        //not moving while attack
        while (attackClock.getElapsedTime() <= sf::seconds(0.1f)) {
            this->knight.setPosition(attackPosition);
        }

        //move on after attacking
        if (attackClock.getElapsedTime() >= sf::seconds(0.6f)) {
            this->attacking = false;
        }

    }
}


auto Knight::updateTexture() -> void {

    switch (this->knightState) {
        case KnightState::KNIGHT_STANDING: {
            Assets::getKnightStanding().updateFrame(animationClock);
            Assets::getKnightStanding().applyTexture(knight);
            break;
        }

        case KnightState::KNIGHT_RUNNING_RIGHT: {
            Assets::getKnightRunningRight().updateFrame(animationClock);
            Assets::getKnightRunningRight().applyTexture(knight);
            break;
        }

        case KnightState::KNIGHT_RUNNING_LEFT: {
            Assets::getKnightRunningLeft().updateFrame(animationClock);
            Assets::getKnightRunningLeft().applyTexture(knight);
            break;
        }


        case KnightState::KNIGHT_ATTACKING: {
            switch (knightFacing) {
                case KnightFacing::RIGHT: {
                    Assets::getKnightAttackRight().updateFrame(animationClock);
                    Assets::getKnightAttackRight().applyTexture(knight);
                    break;
                }

                case KnightFacing::LEFT: {
                    Assets::getKnightAttackLeft().updateFrame(animationClock);
                    Assets::getKnightAttackLeft().applyTexture(knight);
                    break;
                }

                case KnightFacing::UP: {
                    Assets::getKnightAttackUp().updateFrame(animationClock);
                    Assets::getKnightAttackUp().applyTexture(knight);
                    break;
                }

                case KnightFacing::DOWN: {
                    Assets::getKnightAttackDown().updateFrame(animationClock);
                    Assets::getKnightAttackDown().applyTexture(knight);
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
    this->scale = sf::Vector2f(0.5f, 0.5f);
    this->position = sf::Vector2f(350, 250);
    this->movingSpeed = 3;

    this->attacking = false;
    this->attackPosition = position;

    this->knight.setScale(this->scale);
    this->knight.setPosition(this->position);
}

Knight::~Knight() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto Knight::updateState() -> void {
    this->position = knight.getPosition();
    updateEvents();
    updateAttack();
    updateTexture();
}

auto Knight::render(sf::RenderTarget* window) -> void {
    window->draw(this->knight);
}
