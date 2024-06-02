#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {

private:

    // ----- properties ------------------------------------------------------------------------------------------------
    sf::Texture& texture; //przechowuje całą teksturę //tam była referencja - może teraz sie cos wyjebac
    std::vector<sf::IntRect> frames; //przechowuje wymiary klatki
    int currentTextureIndex;
    int width; //przechowuje wysokość tekstury
    int height; //przechowuje wysokość tekstury
    int numberOfFrames; //przechowuje ilość klatek
    int numberOfRows; //przechowuje ilość wierszy (różnych animacji w pgn)
    int row; //wiersz w teksturze
    sf::Clock clock;

    // ----- private methods -------------------------------------------------------------------------------------------
    auto computeFrames() -> void; //oblicza klatki na podsatwie danych
    auto countCurrentTextureIndex() -> void;


public:

    // ----- constructor / destructor ----------------------------------------------------------------------------------
    Animation(sf::Texture& texture, int const& width, int const& height, int const& numberOfFrames, int const& numberOfRows, int const& row);
    ~Animation();

    // ----- public methods --------------------------------------------------------------------------------------------
    auto applyTexture(sf::Sprite& sprite) -> void; //ustawia animacje spritea na odpowiednią klatkę
    auto updateFrame() -> void; //zegar stuff ?? i update klatki na kolejną

};