#include "MapBorder.h"

// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

MapBorder::MapBorder(float width, float height, float x, float y) {
    border = sf::RectangleShape();
    border.setSize(sf::Vector2f(width, height));
    border.setPosition(sf::Vector2f(x, y));
    border.setFillColor(sf::Color::Red); ///TODO TO DELETE
}

// ----- public methods ------------------------------------------------------------------------------------------------

auto MapBorder::getGlobalBounds() const -> sf::FloatRect {
    return border.getGlobalBounds();
}

auto MapBorder::updateState() -> void {}

auto MapBorder::render(sf::RenderTarget* window) -> void {
    window->draw(border);
}
