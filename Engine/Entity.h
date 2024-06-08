#pragma once

#include "SFML/Graphics.hpp"

#include "../Game.h"

class Entity {

protected:

    // ---- protected properties ---------------------------------------------------------------------------------------
    bool isAlive;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Entity();
    ~Entity() = default;

    // ---- public methods ---------------------------------------------------------------------------------------------

    // update state
    virtual auto updateState(Game& game) -> void = 0;

    // lifespan
    auto checkIfAlive() const -> bool; //co on tu podkreśla da fq
    auto kill() -> void;

    //TODO some is as as

};
