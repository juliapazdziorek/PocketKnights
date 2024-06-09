# include "Collidable.h"

// public:

// ----- public methods ------------------------------------------------------------------------------------------------

auto Collidable::isCollidingWith(Collidable &other) const -> bool {
    return getGlobalBounds().intersects(other.getGlobalBounds()); //TODO tu sie wypierdala
}

auto Collidable::onCollisionWith(Collidable &other) -> void {} // nico kurwa :(


