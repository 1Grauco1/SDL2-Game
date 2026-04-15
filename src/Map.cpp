#include "Map.h"
#include "TextureManager.h"

Map::Map(SDL_Renderer *renderer)
    : renderer(renderer), bg(nullptr), wall(nullptr), door(nullptr) {

    bg = TextureManager::loadTexture("assets/sprites/bg.png", renderer);
    wall = TextureManager::loadTexture("assets/sprites/wall.png", renderer);
    door = TextureManager::loadTexture("assets/sprites/door.png", renderer);

    loadMap();

    srcRect = {0, 0, TILE_SIZE, TILE_SIZE};
    destRect = {0, 0, TILE_SIZE, TILE_SIZE};
}

Map::~Map() {
    if (bg)
        SDL_DestroyTexture(bg);
    if (wall)
        SDL_DestroyTexture(wall);
    if (door)
        SDL_DestroyTexture(door);
}

void Map::loadMap() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == 0 || col == 0 || row == ROWS - 1 || col == COLS - 1)
                map[row][col] = 1; // parede
            else
                map[row][col] = 0; // chão
        }
    }

    map[0][12] = 2; // porta
}

void Map::drawMap() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {

            int tile = map[row][col];

            destRect.x = col * TILE_SIZE;
            destRect.y = row * TILE_SIZE;

            switch (tile) {
            case 0:
                SDL_RenderCopy(renderer, bg, &srcRect, &destRect);
                break;
            case 1:
                SDL_RenderCopy(renderer, wall, &srcRect, &destRect);
                break;
            case 2:
                SDL_RenderCopy(renderer, door, &srcRect, &destRect);
                break;
            }
        }
    }
}
