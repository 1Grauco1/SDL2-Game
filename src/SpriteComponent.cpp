#include "Components.h"
#include "TextureManager.h"

SpriteComponent::SpriteComponent(const char *path, SDL_Renderer *ren) {
    renderer = ren;
    setTexture(path);
}

void SpriteComponent::setTexture(const char *path) {
    texture = TextureManager::loadTexture(path, renderer);
}

void SpriteComponent::init() {
    // Accessing the sibling component through the entity
    position = &entity->getComponent<PositionComponent>();

    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 32;
    destRect.w = destRect.h = 64;
}

void SpriteComponent::update() {
    destRect.x = position->xpos;
    destRect.y = position->ypos;
}

void SpriteComponent::draw() {
    TextureManager::draw(texture, srcRect, destRect, renderer);
}
