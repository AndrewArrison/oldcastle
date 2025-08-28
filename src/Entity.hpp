// ================================================
// File: Entity.hpp
// Created on: 08-08-2025 19:54:57
// Last modified: 15-08-2025 16:54:12
// Created by: Alwin R Ajeesh
// ================================================
#include <SDL3/SDL_rect.h>

class Entity {
  public:
    Entity(SDL_FRect *prect) : rect(*prect) {};
    virtual ~Entity();

    virtual void update(float dt) = 0;
    virtual void render(SDL_FPoint *camera) = 0;

    SDL_FRect rect;

  protected:
};
