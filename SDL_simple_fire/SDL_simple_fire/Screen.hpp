//
//  Screen.hpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 21.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>
namespace scrspace {
class Screen {
public:
    const static int SCREEN_WIDTH = 700;
    const static int SCREEN_HEIGHT = 600;
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32 *m_buffer;
    
public:
    Screen();
    bool init();
    bool processEvent();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void close();
    void clear();
    void update();
};
}

#endif /* Screen_hpp */
