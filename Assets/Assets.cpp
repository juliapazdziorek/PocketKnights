#include "Assets.h"

//private:

// ----- public methods ------------------------------------------------------------------------------------------------
auto Assets::createKnightOriginal() -> void {
    if (!knightOriginal.loadFromFile("TinySwords/Fractions/Knights/Troops/Warrior/Original/Warrior_Blue1.png")) {
        fmt::println("File can not load from file: TinySwords/Fractions/Knights/Troops/Warrior/Original/Warrior_Blue1.png");
    }
    knightOriginal.setSmooth(true);
}


//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Assets::Assets() {
    createKnightOriginal();
}


Assets::~Assets() = default;


// ----- public methods --------------------------------------------------------------------------------------------
auto Assets::getKnightOriginal() -> sf::Texture& {
    return Assets::knightOriginal;
}

