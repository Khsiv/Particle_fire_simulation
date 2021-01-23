//
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
    
    srand(time(0));
    
    Screen screen;
    
    if (!screen.init()) {
        std::cout << "False init\n;";
    }
    
    Swarm swarm;
    
    while (1) {
        
          const Particle * const pParticles = swarm.getParticles();
        
        for (int i(0); i < Swarm::NPARTICLES; ++i) {
            int x = (pParticles[i].getX() + 1) * Screen::SCREEN_WIDTH/2;
            int y = (pParticles[i].getY() + 1) * Screen::SCREEN_HEIGHT/2;
            
            screen.setPixel(x, y, 200, 0, 125);
        }
        
        
        /*
         int elapsed = SDL_GetTicks();
         
        unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
        unsigned char red   = (1 + sin(elapsed * 0.0004)) * 128;
        unsigned char blue  = (1 + sin(elapsed * 0.0008)) * 128;
        
        for (int i(0); i < Screen::SCREEN_HEIGHT; i++) {
            for (int j(0); j < Screen::SCREEN_WIDTH; j++) {
                screen.setPixel(j, i, red, green, blue);
            }
        }
        */
        
        screen.update();
        if (!screen.processEvent()) {
            break;
        }
    }
    
    screen.close();
}
