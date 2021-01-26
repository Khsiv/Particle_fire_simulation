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
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.0008 * rand())/RAND_MAX;
}
Particle::~Particle() {
    
}
void Particle::update(int interval) {
    m_x += (cos(m_direction) * m_speed) * interval;
    m_y += (sin(m_direction) * m_speed) * interval;
}
}
