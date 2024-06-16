#pragma once

#include "SFML/Graphics.hpp"

class Entity {

public:

    // ----- variables -------------------------------------------------------------------------------------------------
    bool isAlive;

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Entity();
    virtual ~Entity() = default;

    // ---- public methods ---------------------------------------------------------------------------------------------

    // update state
    virtual auto updateState() -> void = 0;

};
