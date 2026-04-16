#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager {
  public:
    static SDL_Texture *loadTexture(const char *fileName, SDL_Renderer *ren);
    static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest,
                     SDL_Renderer *ren);
};

#endif
