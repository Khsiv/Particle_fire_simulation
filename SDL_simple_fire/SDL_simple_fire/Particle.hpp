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
#include <math.h>
namespace scrspace {

class Particle {
public:
    mutable double m_x;
    mutable double m_y;
    double m_speed;
    double m_direction;
public:
    Particle();
    virtual ~Particle();
    void init();
    const double &getX() const {return m_x;}
    const double &getY() const {return m_y;}
    const void setX(const double &x) const {m_x = x;}
    const void setY(const double &y) const {m_y = y;}
    void update(int interval);
};

}

#endif /* Particle_hpp */
