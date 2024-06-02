#include "Assets.h"

//private:

// ----- private methods ------------------------------------------------------------------------------------------------
auto Assets::loadTextures() -> void {

    //knightTexture
    auto knightTexture = sf::Texture();
    if (!knightTexture.loadFromFile("TinySwords/Fractions/Knights/Troops/Warrior/Warrior_Blue.png")) {
        fmt::println("File can not load from file: TinySwords/Fractions/Knights/Troops/Warrior/Warrior_Blue.png");
    }
    knightTexture.setSmooth(true);
    Assets::textures["knightTexture"] = knightTexture;



}



//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Assets::Assets() {
    loadTextures();
}


Assets::~Assets() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

auto Assets::getKnightStanding() -> Animation& {
    return Assets::knightStanding;
}

