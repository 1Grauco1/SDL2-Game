#include "Game.h"
#include "Components.h"

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr) {}

Game::~Game() {}

void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL init failed: " << SDL_GetError() << std::endl;
        return;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "IMG init failed: " << SDL_GetError() << std::endl;
        return;
    }

    window = windowManager.create();
    renderer = rendererManager.create(window);

    entityManager = std::make_unique<Manager>();
    map = std::make_unique<Map>(renderer);

    auto &player(entityManager->addEntity());

    player.addComponent<PositionComponent>(100, 100);
    player.addComponent<SpriteComponent>("assets/sprites/player.png", renderer);

    isRunning = true;
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            isRunning = false;
    }
}

void Game::update() {
    entityManager->refresh();
    entityManager->update();
}

void Game::render() {
    rendererManager.clear();

    if (map)
        map->drawMap();
    if (entityManager)
        entityManager->draw();

    rendererManager.present();
}

void Game::clean() {
    map.reset();
    entityManager.reset();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    std::cout << "Game Cleaned" << std::endl;
}
