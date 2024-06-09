#pragma once

#include <SFML/Graphics.hpp>

#include "../Engine/Collidable.h"

class MapBorder : public Collidable {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::RectangleShape border;

public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    MapBorder(float width, float height, float x, float y);
    ~MapBorder() = default;

    // ----- public methods --------------------------------------------------------------------------------------------
    auto getGlobalBounds() const -> sf::FloatRect override;
    auto updateState() -> void override;

    auto render(sf::RenderTarget* window) -> void;

};
