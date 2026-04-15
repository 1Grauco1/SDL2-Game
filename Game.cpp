#include "Game.h"
#include "TextureManager.h"
#include <stdlib.h>

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr) {}
Game::~Game() {}

SDL_Texture *player_tex;

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {

#ifdef __linux__
    setenv("SDL_VIDEODRIVER", "wayland", 1);
#endif

    int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "subsys initialized" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
            std::cout << "rederer created" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    player_tex =
        TextureManager::loadTextute("assets/sprites/player.png", renderer);

    lastTime = SDL_GetTicks();
}

void Game::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_D])
        playerX += speed * deltaTime;

    if (keystate[SDL_SCANCODE_A])
        playerX -= speed * deltaTime;

    if (keystate[SDL_SCANCODE_W])
        playerY -= speed * deltaTime;

    if (keystate[SDL_SCANCODE_S])
        playerY += speed * deltaTime;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); // Orange
    SDL_RenderClear(renderer);

    SDL_Rect dst = {(int)playerX, (int)playerY, 64, 64};

    SDL_RenderCopy(renderer, player_tex, NULL, &dst);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}
