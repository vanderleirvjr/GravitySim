#pragma once 

#include <string>
#include "Position.h"
#include "Velocity.h"
#include "Constants.h"

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

    void setComponents(std::string newName, double newX, double newY, double newZ, 
                       double newVx, double newVy, double newVz, 
                       double newRadius, double newMass) {
        name = newName;
        position.setComponents(newX,newY,newZ);
        velocity.setComponents(newVx,newVy,newVz);
        radius = newRadius;
        mass = newMass;
    }

};
