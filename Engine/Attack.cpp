#include "Attack.h"


Attack::Attack(sf::FloatRect attackBounds)
    : attackBounds(attackBounds) {}

auto Attack::getGlobalBounds() const -> sf::FloatRect {
    return attackBounds;
}


auto Attack::setBounds(sf::FloatRect bounds) -> void {
    attackBounds = bounds;
}


auto Attack::updateState() -> void {}


