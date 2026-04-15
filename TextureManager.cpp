#include "TextureManager.h"

SDL_Texture *TextureManager::loadTextute(const char *imgFile,
                                         SDL_Renderer *renderer) {

    SDL_Surface *tempSurface = IMG_Load(imgFile);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}
