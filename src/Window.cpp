#include "Window.h"
#include <cstdlib>
#include <iostream>

Window::Window()
    : title("MyGame"), xpos(SDL_WINDOWPOS_CENTERED),
      ypos(SDL_WINDOWPOS_CENTERED), width(800), height(600), fullscreen(false),
      window(nullptr) {}

Window::~Window() {
    if (window) {
        SDL_DestroyWindow(window);
    }
}

SDL_Window *Window::create() {
#ifdef __linux__
    setenv("SDL_VIDEODRIVER", "wayland", 0);
#endif

    int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return window;
}
