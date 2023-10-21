#pragma once 

#include <string>
#include "Position.h"
#include "Velocity.h"

struct Particle {
    std::string name; 
    Position position;
    Velocity velocity;
    double radius;
    double mass;

    bool operator==(const Particle& other) const {
        return position == other.position &&
               velocity == other.velocity &&
               radius == other.radius &&
               mass == other.mass;
    }
};
