#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {
  public:
    Game();
    ~Game();

    float playerX = 100.0f;
    float playerY = 100.0f;
    float speed = 200.0f; // pixels per second
    Uint32 lastTime = 0;

    void init(const char *title, int xpos, int ypos, int width, int height,
              bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

  private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif
