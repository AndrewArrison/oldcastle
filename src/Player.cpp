// ================================================
// File: Player.cpp
// Created on: 08-08-2025 14:28:45
// Last modified: 02-09-2025 18:07:34
// Created by: Alwin R Ajeesh
// ================================================
#include "Player.hpp"
#include <SDL3/SDL_timer.h>
#include <cmath>
#include "AnimationSystem.hpp"
#include "Renderer.hpp"

Player::Player(SDL_FRect *prect, Tilemap *ptilemap)
    : Entity(prect), animation(new AnimationSystem(currentframex, currentframey)), _tilemap(ptilemap) {
    animation->adda("idle", 2, 0, 0.3f);
    animation->adda("run", 2, 1, 0.2f);
    animation->adda("climb", 2, 2, 0.2f);
    animation->adda("jump", 1, 3, 0.2f);
}

Player::~Player() {
    _tilemap = nullptr;
    delete animation;
    animation = nullptr;
}

void Player::input(float dt) {
    // x
    dx = 0.0f;
    if (moving_left) {
        dx -= SPEED;
        direction = -1;
    }
    if (moving_right) {
        dx += SPEED;
        direction = 1;
    }
    rect.x += dx * dt;
    // c x
    //  y
    if (jump && !in_air) {
        in_air = true;
        velY -= 1800.0f;
    }
    //
    velY += GRAVITY;
    // clip to terminal velocity
    if (velY > 500.0f) {
        velY = 500.0f;
    }

    dy = velY * dt;
    // c y
    if (rect.y + rect.h + dy >= 400) {
        velY = 0;
        dy = 0;
        rect.y = 400 - rect.h;
        in_air = false;
    } else {
        rect.y += dy;
    }

    // update action for animation
    animation->setaction("idle");
    if (in_air) {
        animation->setaction("jump");
    } else if (moving_left || moving_right) {
        animation->setaction("run");
    }
}

void Player::update(float dt) {
    input(dt);
    animation->update(dt);
}
void Player::render(SDL_FPoint *camera) {
    SDL_FRect desrect = {(rect.x - camera->x), (rect.y - camera->y), rect.w, rect.h};
    if (direction == 1) {
        Renderer::instance()->rendertexture(&desrect, currentframex, currentframey);
    } else {
        Renderer::instance()->rendertexture(&desrect, currentframex, currentframey, true);
    }
}
