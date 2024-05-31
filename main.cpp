#include "Game.h"

auto main() -> int {

    // ----- creating game object --------------------------------------------------------------------------------------
    auto game = Game();

    // ----- game loop -------------------------------------------------------------------------------------------------
    while (game.isRunning()) {

        //update game state
        game.updateState();

        //render game
        game.render();

    }

}
