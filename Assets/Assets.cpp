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

    //goblinTexture
    auto goblinTexture = sf::Texture();
    if (!goblinTexture.loadFromFile("TinySwords/Goblin.png")) {
        fmt::println("File can not load from file: TinySwords/Goblin.png");
    }
    goblinTexture.setSmooth(true);
    Assets::textures["goblinTexture"] = goblinTexture;

    //goblinTextureFlipped
    auto goblinTextureFlipped = sf::Texture();
    if (!goblinTextureFlipped.loadFromFile("TinySwords/GoblinFlipped.png")) {
        fmt::println("File can not load from file: TinySwords/GoblinFlipped.png");
    }
    goblinTextureFlipped.setSmooth(true);
    Assets::textures["goblinTextureFlipped"] = goblinTextureFlipped;


}



//public:

// ----- constructor / destructor --------------------------------------------------------------------------------------

Assets::Assets() {
    loadTextures();
}

Assets::~Assets() = default;


// ----- public methods ------------------------------------------------------------------------------------------------

//knight animation getters
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


//goblin animation getters
auto Assets::getGoblinStanding() -> Animation& {
    return Assets::goblinStanding;
}

auto Assets::getGoblinRunningLeft() -> Animation & {
    return Assets::goblinRunningLeft;
}

auto Assets::getGoblinRunningRight() -> Animation & {
    return Assets::goblinRunningRight;
}

auto Assets::getGoblinAttackRight() -> Animation & {
    return Assets::goblinAttackRight;
}

auto Assets::getGoblinAttackLeft() -> Animation & {
    return Assets::goblinAttackLeft;
}

auto Assets::getGoblinAttackUp() -> Animation & {
    return Assets::goblinAttackUp;
}

auto Assets::getGoblinAttackDown() -> Animation & {
    return Assets::goblinAttackDown;

}

