// ================================================
// File: main.cpp
// Created on: 06-08-2025 20:06:57
// Last modified: 28-08-2025 16:01:38
// Created by: Alwin R Ajeesh
// ================================================
#include <cstdio>
#include <iostream>
#include <ostream>
#include "Game.hpp"

#define FPS_CAP 60
#define FRAME_TARGET_TIME (1000 / FPS_CAP)
int main() {

    Game game = Game();
    game.init();
    float deltaTime;
    Uint64 lastTime;
    Uint64 frameStart;
    Uint64 frameTime;
    lastTime = SDL_GetTicks();

    while (game._running) {

        frameStart = SDL_GetTicks();

        game.input();
        game.update(deltaTime);
        game.render();

        deltaTime = (frameStart - lastTime) / 1000.0f;
        lastTime = frameStart;
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_TARGET_TIME) {
            SDL_Delay(FRAME_TARGET_TIME - frameTime);
        }
    }
    // SDL_Quit();
    std::cout << "Exit Normal main" << std::endl;
    return 0;
}
