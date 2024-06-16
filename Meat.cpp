#include "Meat.h"

// private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Meat::updateTexture() -> void {
    if (!spawned) {

        // if not finished spawning continue with spawning animation
        Assets::getAnimationMeatSpawning().updateFrame(animationClock);
        Assets::getAnimationMeatSpawning().applyTexture(meat);
    }

    if (!spawned && spawningClock.getElapsedTime() >= sf::seconds(0.7f)) {

        // if animation finished set static frame
        meat.setTexture(Assets::getTextureMeat());
        meat.setTextureRect(sf::IntRect(768, 0, 128, 128));
        spawned = true;
    }
}


// ----- private methods -----------------------------------------------------------------------------------------------

// overrides

auto Meat::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Meat::Meat(sf::Vector2f newPosition) {

    // meat state
    isAlive = true;

    // sprite variables
    position = newPosition;
    scale = sf::Vector2f(0.5f, 0.5f);
    bounds = sf::FloatRect(sf::Vector2f(newPosition.x + 28, newPosition.y + 28), sf::Vector2f(16, 16));
    //texture = Assets::getTextureMeat();
    meat.setPosition(position);
    meat.setScale(scale);

    // animation variables
    spawned = false;
    spawningClock.restart();

    //TODO to delete
    /*this->hitBox.setOutlineColor(sf::Color::Red);
    this->hitBox.setOutlineThickness(1);
    this->hitBox.setSize(bounds.getSize());
    this->hitBox.setPosition(bounds.getPosition());
    this->hitBox.setFillColor(sf::Color::Transparent);*/
}


// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto Meat::render(sf::RenderTarget *window) -> void {

    // render the meat
    window->draw(meat);

    //TODO to delete
    /*window->draw(this->hitBox);*/
}


// overrides

auto Meat::updateState() -> void {

    //update meat's state
    updateTexture();
}


auto Meat::isCollidingWith(Collidable &other) -> bool {

    //return if meat is colliding
    return bounds.intersects(other.getGlobalBounds());
}


auto Meat::onCollisionWith(Collidable &other) -> void {

    // if colliding with knight be eaten
    if (typeid(other) == typeid(Knight)) {
        isAlive = false;
    }
}
