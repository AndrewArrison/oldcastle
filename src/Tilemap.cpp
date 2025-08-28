// ================================================
// File: Tilemap.cpp
// Created on: 12-08-2025 11:12:36
// Last modified: 28-08-2025 16:10:14
// Created by: Alwin R Ajeesh
// ================================================
#include <cstdio>
#include <fstream>
#define STB_PERLIN_IMPLEMENTATION
#include <cmath>
#include <cstdlib>
#include <stb/stb_perlin.h>
#include "Renderer.hpp"
#include "Tilemap.hpp"

Tilemap::Tilemap() {}
Tilemap::~Tilemap() {}

void Tilemap::init() {
    _tiles.reserve(levelw * levelh);
    //
    std::ifstream file("level.txt");
    for (int y = 0; y < levelh; y++) {
        for (int x = 0; x < levelw; x++) {
            Tile tile;
            tile._pos.x = y;
            tile._pos.y = x;
            int type;
            file >> type;
            tile._type = type;
            // printf("%d", type);

            _tiles.push_back(tile);
        }
    }
    // Tile tile;
    // tile._pos = {1, 1};
    // tile._type = 2;
    // _tiles.push_back(tile);
}
void Tilemap::render(SDL_FPoint *camera) {
    for (const Tile &tile : _tiles) {
        rect = {((tile._pos.x * tilesize) - camera->x), ((tile._pos.y * tilesize) - camera->y), tilesize, tilesize};

        if (rect.x + 32 < -32 || rect.y + 32 < 0 || rect.x > _vieww || rect.y > _viewh) {
            continue;
        }

        switch (tile._type) {
            sourceRect.x = 0;
            sourceRect.y = 0;
            // TODO reader adter seting srxrect
        case 0:
            sourceRect.x = 9 * 32;
            sourceRect.y = 0;
            // Renderer::instance()->renderrect(rect.x, rect.y, tilesize, tilesize, 255, 0, 0);
            break;
        case 1:
            // sourceRect.x = 8 * 32;
            // sourceRect.y = 0;
            sourceRect.x = 8 * 32;
            sourceRect.y = 0;
            Renderer::instance()->renderrect(rect.x, rect.y, tilesize, tilesize, 0, 255, 0);
            break;
        case 2:
            // sourceRect.x = 9 * 32;
            // sourceRect.y = 1 * 32;
            break;
        default:
            Renderer::instance()->renderrect(rect.x, rect.y, tilesize, tilesize, 0, 0, 250);
            sourceRect.x = 9 * 32;
            sourceRect.y = 1 * 32;
            break;
        }
        // Renderer::instance()->rendertexture(&rect, &sourceRect);
    }
}
