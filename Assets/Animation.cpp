#include "Animation.h"

// private:

// ----- private methods -----------------------------------------------------------------------------------------------

auto Animation::computeFrames() -> void {

    // compute frames accordingly
    auto recWidth = this->width / this->numberOfFramesInTexture;
    auto recHeight = this->height / this->numberOfRowsInTexture;

    for (int i = 0; i < this->framesOfAnimation; ++i) {
        frames[i] = sf::IntRect(i * recWidth, (rowOfAnimation - 1) * recHeight, recWidth, recHeight);
    }
}

auto Animation::countCurrentTextureIndex() -> void {

    // set current frame
    if (this->currentTextureIndex < this->framesOfAnimation - 1) {
        currentTextureIndex++;
    } else {
        currentTextureIndex = 0;
    }
}



// public:

// ----- constructor ---------------------------------------------------------------------------------------------------

Animation::Animation(sf::Texture& texture, int const& width, int const& height, int const& numberOfFramesInTexture, int const& numberOfRowsInTexture, int const& rowOfAnimation, int const& framesOfAnimation)
    : texture(texture), currentTextureIndex(0), width(width), height(height), numberOfFramesInTexture(numberOfFramesInTexture), numberOfRowsInTexture(numberOfRowsInTexture), rowOfAnimation(rowOfAnimation), framesOfAnimation(framesOfAnimation) {
    this->frames = std::vector<sf::IntRect>(this->framesOfAnimation);
    computeFrames();
}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Animation::applyTexture(sf::Sprite& sprite) -> void {

    // change texture and frame accordingly
    sprite.setTexture(texture);
    sprite.setTextureRect(frames[currentTextureIndex]);
}

auto Animation::updateFrame(sf::Clock& clock) -> void {

    // change frame every 0,1 sec
    if (clock.getElapsedTime() >= sf::seconds(0.1f)) {
        countCurrentTextureIndex();
        clock.restart();
    }
}
