#ifndef GameObject_hpp
#define GameObject_hpp

#include <SDL2/SDL.h>

class GameObject {
  public:
    GameObject(const char *imgFile, SDL_Renderer *renderer, int x, int y);
    ~GameObject();

    void update();
    void render();
    void input();

  private:
    float xpos, ypos;
    float speed;

    Uint32 lastTime;

    SDL_Texture *objTexture;
    SDL_Rect sourceRec, destinationRec;
    SDL_Renderer *renderer;
};

#endif
