# include "Collidable.h"

// public:

// ----- public methods ------------------------------------------------------------------------------------------------

auto Collidable::isCollidingWith(Collidable &other) const -> bool {
    return getGlobalBounds().intersects(other.getGlobalBounds());
}

auto Collidable::onCollisionWith(Collidable &other) -> void {} // nico kurwa :(

