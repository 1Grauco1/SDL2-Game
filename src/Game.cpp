#include "Game.h"

Game::Game() : isRunning(false), window(nullptr), player(nullptr) {}

Game::~Game() {}

void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL init failed: " << SDL_GetError() << std::endl;
        return;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "IMG init failed: " << IMG_GetError() << std::endl;
        return;
    }

    window = windowManager.create();
    if (!window)
        return;

    if (!rendererManager.create(window))
        return;

    player = new GameObject("assets/sprites/player.png", rendererManager.get(),
                            0, 0);

    isRunning = true;
}

void Game::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Game::update() { player->update(); }

void Game::render() {
    rendererManager.clear();
    player->render();
    rendererManager.present();
}

void Game::clean() {
    delete player;

    SDL_DestroyRenderer(rendererManager.get());
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    std::cout << "Game Cleaned" << std::endl;
}
