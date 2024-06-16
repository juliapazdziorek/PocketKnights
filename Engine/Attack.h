#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.h"

class Attack : public Collidable {

protected:

    // ----- variables -------------------------------------------------------------------------------------------------
    sf::FloatRect attackBounds;

public:

    // public variables ------------------------------------------------------------------------------------------------
    sf::Clock aliveClock;

    // ----- constructor -----------------------------------------------------------------------------------------------
    Attack() = default;
    explicit Attack(sf::FloatRect attackBounds);

    // ----- public methods --------------------------------------------------------------------------------------------

    auto setBounds(sf::FloatRect bounds) -> void;

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto updateState() -> void override;

};
