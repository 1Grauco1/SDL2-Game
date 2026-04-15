#ifndef Window_hpp
#define Window_hpp

#include <SDL2/SDL.h>

class Window {
  public:
    Window();
    ~Window();

    SDL_Window *create();

  private:
    const char *title;
    int xpos, ypos;
    int width, height;
    bool fullscreen;

    SDL_Window *window;
};

#endif
