#include "Attack.h"

// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Attack::Attack(sf::FloatRect attackBounds)
    : attackBounds(attackBounds) {
}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Attack::setBounds(sf::FloatRect bounds) -> void {
    attackBounds = bounds;
}


// overrides

auto Attack::getGlobalBounds() const -> sf::FloatRect {
    return attackBounds;
}


auto Attack::updateState() -> void {

    // turn off attack after time
    if (aliveClock.getElapsedTime() >= sf::seconds(0.1f)) {
        isAlive = false;
    }
}
