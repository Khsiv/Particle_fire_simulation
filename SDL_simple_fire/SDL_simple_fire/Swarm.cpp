//
//  Swarm.cpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 22.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//

#include "Swarm.hpp"
#include <iostream>
namespace scrspace {
Swarm::Swarm() : lastTime(0) {
    m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update(int elapsed) {
    
    int interval = elapsed - lastTime;
    
    for (int i(0); i < Swarm::NPARTICLES; ++i) {
        m_pParticles[i].update(interval);
    }
    lastTime = elapsed;
}

}
