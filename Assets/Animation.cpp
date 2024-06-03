#include "Animation.h"

//private:

// ----- private methods -----------------------------------------------------------------------------------------------

auto Animation::computeFrames() -> void {
    auto recWidth = this->width / this->numberOfFramesInTexture;
    auto recHeight = this->height / this->numberOfRowsInTexture;

    for (int i = 0; i < this->framesOfAnimation; ++i) {
        frames[i] = sf::IntRect(i * recWidth, (rowOfAnimation - 1) * recHeight, recWidth, recHeight);
    }
}

auto Animation::countCurrentTextureIndex() -> void {
    if (this->currentTextureIndex < this->framesOfAnimation - 1) {
        currentTextureIndex++;
    } else {
        currentTextureIndex = 0;
    }
}



//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Animation::Animation(sf::Texture& texture, int const& width, int const& height, int const& numberOfFramesInTexture, int const& numberOfRowsInTexture, int const& rowOfAnimation, int const& framesOfAnimation)
    : texture(texture), currentTextureIndex(0), width(width), height(height), numberOfFramesInTexture(numberOfFramesInTexture), numberOfRowsInTexture(numberOfRowsInTexture), rowOfAnimation(rowOfAnimation), framesOfAnimation(framesOfAnimation) {
    this->frames = std::vector<sf::IntRect>(this->framesOfAnimation);
    computeFrames();
}

Animation::~Animation() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto Animation::applyTexture(sf::Sprite& sprite) -> void {
    sprite.setTexture(this->texture);
    sprite.setTextureRect(frames[currentTextureIndex]);
}

auto Animation::updateFrame(sf::Clock& clock) -> void {
    while (clock.getElapsedTime() >= sf::seconds(0.1f)) {
        countCurrentTextureIndex();
        clock.restart();
    }
}