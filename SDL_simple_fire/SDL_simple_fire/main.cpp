
//  main.cpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 17.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.hpp"
#include "Swarm.hpp"
using namespace scrspace;
int main() {
    
    srand(int(time(0)));
    
    Screen screen;
    Swarm swarm;
    if (!screen.init()) {
        std::cout << "False init\n;";
    }
    const Particle * const pParticles = swarm.getParticles();
    
    
    while (1) {
        
        screen.clear();
        int elapsed = SDL_GetTicks();
        swarm.update();
        unsigned char green = (1 + sin(elapsed * 0.0001)) * 128;
        unsigned char red   = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char blue  = (1 + sin(elapsed * 0.0003)) * 128;
        /*
        for (int i(0); i < Screen::SCREEN_HEIGHT; i++) {
            for (int j(0); j < Screen::SCREEN_WIDTH; j++) {
                screen.setPixel(j, i, 0, green, 0);
            }
        }
        */
        for (int i(0); i < Swarm::NPARTICLES; ++i) {
            int x = (pParticles[i].getX() + 1) * Screen::SCREEN_WIDTH/2;
            int y = (pParticles[i].getY() + 0) * Screen::SCREEN_HEIGHT/2 + Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.update();
        if (!screen.processEvent()) {
            break;
        }
    }
    screen.close();
}
