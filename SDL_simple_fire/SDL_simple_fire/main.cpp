//
//  main.cpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 17.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//
#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 600;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL init failed";
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    
    if (!window) {
        SDL_Quit();
        return 2;
    }
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    
    std::cout << "SDL succeeded.\n";
    SDL_DestroyWindow(window);
    SDL_Quit();
}
