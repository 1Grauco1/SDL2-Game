#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "GameObject.h"
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

    bool running() { return isRunning; }

  private:
    bool isRunning;

    Window windowManager;
    Renderer rendererManager;

    SDL_Window *window;
    GameObject *player;
};

#endif
