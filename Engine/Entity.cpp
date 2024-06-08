#include "Entity.h"

// -----constructor / destructor ---------------------------------------------------------------------------------------

Entity::Entity() {
    isAlive = true;
}


// ----- public methods ------------------------------------------------------------------------------------------------

auto Entity::checkIfAlive() const -> bool {
    return isAlive;
}

auto Entity::kill() -> void {
    isAlive = false;
}
