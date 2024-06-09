#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

//public Entity
class Collidable : Entity {

public:

    // ----- public methods --------------------------------------------------------------------------------------------

    virtual auto getGlobalBounds() const -> sf::FloatRect = 0;
    virtual auto isCollidingWith(Collidable& other) -> bool;
    virtual auto onCollisionWith(Collidable& other) -> void;

};