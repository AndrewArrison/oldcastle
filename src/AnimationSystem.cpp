// ================================================
// File: AnimationSystem.cpp
// Created on: 10-08-2025 20:32:29
// Last modified: 11-08-2025 13:02:37
// Created by: Alwin R Ajeesh
// ================================================
#include "AnimationSystem.hpp"
#include <cstdio>
#include <string>
#include "Timer.hpp"

AnimationSystem::AnimationSystem(int &column, int &row) : currentframex(column), currentframey(row) {}

void AnimationSystem::adda(const char *animationname, int framesx, int framey, float duration) {
    Animation animationt{framesx, duration};
    // TODO - DONE get string once
    std::string namestring = std::string(animationname);
    _animations[namestring] = animationt;
    _actionlist[namestring] = framey;
}

bool AnimationSystem::setaction(const char *newaction) {
    std::string actionstring = std::string(newaction);
    if (actionstring != currentaction) {
        currentaction = actionstring;
        // printf("set action\n");
        return true;
    }
    return false;
}
void AnimationSystem::removea(const char *animationname) { _animations.erase(animationname); }

void AnimationSystem::update(float dt) {
    if (currentaction != lastaction) {
        currentframex = 0;
        lastaction = currentaction;
        // printf("New action\n");
    }
    timeer += dt;
    // TODO - DONE one time accest to map
    duration = _animations[currentaction]._duration;
    // if (timeer >= _animations[currentaction]._duration) {
    //     timeer -= _animations[currentaction]._duration;
    if (timeer >= duration) {
        timeer -= duration;
        // printf("%i", currentframe);
        currentframex += 1;
    }
    if (currentframex > _animations[currentaction]._maxframe - 1) {
        currentframex = 0;
    }
    currentframey = _actionlist[currentaction];
}
