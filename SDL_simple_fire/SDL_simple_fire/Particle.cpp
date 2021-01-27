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
Particle::Particle() : m_x(0), m_y(0) {
    init();
}

void Particle::init() {
    m_x = 0;
    m_y = 0;
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.04 * rand())/RAND_MAX;
    m_speed *= m_speed;
}

Particle::~Particle() {
    
}
void Particle::update(int interval) {
    m_direction += interval * 0.0003;
    m_x += (cos(m_direction) * m_speed) * interval;
    m_y += (sin(m_direction) * m_speed) * interval;
    
    if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1 ) {
        init();
    }
//    if (rand()< RAND_MAX/100) {
//        init();
//    }
}
}
