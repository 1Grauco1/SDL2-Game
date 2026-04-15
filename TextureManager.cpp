#include "TextureManager.h"
#include <SDL2/SDL_image.h>
#include <iostream>

SDL_Texture *TextureManager::loadTexture(const char *imgFile,
                                         SDL_Renderer *renderer) {

    SDL_Surface *tempSurface = IMG_Load(imgFile);

    if (!tempSurface) {
        std::cout << "IMG_Load error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}
