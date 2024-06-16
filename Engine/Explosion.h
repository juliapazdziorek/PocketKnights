#pragma once

#include "../Assets/Animation.h"
#include "../Assets/Assets.h"
#include "Attack.h"

class Explosion : public Attack {

private:

    // ----- variables -------------------------------------------------------------------------------------------------

    // explosion state
    sf::Clock timeOfExplosionClock;

    // sprite variables
    sf::Sprite explosion;
    sf::Vector2f position;

    // animation variables
    sf::Clock animationClock;

    // ----- event updating --------------------------------------------------------------------------------------------
    auto updateTexture() -> void;

    // ----- private methods -------------------------------------------------------------------------------------------

    // overrides
    auto getGlobalBounds() const -> sf::FloatRect override;

public:

    // ----- constructor -----------------------------------------------------------------------------------------------
    explicit Explosion(sf::Vector2f tntPosition);

    // ----- public methods --------------------------------------------------------------------------------------------

    // render
    auto render(sf::RenderTarget* window) -> void;

    // overrides
    auto updateState() -> void override;

    // getters
    auto getTimeOfExplosion() -> sf::Clock&;

};
