#include "Renderer.h"
#include <iostream>

Renderer::Renderer() : renderer(nullptr) {}

Renderer::~Renderer() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
}

SDL_Renderer *Renderer::create(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cout << "Renderer creation failed: " << SDL_GetError()
                  << std::endl;
        return nullptr;
    }

    return renderer;
}

void Renderer::clear() { SDL_RenderClear(renderer); }

void Renderer::present() { SDL_RenderPresent(renderer); }
