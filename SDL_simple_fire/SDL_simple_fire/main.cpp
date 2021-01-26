
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
    
    srand(int(time(NULL)));
    
    Screen screen;
    Swarm swarm;
    if (!screen.init()) {
        std::cout << "False init\n;";
    }
    const Particle * const pParticles = swarm.getParticles();
    
    
    while (1) {
        
        
        int elapsed = SDL_GetTicks();
        swarm.update(elapsed);
//        memset(screen.getBuff(), 0, Screen::SCREEN_WIDTH * Screen::SCREEN_HEIGHT * sizeof(Uint32));
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red   = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue  = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
        
        for (int i(0); i < Swarm::NPARTICLES; ++i) {
            int x = (pParticles[i].m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = (pParticles[i].m_y + 0) * Screen::SCREEN_HEIGHT/2 + Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);
        }
        screen.boxBlur();
        
        screen.update();
        if (!screen.processEvent()) {
            break;
        }
    }
    screen.close();
}
