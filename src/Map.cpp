#include "Map.h"
#include "TextureManager.h"

Map::Map(SDL_Renderer *ren) : renderer(ren) {
    bg = TextureManager::loadTexture("assets/sprites/bg.png", renderer);
    wall = TextureManager::loadTexture("assets/sprites/wall.png", renderer);
    door = TextureManager::loadTexture("assets/sprites/door.png", renderer);

    loadMap();

    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = TILE_SIZE;

    destRect.w = destRect.h = TILE_SIZE;
}

Map::~Map() {
    SDL_DestroyTexture(bg);
    SDL_DestroyTexture(wall);
    SDL_DestroyTexture(door);
}

void Map::loadMap() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            // Create a border of walls
            if (row == 0 || col == 0 || row == ROWS - 1 || col == COLS - 1) {
                mapGrid[row][col] = 1;
            } else {
                mapGrid[row][col] = 0; // Floor
            }
        }
    }
    mapGrid[0][12] = 2;
}

void Map::drawMap() {
    int type = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            type = mapGrid[row][col];

            destRect.x = col * TILE_SIZE;
            destRect.y = row * TILE_SIZE;

            switch (type) {
            case 0:
                TextureManager::draw(bg, srcRect, destRect, renderer);
                break;
            case 1:
                TextureManager::draw(wall, srcRect, destRect, renderer);
                break;
            case 2:
                TextureManager::draw(door, srcRect, destRect, renderer);
                break;
            default:
                break;
            }
        }
    }
}
