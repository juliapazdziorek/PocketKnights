#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.h"

class Attack : public Collidable {

private:

    // ----- variables -------------------------------------------------------------------------------------------------
    sf::FloatRect attackBounds;

public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    Attack() = default;
    explicit Attack(sf::FloatRect attackBounds);

    // ----- public methods --------------------------------------------------------------------------------------------

    auto setBounds(sf::FloatRect bounds) -> void;

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto updateState() -> void override;

};
