cmake_minimum_required(VERSION 3.10)
project(sdl2-Game)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB SRC_FILES CONFIGURE_DEPENDS *.cpp)

add_executable(sdl2-Game ${SRC_FILES})

target_link_libraries(sdl2-Game
    SDL2::SDL2
    SDL2_image::SDL2_image
)
