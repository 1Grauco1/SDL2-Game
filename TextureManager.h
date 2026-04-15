#include "Game.h"

class TextureManager {
  public:
    static SDL_Texture *loadTextute(const char *imgFile,
                                    SDL_Renderer *renderer);
};
