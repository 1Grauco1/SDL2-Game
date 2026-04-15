cmake_minimum_required(VERSION 3.10)
project(sdl2-Game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(sdl2-Game ${SRC_FILES})

target_include_directories(sdl2-Game PRIVATE include)

target_link_libraries(sdl2-Game
    SDL2::SDL2
    SDL2_image::SDL2_image
)
