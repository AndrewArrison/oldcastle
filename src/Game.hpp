// ================================================
// File: Game.hpp
// Created on: 06-08-2025 20:15:01
// Last modified: 15-08-2025 16:52:48
// Created by: Alwin R Ajeesh
// ================================================
#pragma once
#include <SDL3/SDL.h>
#include "Player.hpp"
#include "Tilemap.hpp"

class Game {
  public:
    Game();
    ~Game();

    void init();

    void input();
    void update(float dt);
    void render();

    bool _running = false;

  private:
    SDL_Window *_window = nullptr;
    SDL_Renderer *_renderer = nullptr;
    SDL_Event _event;
    SDL_FPoint _camera = {0, 0};
    int _width = 854;
    int _height = 480;
    Player *player;
    Tilemap *tilemap;
};
