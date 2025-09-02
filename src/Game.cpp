// ================================================
// File: Game.cpp
// Created on: 06-08-2025 20:21:07
// Last modified: 02-09-2025 18:08:33
// Created by: Alwin R Ajeesh
// ================================================
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include "Renderer.hpp"
#include "Tilemap.hpp"

Game::Game() {}

Game::~Game() {
    delete tilemap;
    tilemap = nullptr;
    delete player;
    player = nullptr;
    Renderer::instance()->destroy();
    SDL_DestroyRenderer(_renderer);
    _renderer = nullptr;
    SDL_DestroyWindow(_window);
    _window = nullptr;
    SDL_Quit();
    std::cout << "Exit Normal Game" << std::endl;
}

void Game::init() {
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        throw std::runtime_error("Failed to init video\n");
    }

    _window = SDL_CreateWindow("game", _width, _height, SDL_WINDOW_MAXIMIZED);
    if (!_window) {
        SDL_Quit();
        throw std::runtime_error("Failed to create video\n");
    }

    _renderer = SDL_CreateRenderer(_window, nullptr);
    if (!_renderer) {
        SDL_DestroyWindow(_window);
        SDL_Quit();
        throw std::runtime_error("Failed to create renderer\n");
    }
    Renderer::instance()->init(_renderer);
    _camera = {0, 0};
    tilemap = new Tilemap();
    tilemap->init();
    SDL_FRect prect = {100, 100, 32 * 1.5, 32 * 1.5};
    player = new Player(&prect, tilemap);

    _running = true;
}

void Game::input() {
    while (SDL_PollEvent(&_event)) {
        switch (_event.type) {
        case SDL_EVENT_QUIT:
            _running = false;
            break;
        case SDL_EVENT_KEY_DOWN:
            if (_event.key.scancode == SDL_SCANCODE_ESCAPE) {
                _running = false;
            }
            if (_event.key.scancode == SDL_SCANCODE_A) {
                player->moving_left = true;
            }
            if (_event.key.scancode == SDL_SCANCODE_D) {
                player->moving_right = true;
            }
            if (_event.key.scancode == SDL_SCANCODE_W) {
                player->jump = true;
            }
            break;
        case SDL_EVENT_KEY_UP:
            if (_event.key.scancode == SDL_SCANCODE_A) {
                player->moving_left = false;
            }
            if (_event.key.scancode == SDL_SCANCODE_D) {
                player->moving_right = false;
            }
            if (_event.key.scancode == SDL_SCANCODE_W) {
                player->jump = false;
            }
            break;
        default:
            break;
        }
    }
}

void Game::update(float dt) {
    player->update(dt);
    _camera = {(player->rect.x + 16 - (854.0f / 2.0f)), 0};
}

void Game::render() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    tilemap->render(&_camera);
    player->render(&_camera);
    SDL_RenderPresent(_renderer);
}
