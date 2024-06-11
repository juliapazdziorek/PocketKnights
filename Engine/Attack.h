#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.h"

class Attack : public Collidable {

private:

    // ----- variables -------------------------------------------------------------------------------------------------
    sf::FloatRect attackBounds;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Attack() = default;
    explicit Attack(sf::FloatRect attackBounds);

    // ----- public methods --------------------------------------------------------------------------------------------
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto setBounds(sf::FloatRect bounds) -> void;
    auto updateState() -> void override;

};

