#include "Game.hpp"

int main(int argc, char *argv[]) {

    Game *game = new Game();

    game->init("SDL2 Hyprland Engine", SDL_WINDOWPOS_CENTERED,
               SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();

        SDL_Delay(16);
    }

    game->clean();
    delete game;

    return 0;
}
