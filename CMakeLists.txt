cmake_minimum_required(VERSION 3.10)
project(sdl2-Game)

find_package(SDL2 REQUIRED)

add_executable(sdl2-Game main.cpp Game.cpp)

target_include_directories(sdl2-Game PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(sdl2-Game ${SDL2_LIBRARIES})
