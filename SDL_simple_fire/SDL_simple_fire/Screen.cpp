//
//  Screen.cpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 21.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//

#include "Screen.hpp"

namespace scrspace {
Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL),  m_buffer(NULL) {
        
    }


bool Screen::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }
    m_window = SDL_CreateWindow("Fire explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    
    if (!m_window) {
        SDL_Quit();
        return false;
    }
    
    
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                                            SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if (!m_renderer) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    
    if (!m_texture) {
        SDL_DestroyWindow(m_window);
        SDL_DestroyRenderer(m_renderer);
        SDL_Quit();
        return false;
    }
    
    Uint32 *buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
    
    for (int i {0}; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i) {
        buffer[i] = 0xFFFF00FF;
    }
    SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
    return true;
}
bool Screen::processEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}
void Screen::close() {
    delete [] m_buffer;
    std::cout << "SDL succeeded.\n";
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

}
