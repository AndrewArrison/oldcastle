// ================================================
// File: Renderer.cpp
// Created on: 07-08-2025 12:28:16
// Last modified: 15-08-2025 16:43:48
// Created by: Alwin R Ajeesh
// ================================================
#include "Renderer.hpp"
#include <SDL3_image/SDL_image.h>
#include <iostream>

Renderer *Renderer::_instance = nullptr;
bool Renderer::_destroyed = false;

Renderer *Renderer::instance() {
    // if (_destroyed) {
    //     std::cout << "Deleted renderer called" << std::endl;
    //     return nullptr;
    // }
    if (!_instance) {
        _instance = new Renderer();
        return _instance;
    }
    return _instance;
}

Renderer::~Renderer() {
    SDL_DestroyTexture(_texture);
    std::cout << "Delete renderer" << std::endl;
}

void Renderer::destroy() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
        _destroyed = true;
    } else {
        std::cout << "Calling destroy renderer before init?or twice" << std::endl;
    }
}

void Renderer::init(SDL_Renderer *prenderer) {
    _renderer = prenderer;
    _texture = IMG_LoadTexture(_renderer, "sprite.png");
    SDL_SetTextureScaleMode(_texture, SDL_SCALEMODE_NEAREST);
}

void Renderer::renderrect(float x, float y, float w, float h, int r, int g, int b, bool fill) {
    SDL_FRect temprect = {x, y, w, h};
    SDL_SetRenderDrawColor(_renderer, r, g, b, 255);
    if (fill) {
        SDL_RenderFillRect(_renderer, &temprect);
    } else {
        SDL_RenderRect(_renderer, &temprect);
    }
}

// ROW | COLUMN ->
void Renderer::rendertexture(SDL_FRect *rect, int column, int row, bool flip) {
    // TODO create and store sdlfrect for modification than creatiion
    // TODO make 32 unit sprite size or pass in w and h
    SDL_FRect srcrect = {32 * static_cast<float>(column), 32 * static_cast<float>(row), 32, 32};
    if (!flip) {
        SDL_RenderTextureRotated(_renderer, _texture, &srcrect, rect, 0, &point, SDL_FLIP_NONE);
    } else {
        SDL_RenderTextureRotated(_renderer, _texture, &srcrect, rect, 0, &point, SDL_FLIP_HORIZONTAL);
    }
}

void Renderer::rendertexture(SDL_FRect *rect, SDL_FRect *srcRect, bool flip) {
    if (!flip) {
        SDL_RenderTextureRotated(_renderer, _texture, srcRect, rect, 0, &point, SDL_FLIP_NONE);
    } else {
        SDL_RenderTextureRotated(_renderer, _texture, srcRect, rect, 0, &point, SDL_FLIP_HORIZONTAL);
    }
}
