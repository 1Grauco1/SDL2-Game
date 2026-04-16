#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>

#include "ECS.h"
#include "Map.h"
#include "Renderer.h"
#include "Window.h"

class Game {
  public:
    Game();
    ~Game();

    void init();
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() const { return isRunning; }

  private:
    bool isRunning;

    Window windowManager;
    Renderer rendererManager;

    SDL_Window *window;
    SDL_Renderer *renderer;

    std::unique_ptr<Manager> entityManager;
    std::unique_ptr<Map> map;
};

#endif
