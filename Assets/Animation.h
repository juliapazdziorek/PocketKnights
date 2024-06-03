#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Texture& texture;
    std::vector<sf::IntRect> frames;
    int currentTextureIndex;
    int width;
    int height;
    int numberOfFrames;
    int numberOfRows;
    int row;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto computeFrames() -> void;
    auto countCurrentTextureIndex() -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Animation(sf::Texture& texture, int const& width, int const& height, int const& numberOfFrames, int const& numberOfRows, int const& row);
    ~Animation();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto applyTexture(sf::Sprite& sprite) -> void;
    auto updateFrame(sf::Clock& clock) -> void;

};