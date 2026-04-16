#ifndef SpriteComponent_h
#define SpriteComponent_h

#include "ECS.h"
#include <SDL2/SDL.h>

class PositionComponent;
class TextureManager;

class SpriteComponent : public Component {
  private:
    PositionComponent *position;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;

  public:
    SpriteComponent() = default;
    SpriteComponent(const char *path, SDL_Renderer *ren);
    ~SpriteComponent() {}

    void setTexture(const char *path);

    void init() override;
    void update() override;
    void draw() override;
};

#endif
