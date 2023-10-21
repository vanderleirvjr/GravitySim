#include "Physics.h"
#include <cmath>
#include <iostream>

Physics::Physics(ObjectManager& inputManager) {
    manager = inputManager;
}


Physics::~Physics() {

}


Force Physics::gravityForce(Object& obj) {
    
    const double G = 6.67430e-11;  // Gravitational constant
    
    Force force;

    force.x = 0;
    force.y = 0;
    force.z = 0;

    Particle particle1 = obj.getParticle();
    
    double m1 = particle1.mass;

    size_t num_particles = manager.getObjectCount();

    for (size_t i = 0; i < num_particles; ++i) {
        Object fobj = manager.getObjectAt(i);
        Particle particle2 = fobj.getParticle();
        
        if (particle1 == particle2) continue;  // Skip self

        Position diff = particle2.position - particle1.position;

        double m2 = particle2.mass;

        double dx = diff.x;
        double dy = diff.y;
        double dz = diff.z;

        double r = std::sqrt(dx * dx + dy * dy + dz * dz);

        double F = G * m1 * m2 / (r * r);

        force.x += F * dx / r;
        force.y += F * dy / r;
        force.z += F * dz / r;

    }

    return force;

}


ObjectManager Physics::applyForces() {

    double timeStep = 3600;

    size_t num_particles = manager.getObjectCount();
    
    for (size_t i = 0; i < num_particles; ++i) {

        Force totalForce;

        Object obj = manager.getObjectAt(i);
        double mass = obj.getMass();
        Velocity vel = obj.getVelocity();
        Velocity newVel;
        Position pos = obj.getPosition();
        Position newPos;

        Force gforce = gravityForce(obj);

        totalForce += gforce;

        newVel = vel + (totalForce/mass) * timeStep;
        newPos = pos + vel * timeStep;

        obj.setPosition(newPos);
        obj.setVelocity(newVel);

        manager.updateObjectAt(i, obj);

    }

    return manager;
    
}