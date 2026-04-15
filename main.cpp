#include "Game.h"

int main(int argc, char *argv[]) {

    Game *game = new Game();

    game->init();

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
