#pragma once

#include "ObjectManager.h"  // Assuming Object is the class that holds information about each object
#include "Particle.h"


class CollisionHandler {

public:
    ObjectManager processObjects(ObjectManager& manager);

private:
    bool collisionDetection(const Particle& particle1, const Particle& particle2);
    double distance(const Particle& particle1, const Particle& particle2);
};
