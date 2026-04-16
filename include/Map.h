#ifndef Map_hpp
#define Map_hpp

#include <SDL2/SDL.h>
#include <array>

class Map {
  public:
    Map(SDL_Renderer *renderer);
    ~Map();

    void loadMap();
    void drawMap();

  private:
    static constexpr int ROWS = 20;
    static constexpr int COLS = 25;
    static constexpr int TILE_SIZE = 32;

    SDL_Renderer *renderer;
    SDL_Texture *bg, *wall, *door;
    SDL_Rect srcRect, destRect;

    std::array<std::array<int, COLS>, ROWS> mapGrid;
};

#endif
