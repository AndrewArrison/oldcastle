// ================================================
// File: Renderer.hpp
// Created on: 07-08-2025 12:21:59
// Last modified: 15-08-2025 16:30:03
// Created by: Alwin R Ajeesh
// ================================================
#pragma once
#include <SDL3/SDL_render.h>

class Renderer {
  public:
    static Renderer *instance();
    void init(SDL_Renderer *prenderer);
    void destroy();
    void renderrect(float x, float y, float w, float h, int r, int g, int b, bool fill = true);
    void rendertexture(SDL_FRect *rrect, int row, int column, bool flip = false);
    void rendertexture(SDL_FRect *rect, SDL_FRect *srcRect, bool flip = false);

  private:
    Renderer() {}
    ~Renderer();
    SDL_Renderer *_renderer;
    static Renderer *_instance;
    static bool _destroyed;

    SDL_Texture *_texture;
    SDL_FPoint point = {0, 0};
};
