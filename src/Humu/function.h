#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <chrono>
#include <thread>

bool IsMouseInArea(int x, int y, const SDL_Rect& areaRect) {
    return (x >= areaRect.x && x <= areaRect.x + areaRect.w &&
        y >= areaRect.y && y <= areaRect.y + areaRect.h);
}


void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

bool is_collision(SDL_Rect rect1, SDL_Rect rect2) {
    double x1 = static_cast<double>(rect1.x);
    double y1 = static_cast<double>(rect1.y);
    double w1 = static_cast<double>(rect1.w);
    double h1 = static_cast<double>(rect1.h);

    double x2 = static_cast<double>(rect2.x);
    double y2 = static_cast<double>(rect2.y);
    double w2 = static_cast<double>(rect2.w);
    double h2 = static_cast<double>(rect2.h);

    if (x1 < x2 + w2 && x1 + w1 > x2 &&
        y1 < y2 + h2 && y1 + h1 > y2) {
        return true;
    }
    else {
        return false;
    }
}