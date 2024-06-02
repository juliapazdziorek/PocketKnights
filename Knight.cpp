#include "Knight.h"

//private:

// ----- event updating ------------------------------------------------------------------------------------------------

auto Knight::updateEvents() -> void {

    //moving: left, right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->knight.move(-this->movingSpeed, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->knight.move(this->movingSpeed, 0);

    //moving up, down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->knight.move(0, -this->movingSpeed);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->knight.move(0, this->movingSpeed);

}

auto Knight::updateTexture() -> void {
    Assets::getKnightStanding().updateFrame();
    Assets::getKnightStanding().applyTexture(knight);
}



//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Knight::Knight() {
    this->knight.setScale(sf::Vector2f(0.5f, 0.5f));
    this->movingSpeed = 3;
}

Knight::~Knight() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto Knight::updateState() -> void {
    updateEvents();
    updateTexture();
}

auto Knight::render(sf::RenderTarget* window) -> void {
    window->draw(this->knight);
}