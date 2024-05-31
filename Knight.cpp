#include <fmt/ranges.h>

#include "Knight.h"

//private:

// ----- event updating -------------------------------------------------------------------------------------------------

auto Knight::updateEvents() -> void {

    //moving: left, right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->knight.move(-this->movingSpeed, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->knight.move(this->movingSpeed, 0);

    //moving up, down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->knight.move(0, -this->movingSpeed);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->knight.move(0, this->movingSpeed);

}


//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Knight::Knight() {
    if (!Knight::texture.loadFromFile("TinySwords/Fractions/Knights/Troops/Warrior/Original/Warrior_Blue1.png")) {
        fmt::println("File can not load from file: TinySwords/Fractions/Knights/Troops/Warrior/Original/Warrior_Blue1.png");
    }
    Knight::texture.setSmooth(true);
    this->knight.setTexture(Knight::texture);
    this->knight.setScale(0.5f, 0.5f);
    this->movingSpeed = 5;
}

Knight::~Knight() = default;


// ----- public methods --------------------------------------------------------------------------------------------------

auto Knight::updateState() -> void {
    updateEvents();
}

auto Knight::render(sf::RenderTarget* window) -> void {
    window->draw(this->knight);
}