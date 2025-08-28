// ================================================
// File: Tilemap.hpp
// Created on: 11-08-2025 20:34:24
// Last modified: 15-08-2025 16:36:03
// Created by: Alwin R Ajeesh
// ================================================
#pragma once

#include <SDL3/SDL_rect.h>
#include <vector>
typedef struct {
    float x;
    float y;
} Vector2f;

typedef struct {
    Vector2f _pos;
    int _type;
} Tile;

class Tilemap {
  public:
    Tilemap();
    ~Tilemap();
    void init();
    void render(SDL_FPoint *camera);

  private:
    std::vector<Tile> _tiles;
    float _vieww = 854;
    float _viewh = 480;
    int levelh = 17;
    int levelw = 10;
    float tilesize = 32.0f * 1.5f;
    SDL_FRect sourceRect = {0, 0, 32, 32};
    SDL_FRect rect = {0, 0, 0, 0};
};
