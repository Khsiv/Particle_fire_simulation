//
//  Particle.hpp
//  SDL_simple_fire
//
//  Created by Med Coolday on 22.01.2021.
//  Copyright © 2021 Med Coolday. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

namespace scrspace {

class Particle {
public:
    double m_x;
    double m_y;
public:
    Particle();
    virtual ~Particle();
    const double &getX() const {return m_x;}
    const double &getY() const {return m_y;}
};

}

#endif /* Particle_hpp */
