#include "Goblin.h"

//private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Goblin::updateEvents() -> void {

    //if not in other animation
    if(!attacking) {

        //moving left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->goblinState = GoblinState::GOBLIN_RUNNING_LEFT;
            this->goblinFacing = GoblinFacing::LEFT;
            this->goblin.move(-this->movingSpeed, 0);
        }

            //moving right
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->goblinState = GoblinState::GOBLIN_RUNNING_RIGHT;
            this->goblinFacing = GoblinFacing::RIGHT;
            this->goblin.move(this->movingSpeed, 0);
        }

        //moving up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->goblinFacing = GoblinFacing::UP;
            this->goblin.move(0, -this->movingSpeed);

            //some animation while moving up
            if (this->goblinState == GoblinState::GOBLIN_STANDING) {
                this->goblinState = GoblinState::GOBLIN_RUNNING_LEFT;
            }
        }

            //moving down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->goblinFacing = GoblinFacing::DOWN;
            this->goblin.move(0, this->movingSpeed);

            //some animation while moving down
            if (this->goblinState == GoblinState::GOBLIN_STANDING) {
                this->goblinState = GoblinState::GOBLIN_RUNNING_RIGHT;
            }
        }

        //attack
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
            this->goblinState = GoblinState::GOBLIN_ATTACKING;
            this->attacking = true;
            this->attackClock.restart();
            this->attackPosition = sf::Vector2f(this->position);

            //attack();

        }

        //standing
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            this->goblinState = GoblinState::GOBLIN_STANDING;
        }

    }

}


auto Goblin::updateAttack() -> void {
    if(this->attacking) {

        //not moving while attack
        while (attackClock.getElapsedTime() <= sf::seconds(0.1f)) {
            this->goblin.setPosition(attackPosition);
        }

        //move on after attacking
        if (attackClock.getElapsedTime() >= sf::seconds(0.6f)) {
            this->attacking = false;
        }

    }
}


auto Goblin::updateTexture() -> void {

    switch (this->goblinState) {
        case GoblinState::GOBLIN_STANDING: {
            Assets::getGoblinStanding().updateFrame(animationClock);
            Assets::getGoblinStanding().applyTexture(goblin);
            break;
        }

        case GoblinState::GOBLIN_RUNNING_RIGHT: {
            Assets::getGoblinRunningRight().updateFrame(animationClock);
            Assets::getGoblinRunningRight().applyTexture(goblin);
            break;
        }

        case GoblinState::GOBLIN_RUNNING_LEFT: {
            Assets::getGoblinRunningLeft().updateFrame(animationClock);
            Assets::getGoblinRunningLeft().applyTexture(goblin);
            break;
        }


        case GoblinState::GOBLIN_ATTACKING: {
            switch (goblinFacing) {
                case GoblinFacing::RIGHT: {
                    Assets::getGoblinAttackRight().updateFrame(animationClock);
                    Assets::getGoblinAttackRight().applyTexture(goblin);
                    break;
                }

                case GoblinFacing::LEFT: {
                    Assets::getGoblinAttackLeft().updateFrame(animationClock);
                    Assets::getGoblinAttackLeft().applyTexture(goblin);
                    break;
                }

                case GoblinFacing::UP: {
                    Assets::getGoblinAttackUp().updateFrame(animationClock);
                    Assets::getGoblinAttackUp().applyTexture(goblin);
                    break;
                }

                case GoblinFacing::DOWN: {
                    Assets::getGoblinAttackDown().updateFrame(animationClock);
                    Assets::getGoblinAttackDown().applyTexture(goblin);
                    break;
                }
            }
            break;
        }
    }

}


// ----- private methods -----------------------------------------------------------------------------------------------

auto Goblin::attack() -> void {

}


//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Goblin::Goblin() {

    this->goblinState = GoblinState::GOBLIN_STANDING;
    this->goblinFacing = GoblinFacing::DOWN;
    this->scale = sf::Vector2f(0.5f, 0.5f);
    this->position = sf::Vector2f(250, 250);
    this->movingSpeed = 3;

    this->attacking = false;
    this->attackPosition = position;

    this->goblin.setScale(this->scale);
    this->goblin.setPosition(this->position);
}

Goblin::~Goblin() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto Goblin::updateState() -> void {
    this->position = goblin.getPosition();
    updateEvents();
    updateAttack();
    updateTexture();
}

auto Goblin::render(sf::RenderTarget* window) -> void {
    window->draw(this->goblin);
}
