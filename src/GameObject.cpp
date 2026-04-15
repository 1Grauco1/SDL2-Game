#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *imgFile, SDL_Renderer *renderer, int x,
                       int y)
    : xpos(x), ypos(y), speed(200.0f), renderer(renderer) {

    objTexture = TextureManager::loadTexture(imgFile, renderer);
    lastTime = SDL_GetTicks();
}

GameObject::~GameObject() { SDL_DestroyTexture(objTexture); }

void GameObject::update() {
    sourceRec = {0, 0, 32, 32};

    destinationRec.x = static_cast<int>(xpos);
    destinationRec.y = static_cast<int>(ypos);
    destinationRec.w = sourceRec.w * 2;
    destinationRec.h = sourceRec.h * 2;

    input();
}

void GameObject::input() {
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_D])
        xpos += speed * deltaTime;
    if (keystate[SDL_SCANCODE_A])
        xpos -= speed * deltaTime;
    if (keystate[SDL_SCANCODE_W])
        ypos -= speed * deltaTime;
    if (keystate[SDL_SCANCODE_S])
        ypos += speed * deltaTime;
}

void GameObject::render() {
    SDL_RenderCopy(renderer, objTexture, &sourceRec, &destinationRec);
}
