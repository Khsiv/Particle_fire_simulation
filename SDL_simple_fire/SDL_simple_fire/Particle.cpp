//
//  Particle.cpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 22.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//

#include "Particle.hpp"
#include "Screen.hpp"
#include <stdlib.h>
namespace scrspace {
Particle::Particle() {
    m_x = ((2.0 * rand())/RAND_MAX) - 1;
    m_y = ((2.0 * rand())/RAND_MAX) - 1;
    m_xspeed = 0.1 * ((2.0 * rand()/RAND_MAX) - 1);
    m_xspeed = 0.1 * ((2.0 * rand()/RAND_MAX) - 1);
}
Particle::~Particle() {
    
}
void Particle::update() {
    
    m_x += m_xspeed;
    m_y += m_yspeed;
//    if (m_x <= -1.0 || m_x >= 1.0) {
//        m_xspeed = -m_xspeed;
//    }
//    if (m_y <= -1.0 || m_y >= 1.0) {
//        m_yspeed = -m_yspeed;
//    }
}
}
