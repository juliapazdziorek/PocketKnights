#include "Mushroom.h"

// private:

// ----- private methods -----------------------------------------------------------------------------------------------

// overrides

auto Mushroom::getGlobalBounds() const -> sf::FloatRect {
    return bounds;
}


// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Mushroom::Mushroom(sf::Vector2f newPosition) {

    // mushroom state
    isAlive = true;

    // sprite variables
    position = newPosition;
    scale = sf::Vector2f(0.5f, 0.5f);
    bounds = sf::FloatRect(sf::Vector2f(newPosition.x + 8, newPosition.y + 8), sf::Vector2f(16, 16));
    mushroom.setPosition(position);
    mushroom.setScale(scale);
    mushroom.setTexture(Assets::getTextureMushroom());
}

// ----- public methods ------------------------------------------------------------------------------------------------

// render

auto Mushroom::render(sf::RenderTarget *window) -> void {

    // render the meat
    window->draw(mushroom);
}

// overrides

auto Mushroom::updateState() -> void {}


auto Mushroom::isCollidingWith(Collidable &other) -> bool {

    //return if mushroom is colliding
    return bounds.intersects(other.getGlobalBounds());
}


auto Mushroom::onCollisionWith(Collidable &other) -> void {

    // if colliding with knight be eaten
    if (typeid(other) == typeid(Knight)) {
        isAlive = false;
    }
}


// getters

auto Mushroom::getPosition() -> sf::Vector2f {
    return position;
}
