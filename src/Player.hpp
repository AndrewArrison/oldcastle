// ================================================
// File: Player.hpp
// Created on: 08-08-2025 14:18:24
// Last modified: 02-09-2025 18:07:10
// Created by: Alwin R Ajeesh
// ================================================
#pragma once

#include <SDL3/SDL_rect.h>
#include "AnimationSystem.hpp"
#include "Entity.hpp"
#include "Tilemap.hpp"

#define SPEED 400.0f;
#define GRAVITY 180.0f;

class Player : public Entity {
  public:
    Player(SDL_FRect *prect, Tilemap *ptilemap);
    ~Player();

    void input(float dt);
    void update(float dt) override;
    void render(SDL_FPoint *camera) override;

    bool moving_right = false;
    bool moving_left = false;
    bool jump = false;
    bool in_air = false;

  private:
    int direction = 1;
    float velY = 0.0f;
    float dx = 0.0f;
    float dy = 0.0f;
    int currentframex = 0;
    int currentframey = 0;
    AnimationSystem *animation;
    Tilemap *_tilemap;
};
