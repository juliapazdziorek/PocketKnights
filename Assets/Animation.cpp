#include "Animation.h"

//private:

// ----- private methods -----------------------------------------------------------------------------------------------

auto Animation::computeFrames() -> void {
    auto recWidth = this->width / this->numberOfFrames;
    auto recHeight = this->height / this->numberOfRows;

    for (int i = 0; i < frames.size(); ++i) {
        frames[i] = sf::IntRect(i * recWidth, (row - 1) * recHeight, recWidth, recHeight);
    }
}

auto Animation::countCurrentTextureIndex() -> void {
    if (this->currentTextureIndex < this->numberOfFrames - 1) {
        currentTextureIndex++;
    } else {
        currentTextureIndex = 0;
    }
}



//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Animation::Animation(sf::Texture& texture, int const& width, int const& height, int const& numberOfFrames, int const& numberOfRows, int const& row)
    : texture(texture), currentTextureIndex(0), width(width), height(height), numberOfFrames(numberOfFrames), numberOfRows(numberOfRows), row(row) {
    this->frames = std::vector<sf::IntRect>(this->numberOfFrames);
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