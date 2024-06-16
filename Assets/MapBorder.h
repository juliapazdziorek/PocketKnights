#pragma once

#include <SFML/Graphics.hpp>

#include "../Engine/Collidable.h"

class MapBorder : public Collidable {

private:

    // ----- variables -------------------------------------------------------------------------------------------------
    sf::RectangleShape border;

public:

    // ----- constructor  ----------------------------------------------------------------------------------------------
    MapBorder(float width, float height, float x, float y);

    // ----- public methods --------------------------------------------------------------------------------------------

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto updateState() -> void override;

};
