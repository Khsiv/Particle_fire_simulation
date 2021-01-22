//
//  main.cpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 17.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//
#include <SDL2/SDL.h>
#include <iostream>
#include "Screen.hpp"
using namespace scrspace;
int main() {
    
    Screen screen;
    
    if (!screen.init()) {
        std::cout << "False init\n;";
    }

    while (1) {
        
        for (int i(300); i < Screen::SCREEN_HEIGHT; i++) {
            for (int j(200); j < Screen::SCREEN_WIDTH; j++) {
                screen.setPixel(j, i, 100, 0, 200);
            }
        }
        
        screen.setPixel(200, 100, 0, 0, 0);
        screen.update();
        if (!screen.processEvent()) {
            break;
        }
        
        
    }
    
    screen.close();
}
