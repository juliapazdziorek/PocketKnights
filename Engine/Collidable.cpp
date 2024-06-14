# include "Collidable.h"

// public:

// ----- public methods ------------------------------------------------------------------------------------------------

auto Collidable::isCollidingWith(Collidable &other) -> bool {
    return getGlobalBounds().intersects(other.getGlobalBounds());
}

auto Collidable::onCollisionWith(Collidable &other) -> void {} // nico kurwa :(

