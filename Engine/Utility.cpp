#include "Utility.h"

// randomize integers
auto mathRandomInCpp(int const from, int const to) -> int {
    static auto device = std::random_device();
    static auto engine = std::default_random_engine(device());

    auto distribution = std::uniform_int_distribution(from, to);
    return distribution(engine);
}
