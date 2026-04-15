#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <SDL2/SDL.h>

class TextureManager {
  public:
    static SDL_Texture *loadTexture(const char *imgFile,
                                    SDL_Renderer *renderer);
};

#endif
