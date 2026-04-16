#include "TextureManager.h"

SDL_Texture *TextureManager::loadTexture(const char *fileName,
                                         SDL_Renderer *ren) {
    SDL_Surface *tempSurface = IMG_Load(fileName);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

void TextureManager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest,
                          SDL_Renderer *ren) {
    SDL_RenderCopy(ren, tex, &src, &dest);
}
