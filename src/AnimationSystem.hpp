// ================================================
// File: AnimationSystem.hpp
// Created on: 10-08-2025 18:27:43
// Last modified: 11-08-2025 12:53:17
// Created by: Alwin R Ajeesh
// ================================================
#pragma once

#include <SDL3/SDL_rect.h>
#include <cstdio>
#include <string>
#include <unordered_map>
struct Animation {
    int _maxframe;
    float _duration;
};

class AnimationSystem {
  public:
    AnimationSystem(int &column, int &row);
    ~AnimationSystem() { _animations.clear(); }
    void adda(const char *animationname, int framesx, int framey, float duration);
    bool setaction(const char *newaction);
    void removea(const char *animationname);
    void update(float dt);

  private:
    std::unordered_map<std::string, Animation> _animations;
    std::unordered_map<std::string, int> _actionlist;
    float timeer = 0.0f;
    int &currentframex;
    int &currentframey;
    std::string currentaction = "idle";
    std::string lastaction = "idle";
    float duration = 0.0f;
};
