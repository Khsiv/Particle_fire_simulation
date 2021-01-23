//
//  Particle.cpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 22.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//

#include "Particle.hpp"
#include <stdlib.h>
namespace scrspace {
Particle::Particle() {
    m_x = (2.0 * rand()/RAND_MAX) - 1;
    m_y = (2.0 * rand()/RAND_MAX) - 1;
}
Particle::~Particle() {
    
}
}
