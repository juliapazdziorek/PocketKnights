cmake_minimum_required(VERSION 3.27)
project(CppGra)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)
FetchContent_MakeAvailable(fmt)

add_executable(PocketKnight main.cpp
        Game.cpp
        Engine/Entity.cpp
        Engine/Collidable.cpp
        Assets/Assets.cpp
        Assets/MapBorder.cpp
        Assets/MapTile.cpp
        Assets/MapTileAnimated.cpp
        Assets/Animation.cpp
        Map.cpp
        Knight.cpp
        Goblin.cpp)

target_link_libraries(PocketKnight fmt sfml-graphics)