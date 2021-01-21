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
        
        if (!screen.processEvent()) {
            break;
        }
    }
    
    screen.close();
}
