// ================================================
// File: Tilemap.cpp
// Created on: 12-08-2025 11:12:36
// Last modified: 02-09-2025 17:58:31
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
Tilemap::~Tilemap() { _tiles.clear(); }

void Tilemap::init() {
    _tiles.reserve(levelw * levelh);
    std::ifstream file("level.txt");
    for (int y = 0; y < levelh; y++) {
        for (int x = 0; x < levelw; x++) {
            Tile tile;
            int type;
            file >> type;

            tile._pos.x = x;
            tile._pos.y = y;
            tile._type = type;

            _tiles.push_back(tile);
        }
    }
    file.close();
}

void Tilemap::render(SDL_FPoint *camera) {
    for (const Tile &tile : _tiles) {
        rect = {((tile._pos.x * tilesize) - camera->x), ((tile._pos.y * tilesize) - camera->y), tilesize, tilesize};

        if (rect.x + 32 < -32 || rect.y + 32 < 0 || rect.x > _vieww || rect.y > _viewh) {
            continue;
        }
        sourceRect.x = 0;
        sourceRect.y = 0;
        switch (tile._type) {
        case 0:
            continue;
            break;
        case 1:
            sourceRect.x = 9 * 32;
            sourceRect.y = 0;
            break;
        case 2:
            Renderer::instance()->renderrect(rect.x, rect.y, tilesize, tilesize, 255, 0, 0);
            break;
        default:
            sourceRect.x = 0;
            sourceRect.y = 0;
            break;
        }
        Renderer::instance()->rendertexture(&rect, &sourceRect);
    }
}

int Tilemap::getTile(float x, float y) { return 0; }
