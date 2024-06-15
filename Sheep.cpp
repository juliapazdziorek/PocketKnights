#include "Sheep.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Sheep::updateBouncing() -> void {

    // if it's time start bounding
    if (!isBouncing && timeToBounceClock.getElapsedTime() >= sf::seconds(timeToBounce)) {
        isBouncing = true;
        sheepState = SheepState::BOUNCING;
        bouncingAnimationClock.restart();
    }

    // stop bouncing animation
    if (isBouncing && bouncingAnimationClock.getElapsedTime() >= sf::seconds(0.6f)) {
        isBouncing = false;
        sheepState = SheepState::STANDING;
        timeToBounce = (float)mathRandomInCpp(1,3);
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

    // animation variables
    isBouncing = false;
    timeToBounce = (float)(mathRandomInCpp(1, 3));
    animations.push_back(Assets::getAnimationSheepStanding()); // 0
    animations.push_back(Assets::getAnimationSheepBouncing()); // 1

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


// getters

auto Sheep::getPosition() -> sf::Vector2f {
    return position;
}


// setters

auto Sheep::setPosition(sf::Vector2f newPosition) -> void {

    // set new position
    position = newPosition;
    sheep.setPosition(position);
}
