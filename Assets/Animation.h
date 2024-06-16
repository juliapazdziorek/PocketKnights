#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {

private:

    // ----- variables -------------------------------------------------------------------------------------------------
    sf::Texture& texture;
    std::vector<sf::IntRect> frames;
    int currentTextureIndex;
    int width;
    int height;
    int numberOfFramesInTexture;
    int numberOfRowsInTexture;
    int rowOfAnimation;
    int framesOfAnimation;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto computeFrames() -> void;
    auto countCurrentTextureIndex() -> void;


public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    Animation(sf::Texture& texture, int const& width, int const& height, int const& numberOfFramesInTexture, int const& numberOfRowsInTexture, int const& rowOfAnimation, int const& framesOfAnimation);

    // ----- public methods --------------------------------------------------------------------------------------------
    auto applyTexture(sf::Sprite& sprite) -> void;
    auto updateFrame(sf::Clock& clock) -> void;

};
