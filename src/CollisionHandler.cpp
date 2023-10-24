#include "CollisionHandler.h"
#include "Position.h"
#include <cmath>
#include <iostream>


ObjectManager CollisionHandler::processObjects(ObjectManager& manager) {
    double restitution = 0.1;
    double moveFactor = 1.01;  // Factor to move particles apart, can be adjusted

    int start = 0;

    size_t num_particles = manager.getObjectCount();

    for (size_t idx = 0; idx < num_particles; ++idx) {
        for (size_t jdx = 0; jdx < num_particles; ++jdx) {


            if (idx != jdx) {
            
                Object& obj1 = manager.getObjectAt(idx);
                Object& obj2 = manager.getObjectAt(jdx);

                Particle particle1 = obj1.getParticle();  
                Particle particle2 = obj2.getParticle();

                bool isCollision = collisionDetection(particle1, particle2);

                if (isCollision) {
                    double dist = distance(particle1,particle2);

                    if (dist < 1e-10) {
                        continue;
                    }

                    double vx, vy, vz;

                    Position normal = (particle1.position - particle2.position)/dist;

                    Velocity rv = particle1.velocity - particle2.velocity;

                    double vel_along_normal = rv.x * normal.x + rv.y * normal.y + rv.z * normal.z;

                    if (vel_along_normal > 0) { // Do not resolve if velocities are separating
                        continue;
                    }

                    // Compute impulse
                    double j = -(1 + restitution) * vel_along_normal;
                    j /= 1/particle1.mass + 1/particle2.mass;

                    double jx = j * normal.x;
                    double jy = j * normal.y;
                    double jz = j * normal.z;

                    vx = particle1.position.x + jx / particle1.mass;  
                    vy = particle1.position.y + jy / particle1.mass;  
                    vz = particle1.position.z + jz / particle1.mass;

                    Velocity newVelocity1;
                    newVelocity1.setComponents(vx,vy,vz);

                    vx = particle2.position.x + jx / particle2.mass;  
                    vy = particle2.position.y + jy / particle2.mass;  
                    vz = particle2.position.z + jz / particle2.mass;

                    Velocity newVelocity2;
                    newVelocity2.setComponents(vx,vy,vz);

                    Position adjust;
                    
                    adjust.x = normal.x * dist * (moveFactor - 1.0);
                    adjust.y = normal.y * dist * (moveFactor - 1.0);
                    adjust.z = normal.z * dist * (moveFactor - 1.0);

                    particle1.position = particle1.position + adjust;
                    particle2.position = particle2.position - adjust;

                    // Update positions back into the objects
                    obj1.setPosition(particle1.position);
                    obj2.setPosition(particle2.position);

                    obj1.setVelocity(newVelocity1);
                    obj2.setVelocity(newVelocity2);
            
                    manager.updateObjectAt(idx, obj1);
                    manager.updateObjectAt(jdx, obj2);

                }
            }
        }
        ++start;
    }

    return manager;
}

double CollisionHandler::distance(const Particle& particle1, const Particle& particle2) {
    Position pos1 = particle1.position;
    Position pos2 = particle2.position;

    Position diff = pos1 - pos2;

    double distance = std::sqrt((diff*diff).sumComponents()); 

    return distance;
}

bool CollisionHandler::collisionDetection(const Particle& particle1, const Particle& particle2) {
    
    double radius1 = particle1.radius;
    double radius2 = particle2.radius;

    double dist = distance(particle1,particle2);

    return dist <= (radius1 + radius2);
}