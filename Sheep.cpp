#include "Sheep.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Sheep::updateBouncing() -> void {
    if (!isBouncing && timeToBounceClock.getElapsedTime() >= sf::seconds(timeToBounce)) {
        sheepState = SheepState::BOUNCING;
        isBouncing = true;
        bouncingAnimationClock.restart();
    }

    if (isBouncing && bouncingAnimationClock.getElapsedTime() >= sf::seconds(0.6f)) {
        sheepState = SheepState::STANDING;
        isBouncing = false;
        timeToBounce = (float)mathRandomInCpp(2,5);
        timeToBounceClock.restart();
    }

}


auto Sheep::updateTexture() -> void {
    // apply animations for standing and bouncing
    switch (sheepState) {
        case SheepState::STANDING: {
            animations[0].updateFrame(animationClock);
            animations[0].applyTexture(sheep);
            break;
        }

        case SheepState::BOUNCING: {
            animations[1].updateFrame(animationClock);
            animations[1].applyTexture(sheep);

            break;
        }
    }
}


// ----- private methods -----------------------------------------------------------------------------------------------

// overrides

auto Sheep::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Sheep::Sheep() {

    // sheep state
    isAlive = true;
    sheepState = SheepState::STANDING;

    // sprite variables
    position = sf::Vector2f(100, 100);
    scale = sf::Vector2f(0.5f, 0.5f);
    bounds = sf::FloatRect(sf::Vector2f(position.x + 43, position.y + 54), sf::Vector2f(10, 10));
    sheep.setPosition(position);
    sheep.setScale(scale);

    // animations
    animations.push_back(Assets::getAnimationSheepStanding()); // 0
    animations.push_back(Assets::getAnimationSheepBouncing()); // 1

    countBounceTime = false;
    isBouncing = false;
    timeToBounce = (float)(mathRandomInCpp(2, 5));
}


// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto Sheep::render(sf::RenderTarget *window) -> void {

    // render the sheep
    window->draw(sheep);
}


// overrides

auto Sheep::updateState() -> void {

    //update sheep's state
    updateBouncing();
    updateTexture();
}


auto Sheep::isCollidingWith(Collidable &other) -> bool {

    //return if sheep is colliding
    return bounds.intersects(other.getGlobalBounds());
}


auto Sheep::onCollisionWith(Collidable &other) -> void {

    // if colliding with new attack kill
    if (typeid(other) == typeid(Attack)) {
        isAlive = false;
    }
}
