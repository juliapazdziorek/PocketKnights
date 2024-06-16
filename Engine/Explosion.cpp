#include "Explosion.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Explosion::updateTexture() -> void {

    // update animation
    Assets::getAnimationExplosion().updateFrame(animationClock);
    Assets::getAnimationExplosion().applyTexture(explosion);
}


// ----- private methods -----------------------------------------------------------------------------------------------

// overrides

auto Explosion::getGlobalBounds() const -> sf::FloatRect {
    return attackBounds;
}

// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Explosion::Explosion(sf::Vector2f tntPosition) {

    // sprite variables
    position.x = tntPosition.x - 64;
    position.y = tntPosition.y - 64;
    attackBounds = sf::FloatRect(sf::Vector2f(tntPosition.x, tntPosition.y), sf::Vector2f(64, 64));
    explosion.setPosition(position);
}


// ----- public methods --------------------------------------------------------------------------------------------

// render

auto Explosion::render(sf::RenderTarget *window) -> void {

    // render the explosion
    window->draw(explosion);
}


// overrides

auto Explosion::updateState() -> void {

    // update state
    updateTexture();

    // turn off attack after time
    if (aliveClock.getElapsedTime() >= sf::seconds(0.1f)) {
        isAlive = false;
    }
}


// getters

auto Explosion::getTimeOfExplosion() -> sf::Clock & {
    return timeOfExplosionClock;
}
