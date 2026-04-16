#ifndef Renderer_hpp
#define Renderer_hpp

#include <SDL2/SDL.h>

class Renderer {
  public:
    Renderer();
    ~Renderer();

    SDL_Renderer *create(SDL_Window *window);

    void clear();
    void present();

    SDL_Renderer *get() { return renderer; }

  private:
    SDL_Renderer *renderer;
};

#endif
