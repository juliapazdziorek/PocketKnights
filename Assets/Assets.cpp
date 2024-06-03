#include "Assets.h"

//private:

// ----- private methods ------------------------------------------------------------------------------------------------
auto Assets::loadTextures() -> void {

    //knightTexture
    auto knightTexture = sf::Texture();
    if (!knightTexture.loadFromFile("TinySwords/Knight.png")) {
        fmt::println("File can not load from file: TinySwords/Knight.png");
    }
    knightTexture.setSmooth(true);
    Assets::textures["knightTexture"] = knightTexture;

    //knightTextureFlipped
    auto knightTextureFlipped = sf::Texture();
    if (!knightTextureFlipped.loadFromFile("TinySwords/KnightFlipped.png")) {
        fmt::println("File can not load from file: TinySwords/KnightFlipped.png");
    }
    knightTextureFlipped.setSmooth(true);
    Assets::textures["knightTextureFlipped"] = knightTextureFlipped;

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

auto Assets::getKnightRunningLeft() -> Animation & {
    return Assets::knightRunningLeft;
}

auto Assets::getKnightRunningRight() -> Animation & {
    return Assets::knightRunningRight;
}

auto Assets::getKnightAttackRight() -> Animation & {
    return Assets::knightAttackRight;
}

auto Assets::getKnightAttackLeft() -> Animation & {
    return Assets::knightAttackLeft;
}

auto Assets::getKnightAttackUp() -> Animation & {
    return Assets::knightAttackUp;
}

auto Assets::getKnightAttackDown() -> Animation & {
    return Assets::knightAttackDown;
}