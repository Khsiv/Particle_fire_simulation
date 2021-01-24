//
//  Swarm.hpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 22.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>
#include "Particle.hpp"
namespace scrspace {
    
class Swarm {
public:
    const static int NPARTICLES = 1500;
private:
    Particle  * m_pParticles;
public:
    Swarm();
    virtual ~Swarm();
    void update();
    const Particle * const getParticles() {return m_pParticles;}
};

}


#endif /* Swarm_hpp */
